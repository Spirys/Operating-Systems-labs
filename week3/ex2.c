#include <stdio.h>

void bubble_sort(int *arr, int length);

int main(int argc, char *argv[])
{
    int arr[] = {4, 5, 2, 97, 34, 6723, 31};
    int length = sizeof(arr) / sizeof(arr[0]);

    bubble_sort(arr, length);

    return 0;
}

void bubble_sort(int *arr, int length)
{
    for (register int i = 0; i < length; ++i)
    {
        for (register int j = i + 1; j < length; ++j)
        {
            if (arr[i] > arr[j])
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}
