// Mehmet Cagri Aksoy 2023 - Using Luhn algorithms and MOD 10 checksums
// Example. github.com/mcagriaksoy
// Test input : 4417123456789113
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 16
int main(void)
{
    char* input = NULL;
    input = (char *)malloc(MAX_SIZE*sizeof(char));
    
    scanf("%s", input);
    int len = strlen(input);
    int inputArray[len];
    int sum = 0;

    for (int i = 0; i < len; i++)
    {
        inputArray[i] = *input - '0'; // Converting char to int w.o using library
        input += 1; // iterate chars!
        //printf("%d", inputArray[i]);
        if(i % 2 == 0)
        {
            inputArray[i] *= 2;
            if (inputArray[i] >= 10)
            {
                int ones = inputArray[i] % 10;
                int tens = inputArray[i] / 10;
                inputArray[i] = ones + tens;
            }
        }
        sum += inputArray[i];
        //printf("%d", inputArray[i]);
    }

    if (sum % 10 == 0)
    {
        printf("The credit card is VALID!");
    }
    else
    {
        printf("The credit card is INVALID or FAKE!");
    }
    return 0;
}
