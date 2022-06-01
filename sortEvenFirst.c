#include <stdlib.h>
#include <stdio.h>
/**
 * @file sortEvenFirst.c
 * @author Innocent Chukwuemeka
 * @brief A program to sort an array of numbers into even numbers first
 * @version 0.1
 * @date 2022-06-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

int *sortEvenFirst(int *arr, int size)
{
    if (arr == NULL)
        exit(EXIT_FAILURE);
    int length = size / sizeof(arr[0]);

    for (size_t i = 0; i <= length; i++)
    {
        for (size_t j = 1; arr[j] != '\0'; j++)
        {
            if ((arr[j - 1] & 1) != 0 && (arr[j] & 1) == 0)
            {
                arr[j] = arr[j]^arr[j - 1];
                arr[j - 1] = arr[j]^arr[j - 1];
                arr[j] = arr[j]^arr[j - 1];
            }
            
        }
    }

    return (arr);
}

void print_arr(int *arr, char *title)
{
    printf("%s: [", title);
    while (*arr)
    {
        printf(" '%d' ", *arr);
        arr++;
    }
    printf("]\n");
}

int main(void)
{
    int *sorted;

    int sample1[] = {3, 65, 96, 12, 8, 19, 2, 6, 9, 14, 1, 84, 4, 13, 16}; 
    print_arr(sample1, "sample1");
    sorted = sortEvenFirst(sample1, sizeof(sample1));
    print_arr(sorted, "sorted");

    int sample2[10] = {7, 9, 4, 13, 17, 2, 11, 4, 6};
    print_arr(sample2, "sample2");
    sorted = sortEvenFirst(sample2, sizeof(sample2));
    print_arr(sorted, "sorted");

}