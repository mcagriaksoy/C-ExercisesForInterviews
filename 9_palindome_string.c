// Mehmet Cagri Aksoy - 2023
// To check if a string is palindrome or not.

#include <stdio.h>
#include <string.h>

int main()
{
    char array[] = "racecar";
    int array_size = strlen(array) - 1;

    int k = 0;
    for (int i = 0; i < array_size; i++)
    {
        if(array[i] == array[array_size - i])
        {
            k++;
        }
    }

    if (k == array_size)
    {
        printf("Palindrome");
    }
    else
    {
        printf("Not palindrome %d", k);
    }
    return 0;
}
