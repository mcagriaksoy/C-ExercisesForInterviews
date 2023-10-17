// Mehmet Cagri Aksoy - 2023

#include <stdio.h>
#include <string.h>

/*
K Unique Characters
Have the function KUniqueCharacters(str) take the str parameter being passed and find the longest substring that contains k unique characters, where k will be the first character from the string. The substring will start from the second position in the string because the first character will be the integer k. For example: if str is "2aabbacbaa" there are several substrings that all contain 2 unique characters, namely: ["aabba", "ac", "cb", "ba"], but your program should return "aabba" because it is the longest substring. If there are multiple longest substrings, then return the first substring encountered with the longest length. k will range from 1 to 6.
*/
void KUniqueCharacters(char *str)
{
    int len = strlen(str);
    int k = str[0] - '0';
    int start = 1, end = 1;
    int max_start = 1, max_end = 1;
    int count[26] = {0};
    int unique_count = 0;

    while (end < len)
    {
        // Add the current character to the count
        int index = str[end];
        count[index]++;
        if (count[index] == 1)
        {
            unique_count++;
        }

        // If we have more than k unique characters, move the start pointer
        while (unique_count > k)
        {
            int index = str[start];
            count[index]--;
            if (count[index] == 0)
            {
                unique_count--;
            }
            start++;
        }

        // Update the max substring if necessary
        if (end - start > max_end - max_start)
        {
            max_start = start;
            max_end = end;
        }

        end++;
    }

    // Print the longest substring with at most k unique characters
    for (int i = max_start; i <= max_end; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");
}

int main(void)
{
    char *str = "2aabbacbaa";
    KUniqueCharacters(str);
    return 0;
}