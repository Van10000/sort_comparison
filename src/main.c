#include "qsort/qsort_old.c"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef void (*Sorter)(int *a, int size);

int less(const void* first, const void* second)
{
    return *((const int*) first) - *((const int*) second);
}

void postgre_qsort(int* a, int n)
{
    pg_qsort((void*)a, n, sizeof(int), less);
}

void postgre_qsort_new(int* a, int n)
{
    pg_qsort_new((void*)a, n, sizeof(int), less);
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

double test_small_size(Sorter sort, int size, int max_value, int iters)
{
    int** arrays = (int **) malloc(iters * sizeof(int*));
    int i;
    for (i = 0; i < iters; ++i)
    {
        arrays[i] = generate_random(size, max_value);
    }
    clock_t start = clock();
    for (i = 0; i < iters; ++i)
    {
        sort(arrays[i], size);
    }
    clock_t finish = clock();
    for (i = 0; i < iters; ++i)
        free(arrays[i]);
    free(arrays);
    double sum_clocks = finish - start;
    return (sum_clocks) / CLOCKS_PER_SEC;
}

double test_sort(Sorter sort, int size, int max_value, int iters)
{
    double sum_clocks = 0;
    int iter;
    for (iter = 0; iter < iters; ++iter)
    {
        int* arr = generate_random(size, max_value);
        clock_t start = clock();
        sort(arr, size);
        clock_t finish = clock();
        sum_clocks += finish - start;
        free(arr);
    }
    return sum_clocks / iters / CLOCKS_PER_SEC;
}

int sorts_correct_for_size(Sorter sorter, int size)
{
    int* arr = generate_random(size, 1e9);
    int i;
    sorter(arr, size);
    for (i = 0; i < size - 1; ++i)
        if (arr[i] > arr[i + 1])
        {
            free(arr);
            return 0;
        }
    free(arr);
    return 1;
}

int sorter_is_correct(Sorter sorter)
{
    int size, times;
    for (size = 1; size < 10; ++size)
    {
        for (times = 0; times < 10; ++times)
        {
            if (!sorts_correct_for_size(sorter, size))
            {
                return 0;
            }
        }
    }
    if (!sorts_correct_for_size(sorter, 100))
    {
        return 0;
    }
    if (!sorts_correct_for_size(sorter, 1000))
    {
        return 0;
    }
    return 1;
}

int test_med5(int* arr)
{
    char* a = (char*)arr;
    int* med = (int*)med5(a, a + 4, a + 8, a + 12, a + 16, less);
    printf("med5(%d, %d, %d, %d, %d) = %d\n", arr[0], arr[1], arr[2], arr[3], arr[4], *med);
}

void test(Sorter sorter, char* name, int elements, int iters)
{
    double res_time;
    if (!sorter_is_correct(sorter))
    {
        printf("Sorter %s is incorrect\n", name);
        return;
    }
    if (elements > 200)
    {
        res_time = test_sort(sorter, elements, 1e9, iters);
    }
    else
    {
        res_time = test_small_size(sorter, elements, 1e9, iters);
    }
    printf("Average time for %s for size %d is %f seconds\n", name, (int)elements, res_time);
}

int main(int argc, char** argv)
{
    srand(1);
    int i = 0;
    int j = 0;
    Sorter sorters[] = {std_qsort, postgre_qsort, postgre_qsort_new};
    char* names[] = {"std", "postgre", "postgre_new"};
    for (i = 0; i < 3; ++i)
    {
        test(sorters[i], names[i], 4, 4e5);
    }
    printf("\n");
    return 0;
}
