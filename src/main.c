#include "qsort/qsort.c"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef void (*Sorter)(int *a, int size);

int less(const void* first, const void* second)
{
    return *((const int*) first) - *((const int*) second);
}

void postgre_qsort(int* a, int n)
{
    pg_qsort((void*)a, n, sizeof(int), less);
}

void std_qsort(int* a, int n)
{
    qsort((void*)a, n, sizeof(int), less);
}

long long llrand()
{
    return rand() * ((long long )RAND_MAX + 1) + rand();
}

int* generate_random(int size, int max_value)
{
    int* arr = (int*) malloc(size * sizeof(int));
    int i;
    for (i = 0; i < size; ++i)
    {
        arr[i] = llrand() % max_value;
    }
    return arr;
}

double test_sort(Sorter sort, int size, int max_value, int iters)
{
    double sum_seconds = 0;
    int iter;
    for (iter = 0; iter < iters; ++iter)
    {
        int* arr = generate_random(size, max_value);
        clock_t start = clock();
        sort(arr, size);
        clock_t finish = clock();
        sum_seconds += finish - start;
        free((void*)arr);
    }
    return sum_seconds / iters / CLOCKS_PER_SEC;
}

int main(int argc, char** argv)
{
    srand(1);
    int i = 0;
    Sorter sorters[] = {postgre_qsort, std_qsort};
    for (i = 0; i < 1; ++i)
    {
        double res_time = test_sort(sorters[i], 1e6, 1e9, 20);
        printf("Average time is %f seconds\n", res_time);
    }
    return 0;
}
