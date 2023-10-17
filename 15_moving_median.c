// Mehmet Cagri Aksoy - 2023

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//  calculate the median in an array within a sliding window.
/*
Moving Median
    Have the function
    MovingMedian(arr) read the array of numbers stored in arr which will contain a sliding window size, N, as the first element in the array and the rest will be a list of numbers. Your program should return the Moving Median for each element based on the element and its N-1 predecessors, where N is the sliding window size. The final output should be a string with the moving median corresponding to each entry in the original array separated by commas.

Note that for the first few elements (until the window size is reached), the median is computed on a smaller number of entries. For example: if arr is [3, 1, 3, 5, 10, 6, 4, 3, 1] then your program should output "1,2,3,5,6,6,4,3"
Examples
Input: {5, 2, 4, 6}
Output: 2,3,4
Input: {3, 0, 0, -2, 0, 2, 0, -2}
Output: 0,0,0,0,0,0,0
*/

void MovingMedian(int arr[], int size)
{
    int window_size = arr[0];
    int window[window_size];
    int window_index = 0;

    for (int i = 1; i < size; i++)
    {
        // Add the current element to the window
        window[window_index] = arr[i];
        window_index = (window_index + 1) % window_size;

        // Sort the window
        int sorted_window[window_size];
        for (int j = 0; j < window_size; j++)
        {
            sorted_window[j] = window[j];
        }
        for (int j = 0; j < window_size - 1; j++)
        {
            for (int k = j + 1; k < window_size; k++)
            {
                if (sorted_window[j] > sorted_window[k])
                {
                    int temp = sorted_window[j];
                    sorted_window[j] = sorted_window[k];
                    sorted_window[k] = temp;
                }
            }
        }

        // Calculate the median
        int median;
        if (window_size % 2 == 0)
        {
            median = (sorted_window[window_size / 2 - 1] + sorted_window[window_size / 2]) / 2;
        }
        else
        {
            median = sorted_window[window_size / 2];
        }

        // Print the median
        printf("%d,", median);
    }
}

int main()
{
    int arr1[] = {5, 2, 4, 6};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    MovingMedian(arr1, size1);

    int arr2[] = {3, 0, 0, -2, 0, 2, 0, -2};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    MovingMedian(arr2, size2);

    return 0;
}