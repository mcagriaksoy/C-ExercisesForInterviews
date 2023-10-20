// Mehmet Cagri Aksoy - 2023

#include <stdio.h>
#include <string.h>

void Nullify_min(int **a, int **b)
{
    if (**a > **b)
    {
        *b = NULL;
    }
    else if (**b > **a)
    {
        *a = NULL;
    }
}

int find_Maximum(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else if (b > a)
    {
        return b;
    }
    else
    {
        return 0;
    }
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    // TEST CASE 1
    int a = 5;
    int b = 10;
    int *ptr_a = &a;
    int *ptr_b = &b;
    printf("TEST CASE 1\n");
    swap(ptr_a, ptr_b);
    int max = find_Maximum(a, b);
    if (max == a)
    {
        printf("Swap and Find_max test Passed!\n");
    }
    else
    {
        printf("Swap and Find_max test Failed!\n");
    }

    Nullify_min(&ptr_a, &ptr_b);
    if (ptr_b == NULL)
    {
        printf("Nullify_min test Passed!\n");
    }
    else
    {
        printf("Nullify_min test Failed!\n");
    }
}