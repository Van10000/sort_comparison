/*
 *	qsort.c: standard quicksort algorithm
 *
 *	Modifications from vanilla NetBSD source:
 *	  Add do ... while() macro fix
 *	  Remove __inline, _DIAGASSERTs, __P
 *	  Remove ill-considered "swap_cnt" switch to insertion sort,
 *	  in favor of a simple check for presorted input.
 *	  Take care to recurse on the smaller partition, to bound stack usage.
 *
 *	CAUTION: if you change this file, see also qsort_arg.c, gen_qsort_tuple.pl
 *
 *	src/port/qsort.c
 */

/*	$NetBSD: qsort.c,v 1.13 2003/08/07 16:43:42 agc Exp $	*/

/*-
 * Copyright (c) 1992, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *	  notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *	  notice, this list of conditions and the following disclaimer in the
 *	  documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *	  may be used to endorse or promote products derived from this software
 *	  without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */
#include <stdio.h>
#define Min(X, Y) (((X) < (Y)) ? (X) : (Y))

static char *med3(char *a, char *b, char *c,
	 int (*cmp) (const void *, const void *));
static void swapfunc(char *, char *, size_t, int);

/*
 * Qsort routine based on J. L. Bentley and M. D. McIlroy,
 * "Engineering a sort function",
 * Software--Practice and Experience 23 (1993) 1249-1265.
 *
 * We have modified their original by adding a check for already-sorted input,
 * which seems to be a win per discussions on pgsql-hackers around 2006-03-21.
 *
 * Also, we recurse on the smaller partition and iterate on the larger one,
 * which ensures we cannot recurse more than log(N) levels (since the
 * partition recursed to is surely no more than half of the input).  Bentley
 * and McIlroy explicitly rejected doing this on the grounds that it's "not
 * worth the effort", but we have seen crashes in the field due to stack
 * overrun, so that judgment seems wrong.
 */

#define swapcode(TYPE, parmi, parmj, n) \
do {		\
	size_t i = (n) / sizeof (TYPE);			\
	TYPE *pi = (TYPE *)(void *)(parmi);			\
	TYPE *pj = (TYPE *)(void *)(parmj);			\
	do {						\
		TYPE	t = *pi;			\
		*pi++ = *pj;				\
		*pj++ = t;				\
		} while (--i > 0);				\
} while (0)

#define SWAPINIT(a, es) swaptype = ((char *)(a) - (char *)0) % sizeof(long) || \
	(es) % sizeof(long) ? 2 : (es) == sizeof(long)? 0 : 1;

static void
swapfunc(char *a, char *b, size_t n, int swaptype)
{
	if (swaptype <= 1)
		swapcode(long, a, b, n);
	else
		swapcode(char, a, b, n);
}

#define swap(a, b)						\
	if (swaptype == 0) {					\
		long t = *(long *)(void *)(a);			\
		*(long *)(void *)(a) = *(long *)(void *)(b);	\
		*(long *)(void *)(b) = t;			\
	} else							\
		swapfunc(a, b, es, swaptype)

#define vecswap(a, b, n) if ((n) > 0) swapfunc(a, b, n, swaptype)

static char *
med3(char *a, char *b, char *c, int (*cmp) (const void *, const void *))
{
	return cmp(a, b) < 0 ?
		(cmp(b, c) < 0 ? b : (cmp(a, c) < 0 ? c : a))
		: (cmp(b, c) > 0 ? b : (cmp(a, c) < 0 ? a : c));
}

static char *
med5(char *a, char *b, char *c, char *d, char *e, int (*cmp) (const void *, const void *))
{
    return (cmp(a,b) > 0) ? (cmp(c,d) > 0) ? (cmp(d,b) > 0) ? (cmp(e,a) > 0) ? (cmp(d,a) > 0) ? (cmp(d,e) > 0) ? e : d
                                                                                              : (cmp(a,c) > 0) ? c : a
                                                                             : (cmp(d,e) > 0) ? (cmp(d,a) > 0) ? a : d
                                                                                              : (cmp(e,c) > 0) ? c : e
                                                            : (cmp(e,c) > 0) ? (cmp(c,b) > 0) ? (cmp(c,a) > 0) ? a : c
                                                                                              : (cmp(b,e) > 0) ? e : b
                                                                             : (cmp(e,b) > 0) ? (cmp(e,a) > 0) ? a : e
                                                                                              : (cmp(b,c) > 0) ? c : b
                                           : (cmp(c,b) > 0) ? (cmp(e,a) > 0) ? (cmp(c,a) > 0) ? (cmp(c,e) > 0) ? e : c
                                                                                              : (cmp(a,d) > 0) ? d : a
                                                                             : (cmp(c,e) > 0) ? (cmp(c,a) > 0) ? a : c
                                                                                              : (cmp(e,d) > 0) ? d : e
                                                            : (cmp(e,d) > 0) ? (cmp(d,b) > 0) ? (cmp(d,a) > 0) ? a : d
                                                                                              : (cmp(b,e) > 0) ? e : b
                                                                             : (cmp(e,b) > 0) ? (cmp(e,a) > 0) ? a : e
                                                                                              : (cmp(b,d) > 0) ? d : b
                          : (cmp(c,d) > 0) ? (cmp(d,a) > 0) ? (cmp(e,b) > 0) ? (cmp(d,b) > 0) ? (cmp(d,e) > 0) ? e : d
                                                                                              : (cmp(b,c) > 0) ? c : b
                                                                             : (cmp(d,e) > 0) ? (cmp(d,b) > 0) ? b : d
                                                                                              : (cmp(e,c) > 0) ? c : e
                                                            : (cmp(e,c) > 0) ? (cmp(c,a) > 0) ? (cmp(c,b) > 0) ? b : c
                                                                                              : (cmp(a,e) > 0) ? e : a
                                                                             : (cmp(e,a) > 0) ? (cmp(e,b) > 0) ? b : e
                                                                                              : (cmp(a,c) > 0) ? c : a
                                           : (cmp(c,a) > 0) ? (cmp(e,b) > 0) ? (cmp(c,b) > 0) ? (cmp(c,e) > 0) ? e : c
                                                                                              : (cmp(b,d) > 0) ? d : b
                                                                             : (cmp(c,e) > 0) ? (cmp(c,b) > 0) ? b : c
                                                                                              : (cmp(e,d) > 0) ? d : e
                                                            : (cmp(e,d) > 0) ? (cmp(d,a) > 0) ? (cmp(d,b) > 0) ? b : d
                                                                                              : (cmp(a,e) > 0) ? e : a
                                                                             : (cmp(e,a) > 0) ? (cmp(e,b) > 0) ? b : e
                                                                                              : (cmp(a,d) > 0) ? d : a;

}

/*
Один путь:
  Попробовать убрать все переменные в одну, которую передавать параметром функции.
Второй путь:
  Попробовать полностью избавиться от рекурсии так как это сделано в qsort-е.

После чего, возможно, пересмотреть константу на которой включать insertion sort.

И только после этого писать оптимальный unrolled insertion sort

*/

void
pg_qsort(void *a, size_t n, size_t es, int (*cmp) (const void *, const void *))
{
	char	   *pa,
			   *pb,
			   *pc,
			   *pd,
			   *pl,
			   *pm,
			   *pn;
	size_t		d1,
				d2;
	int			r,
				swaptype,
				presorted;

loop:SWAPINIT(a, es);
	if (n < 7)
	{
		for (pm = (char *) a + es; pm < (char *) a + n * es; pm += es)
			for (pl = pm; pl > (char *) a && cmp(pl - es, pl) > 0;
				 pl -= es)
				swap(pl, pl - es);
		return;
	}
	presorted = 1;
	for (pm = (char *) a + es; pm < (char *) a + n * es; pm += es)
	{
		if (cmp(pm - es, pm) > 0)
		{
			presorted = 0;
			break;
		}
	}
	if (presorted)
		return;
	pm = (char *) a + (n / 2) * es;
	if (n > 7)
	{
		pl = (char *) a;
		pn = (char *) a + (n - 1) * es;
		if (n > 40)
		{
			size_t		d = (n / 8) * es;

			pl = med3(pl, pl + d, pl + 2 * d, cmp);
			pm = med3(pm - d, pm, pm + d, cmp);
			pn = med3(pn - 2 * d, pn - d, pn, cmp);
		}
		pm = med3(pl, pm, pn, cmp);
	}
	swap(a, pm);
	pa = pb = (char *) a + es;
	pc = pd = (char *) a + (n - 1) * es;
	for (;;)
	{
		while (pb <= pc && (r = cmp(pb, a)) <= 0)
		{
			if (r == 0)
			{
				swap(pa, pb);
				pa += es;
			}
			pb += es;
		}
		while (pb <= pc && (r = cmp(pc, a)) >= 0)
		{
			if (r == 0)
			{
				swap(pc, pd);
				pd -= es;
			}
			pc -= es;
		}
		if (pb > pc)
			break;
		swap(pb, pc);
		pb += es;
		pc -= es;
	}
	pn = (char *) a + n * es;
	d1 = Min(pa - (char *) a, pb - pa);
	vecswap(a, pb - d1, d1);
	d1 = Min(pd - pc, pn - pd - es);
	vecswap(pb, pn - d1, d1);
	d1 = pb - pa;
	d2 = pd - pc;
	if (d1 <= d2)
	{
		/* Recurse on left partition, then iterate on right partition */
		if (d1 > es)
			pg_qsort(a, d1 / es, es, cmp);
		if (d2 > es)
		{
			/* Iterate rather than recurse to save stack space */
			/* pg_qsort(pn - d2, d2 / es, es, cmp); */
			a = pn - d2;
			n = d2 / es;
			goto loop;
		}
	}
	else
	{
		/* Recurse on right partition, then iterate on left partition */
		if (d2 > es)
			pg_qsort(pn - d2, d2 / es, es, cmp);
		if (d1 > es)
		{
			/* Iterate rather than recurse to save stack space */
			/* pg_qsort(a, d1 / es, es, cmp); */
			n = d1 / es;
			goto loop;
		}
	}
}

char	   *pa,
           *pb,
           *pc,
           *pd,
           *pl,
           *pm;
int			r,
            presorted;
int			swaptype;
size_t      d;

void unrolled_insertion_sort(void *a, size_t n, size_t es, int (*cmp) (const void *, const void *))
{
	switch (n)
    {
        case 0:
        case 1:
            return;
        case 2:
            pb = a + es;
            if (cmp(a, pb) > 0)
            {
                swap(a, pb);
            }
            return;
        case 3:
            pb = a + es;
            pc = a + 2 * es;
            if (cmp(pb, pc) > 0)
            {
                if (cmp(a, pb) > 0)
                {
                    swap(a, pc);
                }
                else
                {
                    swap(pb, pc);
                    if (cmp(a, pb) > 0)
                    {
                        swap(a, pb);
                    }
                }
            }
            else
            {
                if (cmp(a, pb) > 0)
                {
                    swap(a, pb);
                    if (cmp(pb, pc) > 0)
                    {
                        swap(pb, pc);
                    }
                }
            }
            return;
        /* Find smallest element and put it in the beginning of array, then do insertion sort */
        case 4:
        case 5:
        case 6:
            pa = a;
            for (pb = (char*) a + es; pb < (char *) a + n * es; pb += es)
                if (cmp(pa, pb) > 0)
                {
                    pa = pb;
                }
            if (pa != a)
            {
                swap(a, pa);
            }
            for (pb = (char *) a + 2 * es; pb < (char *) a + n * es; pb += es)
                for (pc = pb; pc > (char *) a && cmp(pc - es, pc) > 0;
                     pc -= es)
                    swap(pc, pc - es);
    }
}

void
pg_qsort_new_recursion(void *a, size_t n, size_t es, int (*cmp) (const void *, const void *))
{
char	   *pn;
size_t		d1,
            d2;

loop_new:
	if (n < 7)
	{
        unrolled_insertion_sort(a, n, es, cmp);
		return;
	}
	presorted = 1;
	for (pm = (char *) a + es; pm < (char *) a + n * es; pm += es)
	{
		if (cmp(pm - es, pm) > 0)
		{
			presorted = 0;
			break;
		}
	}
	if (presorted)
		return;
    pl = (char *) a;
    pm = (char *) a + (n / 2) * es;
    pn = (char *) a + (n - 1) * es;
    if (n <= 40)
    {
        pm = med3(pl, pm, pn, cmp);
    }
    else
    {
        /*if (n <= 200)
        {
            d = (n / 4) * es;
            pm = med5(pl, pl + d, pm, pm + d, pn, cmp);
        }
        else
        {
            d = (n / 8) * es;
            pm = med3(med3(pl, pl + d, pl + 2 * d, cmp),
                      med3(pm - d, pm, pm + d, cmp),
                      med3(pn - 2 * d, pn - d, pn, cmp),
                      cmp);
        }*/
        d = (n / 8) * es;
        pm = med3(med3(pl, pl + d, pl + 2 * d, cmp),
                  med3(pm - d, pm, pm + d, cmp),
                  med3(pn - 2 * d, pn - d, pn, cmp),
                  cmp);
    }
	swap(a, pm);
	pa = pb = (char *) a + es;
	pc = pd = (char *) a + (n - 1) * es;
	for (;;)
	{
		while (pb <= pc && (r = cmp(pb, a)) <= 0)
		{
			if (r == 0)
			{
				swap(pa, pb);
				pa += es;
			}
			pb += es;
		}
		while (pb <= pc && (r = cmp(pc, a)) >= 0)
		{
			if (r == 0)
			{
				swap(pc, pd);
				pd -= es;
			}
			pc -= es;
		}
		if (pb > pc)
			break;
		swap(pb, pc);
		pb += es;
		pc -= es;
	}
	pn = (char *) a + n * es;
	d1 = Min(pa - (char *) a, pb - pa);
	vecswap(a, pb - d1, d1);
	d1 = Min(pd - pc, pn - pd - es);
	vecswap(pb, pn - d1, d1);
	d1 = pb - pa;
	d2 = pd - pc;
	if (d1 <= d2)
	{
		/* Recurse on left partition, then iterate on right partition */
		if (d1 > es)
			pg_qsort_new_recursion(a, d1 / es, es, cmp);
		if (d2 > es)
		{
			/* Iterate rather than recurse to save stack space */
			/* pg_qsort(pn - d2, d2 / es, es, cmp); */
			a = pn - d2;
			n = d2 / es;
			goto loop_new;
		}
	}
	else
	{
		/* Recurse on right partition, then iterate on left partition */
		if (d2 > es)
			pg_qsort_new_recursion(pn - d2, d2 / es, es, cmp);
		if (d1 > es)
		{
			/* Iterate rather than recurse to save stack space */
			/* pg_qsort(a, d1 / es, es, cmp); */
			n = d1 / es;
			goto loop_new;
		}
	}
}

void
pg_qsort_new(void *a, size_t n, size_t es, int (*cmp) (const void *, const void *))
{
    SWAPINIT(a, es);
    pg_qsort_new_recursion(a, n, es, cmp);
}

/*
 * qsort comparator wrapper for strcmp.
 */
int
pg_qsort_strcmp(const void *a, const void *b)
{
	return strcmp(*(const char *const *) a, *(const char *const *) b);
}
