#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);


/* 0. Bubble sort */
void bubble_sort(int *array, size_t size);

/* 1. Insertion sort */
void insertion_sort_list(listint_t **list);

/* 2. Selection sort */
void selection_sort(int *array, size_t size);

/* 3.Quick sort */
void quicksort_recursive(int *array, int low, int high);
int partition(int *array, int low, int high);
void quicksort_recursive(int *array, int low, int high);
void quick_sort(int *array, size_t size);
#endif /* SORT_H */
