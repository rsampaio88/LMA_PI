/*
 * =======================================================================
 * Author:     Rita Ferreira
 * File:       sorting.c
 * Created on: 2025-04-17
 * Purpose:    Brief description of the program
 * =======================================================================
 */

#include <stdlib.h>
#include <stdio.h>

int main()
{
    int len;
    scanf("%d", &len);
    int *arr = malloc(sizeof(int) * len);
    if (!arr)
        return (1);
    for (int i = 0; i < len; i++)
        scanf("%d", &arr[i]);
    char *check = calloc(100001, sizeof(char));
    if (!check)
    {
        free(arr);
        return (1);
    }
    int numbers = 0;
    for (int i = 0; i < len; i++)
    {
        if (!check[arr[i]])
        {
            check[arr[i]] = 1;
            numbers += 1;
        }
    }
    for (int i = 0; i < len; i++)
    {
        if (check[arr[i]])
        {
            printf("%d", arr[i]);
            check[arr[i]] = 0;
            numbers--;
            if (numbers)
                printf(" ");
        }
    }
    printf("\n");
    free(arr);
    free(check);
    return (0);
}
