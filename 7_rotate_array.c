// Mehmet Cagri Aksoy - 2023
// To rotate an array with given index.

#include <stdio.h>

void rotateArrayWithGivenIndex(int *array, size_t array_size, int index)
{
    int temp_array[array_size];
    int k = 0;
    for (int i = index; i < array_size; i++)
    {
        temp_array[k] = array[i];
        k++;
    }

    for (int i = 0; i < index; i++)
    {
        temp_array[k] = array[i];
        k++;
    }

    for(int i = 0; i < array_size; i++)
    {
        array[i] = temp_array[i];
        printf("%d ", array[i]);
    }

    printf("\n");
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7}; 
    int array_size = sizeof(array) / sizeof(array[0]);

    printf("Please insert an index number between 0-%d:", array_size - 1);
    int index;
    do
    {
        scanf("%d", &index);
    }while(index < 0 || index > array_size - 1);

    rotateArrayWithGivenIndex(array, array_size, index);
    return 0;
}
