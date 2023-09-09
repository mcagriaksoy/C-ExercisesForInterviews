// Mehmet Cagri Aksoy - 2023
// To find a sequence of "GLROX" in a string.

#include <stdio.h>

int main()
{
    int number;
    printf("Please insert a number between 0-100:");
    do
    {
        scanf("%d", &number);
    }
    while (number < 0 || number > 100);

    char str_3[] = "Global";
    char str_5[] = "Logic";

    if (number % 3 == 0 && number % 5 == 0)
    {
        printf("%s%s", str_3, str_5);
    }
    else if (number % 3 == 0)
    {
        printf("%s", str_3);
    }
    else if (number % 5 == 0)
    {
        printf("%s", str_5);
    }
    else
    {
        printf("%d", number);
    }
    printf("\n");
    return 0;
}
