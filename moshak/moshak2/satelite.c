/*
 * =======================================================================
 * Author:     Rita Ferreira
 * File:       satelite.c
 * Created on: 2025-04-15
 * Purpose:    Brief description of the program
 * =======================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define DIFF(a, b) ((a) > (b) ? (a) - (b) : (b) - (a))

int find(int arr[], int len)
{
    int i;
    int min;

    min = arr[0];
    for (i = 0; i < len; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    return (min);
}

int main()
{
    int len;

    scanf("%d", &len);
    if (len == 0)
        return (printf("0\n"));
    int *dif = malloc(sizeof(int) * len);
    int *ar1 = malloc(sizeof(int) * len);
    int *ar2 = malloc(sizeof(int) * len);
    int i;
    if (dif == NULL || ar1 == NULL || ar2 == NULL)
    {
        free(dif);
        free(ar1);
        free(ar2);
        return (0);
    }
    for (i = 0; i < len; i++)
        scanf("%d", &ar1[i]);
    for (i = 0; i < len; i++)
        scanf("%d", &ar2[i]);
    for (i = 0; i < len; i++)
        dif[i] = DIFF(ar1[i], ar2[i]);
    printf("%d\n", find(dif, len));
    free(ar1);
    free(ar2);
    free(dif);
    return (0);
}