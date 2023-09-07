#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main()
{
    char password[100] = "0#9yV4y&ng8ALb,9A5wB&&lv";
    bool hasCapital = false;
    bool hasSpecial = false;
    bool hasNormal = false;
    bool hasNumber = false;
    
    for (int i = 0; i < strlen(password); i++)
    {
        if(password[i] >= 'A' && password[i] <= 'Z')
        {
            hasCapital = true;
        }
        else if (password[i] >= '0' && password[i] <= '9')
        {
            hasNumber = true;
        }
        else if (password[i] >= 'a' && password[i] <= 'z')
        {
            hasNormal = true;
        }
        else if((password[i] >= ':' && password[i] <= '?') ||
                (password[i] >= '!' && password[i] <= '@') ||
                (password[i] >= '[' && password[i] <= '_') ||
                (password[i] >= '{' && password[i] <= '~'))
        {
            hasSpecial = true;
        }
        else
        {
            printf("Not valid character exist on password!\n");
            break;
        }
    }
    
    if(hasNumber && hasNormal && hasSpecial && hasCapital)
    {
        printf("Success! The passport Strength is OK!\n");
    }
    else
    {
        printf("Weak Password!\n");
    }
 return 0;
}

