/*
 * =======================================================================
 * Author:     Rita Ferreira
 * File:       pascal.c
 * Created on: 2025-04-15
 * Purpose:    Brief description of the program
 * =======================================================================
 */


#include <stdio.h>
#include <stdlib.h>

// n linha
// k coluna

int main()
{
    int n;
    int k;
    long long c;

    scanf("%d", &n);
    n = n - 1;
    c = 1;
    if (n == 0)
    {
        printf("%d\n", 1);
        return (0);
    }
    for (k = 0; k <= n; k++)
    {
        printf("%lld", c);
        if (k != n)
            printf(" ");
        c = c * (n - k) / (k + 1);
    }
    printf("\n");
    return (0);
}