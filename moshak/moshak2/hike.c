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

/*
Rotação Circular

index = (i + k) % lenght 
arr = [1, 10, 5, 4]
k = 2

new[0] = arr[(0 + 2) % 4] = arr[2] = 5
new[1] = arr[(1 + 2) % 4] = arr[3] = 4
new[2] = arr[(2 + 2) % 4] = arr[0] = 1
new[3] = arr[(3 + 2) % 4] = arr[1] = 10

*/

void    print_arr(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d", arr[i]);
        if (i != len - 1)
            printf(" ");
    }
    printf("\n");
}


int main()
{
    int len;
    scanf("%d", &len);
    int *arr = malloc(sizeof(int) * len);
    int *costs = malloc(sizeof(int) * len);
    if (!arr || !costs)
        return 1;
    for (int i = 0; i < len; i++)
        scanf("%d", &arr[i]);
    int equal = 1;
    for (int i = 1; i < len; i++)
    {
        if (arr[i] != arr[0])
        {
            equal = 0;
            break;
        }
    }
    if (equal)
    {
        print_arr(arr, len);
        free(arr);
        free(costs);
        return 0;
    }
    int min_cost = __INT_MAX__;
    int min_k = 0;
    for (int k = 0; k < len; k++)
    {
        int sum = 0;
        for (int i = 0; i < len - 1; i++)
        {
            int x = arr[(i + k) % len];
            int y = arr[(i + k + 1) % len];
            sum += ABS(x, y);
        }

        if (sum < min_cost)
        {
            min_cost = sum;
            min_k = k;
        }
    }
    int *new = malloc(sizeof(int) * len);
    if (!new)
        return 1;
    for (int i = 0; i < len; i++)
        new[i] = arr[(i + min_k) % len];
    print_arr(new, len);
    free(arr);
    free(costs);
    free(new);
    return 0;
}

/*
void swap(int *arr, int lenght, int k)
{
    int *new = malloc(sizeof(int) * lenght);
    if (!new)
        return;
    for (int i = 0; i < lenght; i++)
        new[i] = arr[(i + k) % lenght];
    for (int i = 0; i < lenght; i++)
        arr[i] = new[i];
    free(new);
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

int cost(int *arr, int len, int k)
{
    int i;
    int sum = 0;

    for (i = 0; i < len - 1; i++)
    {
        int x = arr[(i + k) % len];
        int y = arr[(i + k + 1) % len];
        sum += ABS(x, y);
    }
    return (sum);
}


int main()
{
    int len;
    scanf("%d", &len);
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
    for (int i = 1; i < len; i++)
    {
        if (arr[0] != arr[i])
            break;
        if (i == len - 1)
        {
            print_arr(arr, len);
            free(arr);
            free(sum);
            return (0);
        }
    }
    for (int i = 0; i < len; i++)
        sum[i] = cost(arr, len, i);
    swap(arr, len, find(sum, len));
    print_arr(arr, len);
    free(arr);
    free(sum);
    return (0);
}
*/
