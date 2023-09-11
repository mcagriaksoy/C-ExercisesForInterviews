// Mehmet Cagri Aksoy - 2023
// To find the closest pair of two arrays.

#include <stdio.h>

int main()
{
    int ar1[] = {1, 4, 5, 7};
    int ar2[] = {10, 20, 30, 40};
    int ar1_size = sizeof(ar1) / sizeof(ar1[0]);
    int ar2_size = sizeof(ar2) / sizeof(ar2[0]);
    printf("Please insert desired sum value: ");
    int desired_sum;
    scanf("%d", &desired_sum);

    int sum;
    int k = 0;
    int distance;
    int next_distance = 99;

    int point_x;
    int point_y;

    for(int i = 0; i<ar1_size; i++)
    {
        for(int j=0; j<ar2_size; j++)
        {
            sum = ar1[i] + ar2[j];
            if(desired_sum > sum)
            {
                distance = desired_sum - sum;
            }
            else
            {
                distance = sum - desired_sum;
                point_x = i;
                point_y = j;
            }

            if(next_distance > distance)
            {
                next_distance = distance;
            }
        }
    }

    printf("Closest pair is %d and %d \n", ar1[point_x], ar2[point_y]);
    return 0;
}
