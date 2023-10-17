// Mehmet Cagri Aksoy - 2023

#include <stdio.h>
#include <string.h>

/*
This code defines a function called PalindromeCreator that takes a string as input and checks if it can be turned into a palindrome by adding at most one character. If it can, the function prints the palindrome. If it can't, the function prints "not possible".

The function first checks if the input string is already a palindrome. If it is, the function prints "palindrome" and returns. If it's not, the function tries to create a palindrome by adding one character. It does this by checking every pair of characters that are not equal and trying to add a character between them that would make them equal. If it finds a solution, it prints the palindrome and returns. If it can't find a solution, it prints "not possible".

The main function calls the PalindromeCreator function with input from the standard input.
*/

void PalindromeCreator(char *str)
{
    size_t str_size = strlen(str);
    size_t number = 0;

    // success case:
    for (int i = 0; i < str_size; i++)
    {
        if (str[i] == str[str_size - i - 1])
        {
            number++;
        }
    }

    if (number == str_size)
    {
        printf("palindrome");
        return;
    }

    // error case 1:
    int k = 0;
    for (int i = 0, j = str_size - 1; i < j; i++, j--)
    {
        if (str[i] != str[j])
        {
            k++;
            if (str_size - k == 3)
            {
                printf("not possible");
                return;
            }
            if (str[i + 1] == str[j])
            {
                printf("%c", str[i]);
                return;
            }

            if (str[i] == str[j - 1])
            {
                printf("%c", str[j]);
                return;
            }

            if (str[i + 1] == str[j - 1])
            {
                printf("%c%c", str[i], str[j]);
                return;
            }

            if (str[i + 1] == str[j] && str[i + 2] == str[j - 1])
            {
                printf("%c%c", str[i], str[i + 1]);
                return;
            }

            if (str[i] == str[j - 1] && str[i + 1] == str[j - 2])
            {
                printf("%c%c", str[j], str[j - 1]);
                return;
            }
        }
    }

    printf("not possible");
    return;
}

int main(void)
{
    PalindromeCreator("racecar");
    PalindromeCreator("abcdcbea");
    return 0;
}