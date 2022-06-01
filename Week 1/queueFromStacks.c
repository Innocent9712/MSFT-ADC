#include <stdio.h>
#include <stdlib.h>
/**
 * @file queueFromStacks.c
 * @author Innocent Chukwuemeka
 * @brief Implementation of queue from stacks
 * @version 0.1
 * @date 2022-06-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief struct for a stack
 * @capacity: total size of the stack
 * @size: current size of the strack
 * @array: array pointer
 * 
 */

typedef struct Stack {
    unsigned int capacity;
    int size;
    int *array;
} stack;

/**
 * @brief struct for the queue
 * @capacity: total size of the stack
 * @size: current size of the queue
 * @in: stack for input
 * @out: stack for output
 * 
 */

typedef struct Queue {
    unsigned int capacity;
    int size;
    stack *in;
    stack *out;
} queue;

/**
 * @brief create_queue - create a new queue
 * @capacity: capacity of the queue
 * 
 */

queue create_queue(unsigned int capacity)
{
    int *temp = (int *)malloc(sizeof(int) * capacity);
    queue new_queue;
    
    // new_queue = (queue *)malloc(sizeof(queue));
    new_queue.capacity = capacity;
    new_queue.size = -1;
    new_queue.in = malloc(sizeof(stack));
    new_queue.in->capacity = capacity;
    new_queue.in->capacity = capacity;
    new_queue.in->size = -1;
    new_queue.in->array = (int *)malloc(sizeof(int) * capacity);
    new_queue.out = malloc(sizeof(stack));
    new_queue.out->capacity = capacity;
    new_queue.out->size = -1;
    new_queue.out->array = (int *)malloc(sizeof(int) * capacity);

    return (new_queue);
}

/**
 * @brief push_to_queue - push items into the queue
 * 
 * @return int 
 */

int push_to_queue(queue *Q, int item)
{
    if (Q == NULL)
        return (1);
    // printf("size: %d, capacity: %d\n", Q->size, Q->capacity);
    if (Q->size < (int)(Q->capacity - 1))
    {
        Q->in->array[Q->size + 1] = item;
        Q->size += 1;
        Q->in->size += 1;
        printf("Item: %d added successfully!\n", item);
    }
    else
    {
        printf("Queue is at maximum capacity!\nItem: %d not added.\n", item);
        return(1);
    }

    return(0);
    
}

/**
 * @brief pop_from_queue - pop item from the queue
 * 
 * @return int 
 */

int pop_from_queue(queue *Q)
{
    int popped;

    if (!Q)
        return (1);
    if (Q->size == -1)
    {
        printf("Queue is already empty!\n");
        return (-2);
    } 
    else
    {
        while(Q->in->size != -1)
        {
            Q->out->array[Q->out->size + 1] = Q->in->array[Q->in->size];
            Q->out->size++;
            Q->in->size--;
        }

        popped = Q->out->array[Q->out->size];
        Q->out->size--;

        while(Q->out->size != -1)
        {
            Q->in->array[Q->in->size + 1] = Q->out->array[Q->out->size];
            Q->in->size++;
            Q->out->size--;
        }
    }
    Q->size--;
    return (popped);

}

/**
 * @brief print_queue - print all items currently in the queue
 * @Q: queue to list out
 * 
 * @return int 
 */

void print_queue (queue *Q)
{
    if (!Q)
        exit (EXIT_FAILURE);
    
    int i = 0, *list =  Q->in->array;

    printf("Items in queue: [");

    while(i <= Q->size)
    {
        printf(" %d, ", *(list + i));
        i++;
    }
    printf("]\n");
}

int main (void)
{
    int removed;
    queue my_queue = create_queue(5);
    printf("Queue capacity is: %d\n", my_queue.capacity);
    printf("Current Size is: %d\n", my_queue.size);
    push_to_queue(&my_queue, 6);
    push_to_queue(&my_queue, 5);
    push_to_queue(&my_queue, 4);
    push_to_queue(&my_queue, 3);
    removed = pop_from_queue(&my_queue);
    printf("Item: %d has been popped from the queue.", removed);
    push_to_queue(&my_queue, 2);
    push_to_queue(&my_queue, 1);
    push_to_queue(&my_queue, 0);
    push_to_queue(&my_queue, 7);
    removed = pop_from_queue(&my_queue);
    printf("Item: %d has been popped from the queue.", removed);
    push_to_queue(&my_queue, 10);
    print_queue(&my_queue);

    // printf("Input capacity: %d\n", my_queue.in->capacity);
    // printf("Output capacity: %d\n", my_queue.out->capacity);
    // printf("Input size: %d\n", my_queue.in->size);
    // printf("Output size: %d\n", my_queue.out->size);
}