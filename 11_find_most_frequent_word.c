// Mehmet Cagri Aksoy - 2023
// Find most frequent word from a paragraph.

#include <stdio.h>
#include <string.h>

#define MAX_WORD_LEN (10)

int main()
{
    const char paragraph[] = "Finding the truth wouldn't be easy, that's for sure. Then there was the question of whether or not Jane really wanted to know the truth.";

    // Get the length of the paragraph
    int paragraph_size = strlen(paragraph);

    // Initialize a variable to store the number of words in the paragraph
    int word_number = 0;

    // Declare a 2D array to store the words from the paragraph
    char words[paragraph_size][MAX_WORD_LEN];

    // Declare a variable to keep track of the index of each word
    int k = 0;
    // Loop through each character in the paragraph
    for(int i = 0; i < paragraph_size; i++)
    {
        // Copy the character to the words array
        words[word_number][k++] = paragraph[i];
        // If the character is a space, then it marks the end of a word
        if(paragraph[i] == ' ')
        {
            // Add a null character to terminate the word
            words[word_number][k-1] = '\0';
            // Reset the index for the next word
            k = 0;
            // Increment the word number
            word_number++;
        }
    }

    // Declare a variable to store the count of each word
    int count = 0;
    // Declare a variable to store the maximum count of any word
    int max_count = 0;
    // Declare an array to store the most frequent word
    char max_repeated_word[MAX_WORD_LEN];

    // Loop through each word in the words array
    for(int i = 0; i < word_number; i++)
    {
    // Loop through each word after the current word
    for (int j = i+1; j < word_number; j++)
    {
        // Compare the current word with the next word and check if they are not empty spaces
        if(strcmp(words[i], words[j]) == 0 && strcmp(words[i], " ") != 0 )
        {
            // Increment the count if they are equal
            count++;
        }
    }

    // Check if the count is greater than the maximum count
    if (count > max_count)
    {
            // Update the maximum count and copy the current word to the most frequent word array
            max_count = count;
            strcpy(max_repeated_word, words[i]);
    }
    }

    printf("\nMost frequent word is : \"%s\" and %d times\n", max_repeated_word, max_count);
}
