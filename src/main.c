#include "qsort/qsort_old.c"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef void (*Sorter)(void *a, int size);

int less(const void* first, const void* second)
{
    return *((const int*) first) - *((const int*) second);
}

long less_long(const void* first, const void* second)
{
    return *((const long*) first) - *((const long*) second);
}

void postgre_qsort(void* a, int n)
{
    pg_qsort(a, n, sizeof(int), less);
}

void postgre_qsort_new(void* a, int n)
{
    pg_qsort_new(a, n, sizeof(int), less);
}

void std_qsort(void* a, int n)
{
    qsort(a, n, sizeof(int), less);
}

void postgre_qsort_long(void* a, int n)
{
    pg_qsort(a, n, sizeof(long), less);
}

void postgre_qsort_new_long(void* a, int n)
{
    pg_qsort_new(a, n, sizeof(long), less);
}

void std_qsort_long(void* a, int n)
{
    qsort(a, n, sizeof(long), less);
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

long* generate_random_long(int size, long max_value)
{
    long* arr = (long*) malloc(size * sizeof(long));
    int i;
    for (i = 0; i < size; ++i)
    {
        arr[i] = llrand() % max_value;
    }
    return arr;
}

void* generate_random_any(int size, long max_value, int size_of_type)
{
    if (size_of_type == sizeof(int))
    {
        return generate_random(size, max_value);
    }
    else if (size_of_type == sizeof(long))
    {
        return generate_random_long(size, max_value);
    }
    else
    {
        printf("Incorrect size of type %d\n", size_of_type);
        return NULL;
    }
}

double test_small_size(Sorter sort, int size, long max_value, int iters, int size_of_type)
{
    void** arrays = (void **) malloc(iters * size_of_type);
    int i;
    for (i = 0; i < iters; ++i)
    {
        arrays[i] = generate_random_any(size, max_value, size_of_type);
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

double test_sort(Sorter sort, int size, int max_value, int iters, int size_of_type)
{
    double sum_clocks = 0;
    int iter;
    for (iter = 0; iter < iters; ++iter)
    {
        void* arr = generate_random_any(size, max_value, size_of_type);
        clock_t start = clock();
        sort(arr, size);
        clock_t finish = clock();
        sum_clocks += finish - start;
        free(arr);
    }
    return sum_clocks / iters / CLOCKS_PER_SEC;
}

int sorts_correct_for_size(Sorter sorter, int size, int size_of_type)
{
    int i;
    if (size_of_type == sizeof(int))
    {
        int* arr = generate_random_any(size, 1e9, size_of_type);
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
    else if (size_of_type == sizeof(long))
    {
        long* arr2 = generate_random_any(size, 1e9, size_of_type);
        sorter(arr2, size);
        for (i = 0; i < size - 1; ++i)
            if (arr2[i] > arr2[i + 1])
            {
                free(arr2);
                return 0;
            }
        free(arr2);
        return 1;
    }
}

int sorter_is_correct(Sorter sorter, int size_of_type)
{
    int size, times;
    for (size = 1; size < 10; ++size)
    {
        for (times = 0; times < 10; ++times)
        {
            if (!sorts_correct_for_size(sorter, size, size_of_type))
            {
                printf("Size of array is %d\n", size);
                return 0;
            }
        }
    }
    if (!sorts_correct_for_size(sorter, 100, size_of_type))
    {
        return 0;
    }
    if (!sorts_correct_for_size(sorter, 1000, size_of_type))
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

void test(Sorter sorter, char* name, int elements, int iters, int size_of_type)
{
    double res_time;
    if (!sorter_is_correct(sorter, size_of_type))
    {
        printf("Sorter %s is incorrect\n", name);
        return;
    }
    if (elements > 200)
    {
        res_time = test_sort(sorter, elements, 1e9, iters, size_of_type);
    }
    else
    {
        res_time = test_small_size(sorter, elements, 1e9, iters, size_of_type);
    }
    printf("Average time for %s for size %d is %f seconds\n", name, (int)elements, res_time);
}

int main(int argc, char** argv)
{
    srand(1);
    int i = 0;
    int j = 0;
    Sorter sorters[] = {std_qsort, postgre_qsort, postgre_qsort_new};
    Sorter long_sorters[] = {std_qsort_long, postgre_qsort_long, postgre_qsort_new_long};
    char* names[] = {"std", "postgre", "postgre_new"};
    for (i = 0; i < 3; ++i)
    {
        test(long_sorters[i], names[i], 50, 3e5, sizeof(long));
    }
    printf("\n");
    return 0;
}
