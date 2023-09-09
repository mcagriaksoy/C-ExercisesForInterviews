// Mehmet Cagri Aksoy - 2023
// To find a sequence of "GLROX" in a string.

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#ifdef __unix__ 
    #include <unistd.h>
#elif defined(_WIN32)
    #define OS_Windows 1
    #include <windows.h>
#endif


bool isSearchingStrAvailable(char *str, char *searchStr)
{
    bool isFound = false;
    int searchStrIndex = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == searchStr[searchStrIndex])
        {
            searchStrIndex++;
            if (searchStrIndex == strlen(searchStr))
            {
                isFound = true;
                break;
            }
        }
    }
    return isFound;
}

bool receiveString(char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        str[i] = (rand() % 26) + 'A'; // Random char from A to Z!
    }
    return true; // return false in case of error!
}

int main()
{
    char str[32] ="GdsertoczxLiodcdsRcksOklcsdXl";
    char searchString[6] = "GLROX";
    while (!isSearchingStrAvailable(str, searchString))
    {
        printf("%s ", str);
        sleep(1); // 1 sec for testing!

        if (receiveString(str) == false)
        {
             sleep(2); // Wait 2 seconds.
        }
    }

    printf("Found! %s\n", searchString);
    return 0; 
}
