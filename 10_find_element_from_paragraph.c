// Mehmet Cagri Aksoy - 2023
// Find desired element from a paragraph.

#include <stdio.h>
#include <string.h>

int main()
{
    char paragraph[] = "Finding the truth wouldn't be easy, that's for sure. \
                        Then there was the question of whether or not Jane really \
                        wanted to know the truth. That's the thing that bothered \
                        her most. It wasn't the difficulty of actually finding out \
                        what happened that was the obstacle, but having to live with \
                        that information once it was found the truth.";

    char desired_element[] = "truth";
    int paragraph_size = strlen(paragraph);
    int number_of_occurence = 0;

    for(int i = 0; i < paragraph_size; i++)
    {
        if(paragraph[i] == desired_element[0])
        {
            int j = 0;
            while(paragraph[i] == desired_element[j])
            {
                i++;
                j++;
            }

            if(j == strlen(desired_element))
            {
                number_of_occurence++;
            }
        }
    }
    printf("\n The '%s' found : %d times \n", desired_element,number_of_occurence);
}
