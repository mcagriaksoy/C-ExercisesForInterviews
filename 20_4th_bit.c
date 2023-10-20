// Mehmet Cagri Aksoy

#include <stdio.h>

int fouthbit(int n)
{
    int binary_number[sizeof(int) * 8];
    int i = 0;
    while (n > 0)
    {
        binary_number[i] = n % 2;
        n /= 2;
        i++;
    }

    return binary_number[3];
}

int main()
{
    int n = 0;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (fouthbit(n))
    {
        printf("The fourth bit is 1.\n");
    }
    else
    {
        printf("The fourth bit is 0.\n");
    }

    return 0;
}