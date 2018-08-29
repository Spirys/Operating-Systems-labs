#include <stdio.h>

void swap(int *fst, int *scd);

int main(int argc, char const *argv[])
{
    int a, b;
    char str[256];

    printf("Enter first int:\n");

    fgets(str, sizeof(str), stdin);
    sscanf(str, "%i", &a);

    printf("Enter second int:\n");

    fgets(str, sizeof(str), stdin);
    sscanf(str, "%i", &b);

    swap(&a, &b);

    printf("New a: %i, new b: %i", a, b);

    return 0;
}

void swap(int *fst, int *scd)
{
    int tmp;
    tmp = *fst;
    *fst = *scd;
    *scd = tmp;
}