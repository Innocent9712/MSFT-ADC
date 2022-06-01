/**
 * @file qiestion1.c
 * @author Innocent Chukwuemeka
 * @brief a function that returns the first non duplicate character in a string
 * @version 0.1
 * @date 2022-06-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief check_string - checks string to find the first non duplicate character
 * @str: string to check
 * 
 * Return: the character
 */
typedef struct Map {
    char key;
    int count;
} mapping;

typedef struct MapDefinition {
    int size;
    mapping *array;
} map;


int get_position (mapping *arr, char key)
{
    int i = 0;
    // mapping *temp = arr.array;

    while (arr[i].key != key)
        i++;
    
    return (i);
}


int check_for_Key(map arr, char key)
{
    mapping *temp = arr.array;
    if (arr.size == 0)
        return (0);

    while(temp)
    {
        if (temp->key == key)
            return (1);
        temp++;
    }
    return (0);
}

void add_to_map(map *arr, char key)
{
    // arr->array[arr->size + 1].key = key;
    // arr->array[arr->size + 1].count = 1;
    arr->size++;
    // printf("Key %c added to map!", key);
    printf("size of arr %d", arr->size);
}

void increase_count(map *arr, char key)
{
    int position = get_position(arr->array, key);

    arr->array[position].count++;
    printf("count for Key: %c increased!", key);
}

char check_string(const char *str, int size)
{
    map newMap;

    newMap.size = -1;
    newMap.array = (mapping *)malloc(size * sizeof(mapping));

    // newMap.array[0].count = 0;
    // printf("count: %d", newMap.array[0].count);



    for (size_t i = 0; str[i] != '\0'; i++)
    {     
        if (check_for_Key(newMap, str[i]) == 0)
        {
            // add_to_map(&newMap, str[i]);
            // printf("Not in Map");
            newMap.array[newMap.size + 1].key = str[i];
            // newMap.array[newMap.size + 1].count = 1;
            printf("Key %c added to map!", str[i]);
            // newMap.size++;
            // printf("size of arr %d", arr->size);
        }
        else
        {
            // printf("in Map");
            increase_count(&newMap, str[i]);
        }
        
    }

    return ('\0');
}

int main (void)
{
    char *string = "minimum";
    char response = check_string(string, sizeof(string));

    printf("The first non duplicate character is: %c\n", response);

    return (0);
}