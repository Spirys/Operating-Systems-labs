#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int n;
    char str[256];

    printf("Enter array size: ");

    fgets(str, sizeof(str), stdin);
    sscanf(str, "%i", &n);

    int *arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }

    for (int i = 0; i < n - 1; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("%i\n", arr[n - 1]);

    free(arr);

    return 0;
}
