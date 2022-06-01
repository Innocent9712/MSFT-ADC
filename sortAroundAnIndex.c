#include <stdlib.h>
#include <stdio.h>
/**
 * @file sortAroundAnIndex.c
 * @author Innocent Chukwuemeka
 * @brief A prgoram that takes an array and sorts it based on the value of a given index.
 * @version 0.1
 * @date 2022-06-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

int *sortAroundAnIndex(int *A, int i, int size)
{
    if (A == NULL)
        return (0);
    int val = A[i], length = size / sizeof(A[0]);
    printf("value is: %d\n", val);

    for (size_t k = 0; k <= length; k++)
    {
        for (size_t j = 1; A[j] != '\0'; j++)
        {
            if (A[j] <= val && A[j - 1] > val)
            {
                A[j] = A[j]^A[j - 1];
                A[j - 1] = A[j]^A[j - 1];
                A[j] = A[j]^A[j - 1];
            }

            if (A[j] < val && A[j - 1] == val)
            {
                A[j] = A[j]^A[j - 1];
                A[j - 1] = A[j]^A[j - 1];
                A[j] = A[j]^A[j - 1];
            }
        }
    } 
    return (A);
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
    sorted = sortAroundAnIndex(sample1, 8, sizeof(sample1));
    print_arr(sorted, "sorted");

    int sample2[10] = {9, 8, 7, 6, 5, 4, 3};
    print_arr(sample2, "sample2");
    sorted = sortAroundAnIndex(sample2, 3, sizeof(sample2));
    print_arr(sorted, "sorted");
}