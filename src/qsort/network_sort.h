
#ifndef swap

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

#endif

#define SWAP_IF_GREATER(i, j, cmp) \
if ((cmp)(i, j)) { \
    swap(i, j);\
}


#define network_sort2(a, n, es, cmp)\
{\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 1 * (es), (cmp));\
}

#define network_sort3(a, n, es, cmp)\
{\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 1 * (es), (cmp));\
}

#define network_sort4(a, n, es, cmp)\
{\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 1 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 2 * (es), (cmp));\
}

#define network_sort5(a, n, es, cmp)\
{\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 1 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 2 * (es), (cmp));\
}

#define network_sort6(a, n, es, cmp)\
{\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 1 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 3 * (es), (cmp));\
}

#define network_sort7(a, n, es, cmp)\
{\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 1 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 3 * (es), (cmp));\
}

#define network_sort8(a, n, es, cmp)\
{\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 1 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 4 * (es), (cmp));\
}

#define network_sort9(a, n, es, cmp)\
{\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 1 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 1 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 6 * (es), (cmp));\
}

#define network_sort10(a, n, es, cmp)\
{\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 1 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 5 * (es), (cmp));\
}

#define network_sort11(a, n, es, cmp)\
{\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 1 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 8 * (es), (cmp));\
}

#define network_sort12(a, n, es, cmp)\
{\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 1 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 8 * (es), (cmp));\
}

#define network_sort13(a, n, es, cmp)\
{\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 1 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 6 * (es), (cmp));\
}

#define network_sort14(a, n, es, cmp)\
{\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 1 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 9 * (es), (cmp));\
}

#define network_sort15(a, n, es, cmp)\
{\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 1 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 9 * (es), (cmp));\
}

#define network_sort16(a, n, es, cmp)\
{\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 1 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 9 * (es), (cmp));\
}

#define network_sort17(a, n, es, cmp)\
{\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 1 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 8 * (es), (cmp));\
}

#define network_sort18(a, n, es, cmp)\
{\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 1 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 8 * (es), (cmp));\
}

#define network_sort19(a, n, es, cmp)\
{\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 1 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 15 * (es), (cmp));\
}

#define network_sort20(a, n, es, cmp)\
{\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 1 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 18 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 16 * (es), (cmp));\
}

#define network_sort21(a, n, es, cmp)\
{\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 18 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 1 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 19 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 18 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 14 * (es), (cmp));\
}

#define network_sort22(a, n, es, cmp)\
{\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 21 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 18 * (es), (char*)(a) + 21 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 21 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 19 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 19 * (es), (char*)(a) + 21 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 1 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 20 * (es), (char*)(a) + 21 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 18 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 19 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 18 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 16 * (es), (cmp));\
}

#define network_sort23(a, n, es, cmp)\
{\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 21 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 21 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 21 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 18 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 21 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 1 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 18 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 19 * (es), (char*)(a) + 21 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 20 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 19 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 21 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 18 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 20 * (es), (char*)(a) + 21 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 19 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 18 * (es), (cmp));\
}

#define network_sort24(a, n, es, cmp)\
{\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 21 * (es), (char*)(a) + 23 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 21 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 20 * (es), (char*)(a) + 23 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 21 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 19 * (es), (char*)(a) + 23 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 21 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 18 * (es), (char*)(a) + 23 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 21 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 18 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 1 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 18 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 22 * (es), (char*)(a) + 23 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 19 * (es), (char*)(a) + 21 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 20 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 19 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 21 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 18 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 20 * (es), (char*)(a) + 21 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 19 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 18 * (es), (cmp));\
}

#define network_sort25(a, n, es, cmp)\
{\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 18 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 24 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 24 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 20 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 24 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 22 * (es), (char*)(a) + 24 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 20 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 18 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 18 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 21 * (es), (char*)(a) + 23 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 19 * (es), (char*)(a) + 23 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 21 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 19 * (es), (char*)(a) + 21 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 21 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 21 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 23 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 23 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 21 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 1 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 18 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 20 * (es), (char*)(a) + 21 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 22 * (es), (char*)(a) + 23 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 24 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 24 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 19 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 21 * (es), (char*)(a) + 24 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 19 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 21 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 23 * (es), (char*)(a) + 24 * (es), (cmp));\
}

#define network_sort26(a, n, es, cmp)\
{\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 18 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 24 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 24 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 20 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 24 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 22 * (es), (char*)(a) + 24 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 20 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 18 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 18 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 19 * (es), (char*)(a) + 23 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 25 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 23 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 25 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 21 * (es), (char*)(a) + 23 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 25 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 23 * (es), (char*)(a) + 25 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 21 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 21 * (es), (char*)(a) + 23 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 19 * (es), (char*)(a) + 23 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 21 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 19 * (es), (char*)(a) + 21 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 1 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 18 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 20 * (es), (char*)(a) + 21 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 22 * (es), (char*)(a) + 23 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 24 * (es), (char*)(a) + 25 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 24 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 24 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 19 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 21 * (es), (char*)(a) + 24 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 19 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 21 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 23 * (es), (char*)(a) + 24 * (es), (cmp));\
}

#define network_sort27(a, n, es, cmp)\
{\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 20 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 24 * (es), (char*)(a) + 26 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 18 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 24 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 18 * (es), (char*)(a) + 26 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 24 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 26 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 24 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 26 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 18 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 22 * (es), (char*)(a) + 26 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 24 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 20 * (es), (char*)(a) + 24 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 18 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 22 * (es), (char*)(a) + 24 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 19 * (es), (char*)(a) + 23 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 25 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 23 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 25 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 21 * (es), (char*)(a) + 23 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 25 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 23 * (es), (char*)(a) + 25 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 21 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 21 * (es), (char*)(a) + 23 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 19 * (es), (char*)(a) + 23 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 21 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 19 * (es), (char*)(a) + 21 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 1 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 18 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 20 * (es), (char*)(a) + 21 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 22 * (es), (char*)(a) + 23 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 24 * (es), (char*)(a) + 25 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 24 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 26 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 24 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 19 * (es), (char*)(a) + 26 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 19 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 21 * (es), (char*)(a) + 24 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 23 * (es), (char*)(a) + 26 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 19 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 21 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 23 * (es), (char*)(a) + 24 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 25 * (es), (char*)(a) + 26 * (es), (cmp));\
}

#define network_sort28(a, n, es, cmp)\
{\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 21 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 24 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 25 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 26 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 23 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 18 * (es), (char*)(a) + 27 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 27 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 19 * (es), (char*)(a) + 23 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 20 * (es), (char*)(a) + 26 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 21 * (es), (char*)(a) + 25 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 22 * (es), (char*)(a) + 24 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 21 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 23 * (es), (char*)(a) + 24 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 25 * (es), (char*)(a) + 26 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 26 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 19 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 20 * (es), (char*)(a) + 21 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 24 * (es), (char*)(a) + 27 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 0 * (es), (char*)(a) + 1 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 24 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 19 * (es), (char*)(a) + 23 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 20 * (es), (char*)(a) + 25 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 26 * (es), (char*)(a) + 27 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 21 * (es), (char*)(a) + 25 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 22 * (es), (char*)(a) + 23 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 24 * (es), (char*)(a) + 26 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 19 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 23 * (es), (char*)(a) + 25 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 23 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 18 * (es), (char*)(a) + 25 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 21 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 1 * (es), (char*)(a) + 2 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 24 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 21 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 18 * (es), (char*)(a) + 23 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 25 * (es), (char*)(a) + 26 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 21 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 19 * (es), (char*)(a) + 25 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 20 * (es), (char*)(a) + 23 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 22 * (es), (char*)(a) + 24 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 2 * (es), (char*)(a) + 3 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 18 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 19 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 24 * (es), (char*)(a) + 25 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 19 * (es), (char*)(a) + 21 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 13 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 14 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 21 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 4 * (es), (char*)(a) + 5 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 6 * (es), (char*)(a) + 7 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 8 * (es), (char*)(a) + 9 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 10 * (es), (char*)(a) + 11 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 12 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 15 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 16 * (es), (char*)(a) + 17 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 18 * (es), (char*)(a) + 19 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 20 * (es), (char*)(a) + 21 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 22 * (es), (char*)(a) + 23 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 3 * (es), (char*)(a) + 4 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 5 * (es), (char*)(a) + 6 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 7 * (es), (char*)(a) + 8 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 9 * (es), (char*)(a) + 10 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 11 * (es), (char*)(a) + 12 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 13 * (es), (char*)(a) + 14 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 15 * (es), (char*)(a) + 16 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 17 * (es), (char*)(a) + 18 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 19 * (es), (char*)(a) + 20 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 21 * (es), (char*)(a) + 22 * (es), (cmp));\
	SWAP_IF_GREATER((char*)(a) + 23 * (es), (char*)(a) + 24 * (es), (cmp));\
}

#define network_sort(a, n, es, cmp)\
{\
	switch(n)\
	{\
		case 2:\
			network_sort2((a), (n), (es), (cmp));\
			break;\
		case 3:\
			network_sort3((a), (n), (es), (cmp));\
			break;\
		case 4:\
			network_sort4((a), (n), (es), (cmp));\
			break;\
		case 5:\
			network_sort5((a), (n), (es), (cmp));\
			break;\
		case 6:\
			network_sort6((a), (n), (es), (cmp));\
			break;\
		case 7:\
			network_sort7((a), (n), (es), (cmp));\
			break;\
		case 8:\
			network_sort8((a), (n), (es), (cmp));\
			break;\
		case 9:\
			network_sort9((a), (n), (es), (cmp));\
			break;\
		case 10:\
			network_sort10((a), (n), (es), (cmp));\
			break;\
		case 11:\
			network_sort11((a), (n), (es), (cmp));\
			break;\
		case 12:\
			network_sort12((a), (n), (es), (cmp));\
			break;\
		case 13:\
			network_sort13((a), (n), (es), (cmp));\
			break;\
		case 14:\
			network_sort14((a), (n), (es), (cmp));\
			break;\
		case 15:\
			network_sort15((a), (n), (es), (cmp));\
			break;\
		case 16:\
			network_sort16((a), (n), (es), (cmp));\
			break;\
		case 17:\
			network_sort17((a), (n), (es), (cmp));\
			break;\
		case 18:\
			network_sort18((a), (n), (es), (cmp));\
			break;\
		case 19:\
			network_sort19((a), (n), (es), (cmp));\
			break;\
		case 20:\
			network_sort20((a), (n), (es), (cmp));\
			break;\
		case 21:\
			network_sort21((a), (n), (es), (cmp));\
			break;\
		case 22:\
			network_sort22((a), (n), (es), (cmp));\
			break;\
		case 23:\
			network_sort23((a), (n), (es), (cmp));\
			break;\
		case 24:\
			network_sort24((a), (n), (es), (cmp));\
			break;\
		case 25:\
			network_sort25((a), (n), (es), (cmp));\
			break;\
		case 26:\
			network_sort26((a), (n), (es), (cmp));\
			break;\
		case 27:\
			network_sort27((a), (n), (es), (cmp));\
			break;\
		case 28:\
			network_sort28((a), (n), (es), (cmp));\
			break;\
	}\
}
