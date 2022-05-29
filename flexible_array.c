#include <stdio.h>
#include <stdlib.h>

typedef struct Array {
	unsigned int capacity;
	int size;
	int *array;
} array_struct;

/**
 * create_array - Creates an array of specific size
 * @size: size of the array
 *
 * Return: array
 */

array_struct create_array (unsigned int arr_size)
{
	int *temp = (int *)malloc(sizeof(int) * arr_size);
	array_struct new_array;

	new_array.capacity = arr_size;
	new_array.size = -1;
	new_array.array = temp;

	return (new_array);
}

/**
 * get_array_size - gets the size of an array
 * and print to stdout
 * @array: array to get size of
 *
 */

void get_array_size (array_struct array)
{
	printf("Size of the array is: %d\n Capacity of array is: %d\n",
	       array.size, array.capacity);
}

/**
 * resize_and_add - It adds an item to an array.
 * @arr: array to add to
 * @item: item to add to the array
 *
 * Description: It checks if an array is full. If it is not, the item is added
 * to the array. And if it is, the array size is increased and the item
 * is then added to the array.
 *
 */
void resize_and_add (array_struct *arr, int item)
{
	int *temp, i = arr->capacity + 5;

	//arr->capacity += 5;
	temp = (int *)realloc(arr->array, sizeof(int) * i);

	if (temp == NULL)
		exit(EXIT_FAILURE);

	arr->array = temp;
    arr->array[arr->size + 1] = item;
	arr->size += 1;
	arr->capacity = i;
	//free(temp);
	printf("Array capacity increased and item: %d added!\n", item);
}


void add_to_array (array_struct *arr, int item)
{
	if (arr->size == -1 || arr->size < arr->capacity - 1)
	{
		arr->array[arr->size + 1] = item;
		arr->size++;
		printf("%d added to the array successfully.\n", item);
	}
	else
	{
		resize_and_add(arr, item);
	}
}


/**
 * main - flexible array that allows array size to increase when full
 *
 * Return: always 0
 */

int main (void)
{
	array_struct my_array = create_array(4);
	add_to_array(&my_array, 6);
	add_to_array(&my_array, 5);
	add_to_array(&my_array, 6);
	add_to_array(&my_array, 7);
	add_to_array(&my_array, 2);
	add_to_array(&my_array, 9);
	add_to_array(&my_array, 8);
	add_to_array(&my_array, 4);
	add_to_array(&my_array, 76);
	add_to_array(&my_array, 44);
	add_to_array(&my_array, 18);
	add_to_array(&my_array, 200);
	printf("capacity: %d\n size: %d\n", my_array.capacity, my_array.size);

	//resize_and_add(&my_array, 4);

	for (size_t i = 0; i <= my_array.size; i++)
		printf("Item %zu: %d\n", i, my_array.array[i]);

	return(0);
}