#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

void print_left_right(int *array, int size, int first, int mid)
{
    int k;

    printf("Merging...\n");
    printf("[left]: ");
    k = first;
    while (k < mid)
    {
        if (k != mid - 1)
            printf("%d, ", array[k]);
        else
            printf("%d\n", array[k]);
        k++;
    }

    printf("[right]: ");
    k = mid;
    while (k < size)
    {
        if (k < size - 1)
            printf("%d, ", array[k]);
        else
            printf("%d\n", array[k]);
        k++;
    }
}

void merge(int *array, int size, int *cpy, int first, int mid)
{
    int i, j, k;

    print_left_right(array, size, first, mid);

    i = first;
    j = mid;

    printf("[Done]: ");
    k = first;
    while (k < size)
    {
        if (i < mid && (j >= size || array[i] <= array[j]))
        {
            cpy[k] = array[i];
            i++;
        }
        else
        {
            cpy[k] = array[j];
            j++;
        }
        if (k < size - 1)
            printf("%d, ", cpy[k]);
        else
            printf("%d\n", cpy[k]);
        k++;
    }
}

void mergeSort(int *cpy, int first, int size, int *array)
{
    int mid;

    if (size - first < 2)
        return;

    mid = (size + first) / 2;

    mergeSort(cpy, first, mid, array);
    mergeSort(cpy, mid, size, array);

    merge(array, size, cpy, first, mid);
}

void copy_array(int *arr, int *cpy, int size)
{
    int i;

    for (i = 0; i < (int)size; i++)
        cpy[i] = arr[i];
}

void merge_sort(int *array, size_t size)
{
    int *cpy;

    cpy = malloc(sizeof(int) * size);

    if (cpy == NULL)
        return;

    copy_array(array, cpy, size);

    mergeSort(cpy, 0, size, array);
    free(cpy);
}
