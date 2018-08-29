#include <stdio.h>
#include <stdlib.h>

void triange(int n);
void right_triangle(int n);
void square(int n);

int main(int argc, char const *argv[])
{
    int n, type;
    sscanf(argv[1], "%i", &n);

    printf("Choose type (1, 2 or 3):\n");
    char str[256];

    sscanf(str, "%i", &type);

    switch (type)
    {
    case 1:
        triange(n);
        break;
    case 2:
        right_triangle(n);
        break;
    case 3:
        square(n);
        break;
    default:
        printf("Incorrect type");
    }

    return 0;
}

void triange(int n)
{
    int size = n * 2 - 1;

    for (int i = 0; i < n; ++i)
    {
        char *str;
        str = (char *)malloc(size);

        int j;
        for (j = 0; j < (size - 1) / 2 - i; ++j)
        {
            str[j] = ' ';
        }

        for (; j < (size - 1) / 2 + i + 1; ++j)
        {
            str[j] = '*';
        }

        for (; j < size; ++j)
        {
            str[j] = ' ';
        }

        printf("%s\n", str);
    }
}

void square(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d", '*');
        }
        printf("\n");
    }
}

void right_triangle(int n)
{
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < i + 1; j++)
        {
            printf("%s", "*");
        }
        printf("\n");
    }
}
