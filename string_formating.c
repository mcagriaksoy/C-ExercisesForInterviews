// Mehmet Cagri Aksoy - 2023
// Phone number formating or String formating interview question solution.

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool removeSelectedElementFromString(char *str, char character)
{
    bool isFound = false;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == character)
        {
            isFound = true;
            for (int j = i; j < strlen(str); j++)
            {
                str[j] = str[j + 1];
            }
        }
    }
    return isFound;
}

void makeStringGroup(char *str)
{
    int currentElement = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        currentElement = i + 1;    
        if (currentElement % 4 == 0)
        {
            for (int j = strlen(str); j >= i; j--)
            {
                str[j + 1] = str[j];
            }
            str[i] = ' ';
        }
    }
}

int main()
{
    char str[100] ="00-44 4 8  -55-55  -8361";
    char underScore = '-';
    char blank = ' ';

    removeSelectedElementFromString(str, underScore);

    while (removeSelectedElementFromString(str, blank));
    makeStringGroup(str);

     printf("\nResult: ");
    for(int i=0; i<strlen(str); i++)
    {
        printf("%c", str[i]);
    }

    return 0; 
}
