/*
 * =======================================================================
 * Author:     Rita Ferreira
 * File:       shuffle.c
 * Created on: 2025-04-17
 * Purpose:    Brief description of the program
 * =======================================================================
 */

#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int *a = malloc(sizeof(int) * n);
    int *b = malloc(sizeof(int) * m);
    if (!a || !b)
    {
        free(a);
        free(b);
        return (1);
    }
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);
    int i = 0, j = 0, printed = 0;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
            printf("%d", a[i++]);
        else
            printf("%d", b[j++]);
        printed++;
        if (printed < (n + m))
            printf(" ");
    }
    while (i < n)
    {
        printf("%d", a[i]);
        i++;
        printed++;
        if (printed < (n + m))
            printf(" ");
    }
    while (j < m)
    {
        printf("%d", b[j]);
        j++;
        printed++;
        if (printed < (n + m))
            printf(" ");
    }
    free(a);
    free(b);
    printf("\n");
    return (0);
}
