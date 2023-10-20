// Mehmet Cagri Aksoy

#include <stdio.h>

int xor_maximum(int lo, int hi, int k)
{
    if (lo > hi || hi == 0 || k == 0 || lo == 0)
    {
        return 0;
    }

    int difference = hi - lo;
    int max_result = 0;
    for (int i = 0; i <= difference; i++)
    {
        for (int j = 0; j <= difference; j++)
        {
            if (max_result < ((lo + i) ^ (lo + j)))
            {
                max_result = ((lo + i) ^ (lo + j));
            }
        }
    }

    if (max_result > k)
    {
        return k;
    }

    return max_result;
}

int main()
{
    int lo = 10;
    int hi = 15;
    int k = 12;

    // TEST CASE 1
    int result = xor_maximum(lo, hi, k);
    if (result == 7)
    {
        printf("Test 1 Passed!\n");
    }
    else
    {
        printf("Test 1 Failed! Your result: %d\n", result);
    }

    // TEST CASE 2
    lo = 11;
    hi = 100;
    k = 5;
    result = xor_maximum(lo, hi, k);
    if (result == 5)
    {
        printf("Test 2 Passed!\n");
    }
    else
    {
        printf("Test 2 Failed! Your result: %d\n", result);
    }

    // TEST CASE 3
    lo = 3;
    hi = 5;
    k = 6;
    result = xor_maximum(lo, hi, k);
    if (result == 6)
    {
        printf("Test 3 Passed!\n");
    }
    else
    {
        printf("Test 3 Failed! Your result: %d\n", result);
    }

    // TEST CASE 4
    lo = 2;
    hi = 4;
    k = 8;
    result = xor_maximum(lo, hi, k);
    if (result == 7)
    {
        printf("Test 4 Passed!\n");
    }
    else
    {
        printf("Test 4 Failed! Your result: %d\n", result);
    }

    return 0;
}