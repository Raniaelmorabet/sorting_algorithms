#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merges two subarrays of the array
 * @array: Pointer to the array
 * @left: Pointer to the left subarray
 * @left_size: Size of the left subarray
 * @right: Pointer to the right subarray
 * @right_size: Size of the right subarray
 **/
void merge(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
    size_t i = 0, j = 0, k = 0;
    size_t size = left_size + right_size;
    int *temp = malloc(size * sizeof(int));

    printf("Merging...\n[left]: ");
    print_array(left, left_size);
    printf("[right]: ");
    print_array(right, right_size);

    printf("[Done]: ");
    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
            temp[k++] = left[i++];
        else
            temp[k++] = right[j++];
    }

    while (i < left_size)
        temp[k++] = left[i++];
    while (j < right_size)
        temp[k++] = right[j++];

    for (i = 0; i < size; i++)
        array[i] = temp[i];
    free(temp);
    print_array(array, size);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge sort
 * @array: Pointer to the array
 * @size: Size of the array
 **/
void merge_sort(int *array, size_t size)
{
    if (size < 2)
        return;

    size_t mid = size / 2;
    size_t i;
    int *left = malloc(mid * sizeof(int));
    int *right = malloc((size - mid) * sizeof(int));

    for (i = 0; i < mid; i++)
        left[i] = array[i];
    for (i = mid; i < size; i++)
        right[i - mid] = array[i];

    merge_sort(left, mid);
    merge_sort(right, size - mid);
    merge(array, left, mid, right, size - mid);

    free(left);
    free(right);
}
