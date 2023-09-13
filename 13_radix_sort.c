// Mehmet Cagri Aksoy - 2023
// 13. Radix Sort

#include <stdio.h>
#include <stdbool.h>

// A utility function to get maximum value in arr[].
int find_max(int *arr, size_t arr_size)
{
    int max = arr[0];
    for (int i = 1; i < arr_size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

// Counting sort of arr[].
void count_sort(int *arr, size_t arr_size, int exp)
{
    int output[arr_size];
    int count[10] = { 0 };

    // Store count of occurrences in count[] 
    for (int i = 0; i < arr_size; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }

    // Change count[i] so that count[i] now contains 
    // actual position of this digit in output[] 
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = arr_size - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now 
    // contains sorted numbers according to curent digit 
    for (int i = 0; i < arr_size; i++)
    {
        arr[i] = output[i];
    }
}

// Radix sort of arr[].
void radix_sort(int *arr, size_t arr_size)
{
    int max = find_max(arr, arr_size);

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        count_sort(arr, arr_size, exp);
    }
}

// Driver program to test above functions.
int main()
{
    int arr[] = { 543, 986, 217, 765, 329 };
    size_t arr_size = sizeof(arr) / sizeof(arr[0]);

    radix_sort(arr, arr_size);

    printf("Sorted array: \n");
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ", arr[i]);
    }
}