/*
 * =======================================================================
 * Author:     Rita Ferreira
 * File:       hike.c
 * Created on: 2025-04-15
 * Purpose:    Brief description of the program
 * =======================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define ABS(a, b) (((a) > (b)) ? (a) - (b) : (b) - (a))

int cost(int *arr, int len)
{
    int i;
    int sum = 0;

    for (i = 0; i < len; i++)
        sum += ABS(arr[i], arr[i + 1]);
    sum = sum + ABS(arr[len - 1], arr[0]);
    return (sum);
}

int find(int *arr, int len)
{
    int i;
    int j;
    int min;

    min = arr[0];
    j = 0;
    for (i = 0; i < len; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            j = i;
        }
    }
    return (j);
}
//verrrrrrr
void swap(int *arr, int lenght, int k)
{
    int *new = malloc(sizeof(int) * lenght);
    if (!new)
        return;
    for (i = 0; i + k < lenght; i++)
        new[i] = arr[i + k];
    while (i > lenght - k)
    {
        new[i] = arr[i - k];
        i--;
    }
    for (int i = 0; i < lenght; i++)
        arr[i] = new[i];
    free(new);
}

int main()
{
    int len;
    len = scanf("%d", &len);
    int *arr = malloc(sizeof(int) * len);
    int *sum = malloc(sizeof(int) * len);
    if (!arr || !sum)
    {
        free(arr);
        free(sum);
        return (0);
    }
    for (int i = 0; i < len; i++)
        scanf("%d", &arr[i]);
    for (int i = 0; i < len; i++)
        sum[i] = cost(arr, len);
    swap(arr, len, find(sum, len));
    for (int i = 0; i < len; i++)
    {
        printf("%d", arr[i]);
        if (i != len - 1)
            printf(" ");
    }
    free(arr);
    free(sum);
    return (0);
}
