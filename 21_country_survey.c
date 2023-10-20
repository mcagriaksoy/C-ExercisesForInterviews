// Mehmet Cagri Aksoy

#include <stdio.h>
#include <string.h>

typedef struct personal_info
{
    char name[50];
    int age;
} personal_info;

typedef struct Person
{
    personal_info info;
    char city[20];
    int salary;
} Person;

int age_more_than_k(struct Person p[], int k, int n)
{
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (p[i].info.age > k)
        {
            result++;
        }
    }

    return result;
}

int persons_from_city_c(struct Person p[], char c[], int n)
{
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (memcmp(p[i].city, c, strlen(c)) == 0)
        {
            result++;
        }
    }

    return result;
}

int salary_between(struct Person p[], int minimum, int maximum, int n)
{
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (p[i].salary >= minimum && p[i].salary <= maximum)
        {
            result++;
        }
    }

    return result;
}

int main()
{
    // TEST CASE 1

    struct Person p1 = {{"Mehmet Cagri Aksoy", 25}, "Istanbul", 1000};
    struct Person p2 = {{"John Doe", 30}, "Istanbul", 2000};
    struct Person p3 = {{"Jane Doe", 35}, "Istanbul", 3000};
    struct Person p4 = {{"Jack Doe", 40}, "Burgaz", 4000};
    struct Person p5 = {{"Jill Doe", 45}, "Istanbul", 5000};

    struct Person persons[5] = {p1, p2, p3, p4, p5};

    int result = age_more_than_k(persons, 30, 5);
    if (result == 3)
    {
        printf("TEST CASE 1 age_more_than_k PASSED\n");
    }
    else
    {
        printf("TEST CASE 1 age_more_than_k FAILED, Your result %d\n", result);
    }

    result = persons_from_city_c(persons, "Istanbul", 5);
    if (result == 4)
    {
        printf("TEST CASE 1 persons_from_city_c PASSED\n");
    }
    else
    {
        printf("TEST CASE 1 persons_from_city_c FAILED, Your result %d\n", result);
    }

    result = salary_between(persons, 2000, 4000, 5);
    if (result == 3)
    {
        printf("TEST CASE 1 salary_between PASSED\n");
    }
    else
    {
        printf("TEST CASE 1 salary_between FAILED, Your result %d\n", result);
    }
}
