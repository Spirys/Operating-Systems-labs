#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

void *my_realloc(void *ptr, size_t size);

int main(int argc, char const *argv[])
{
    // Just copy/paste from previous exercise (for test only)

    printf("Enter original array size:");
    int n1 = 0;
    scanf("%d", &n1);

    //Create a new array of n1 ints
    int *a1 = malloc(n1 * sizeof(int));
    int i;
    for (i = 0; i < n1; i++)
    {
        //Set each value in a1 to 100
        a1[i] = 100;

        //Print each element out (to make sure things look right)
        printf("%d ", a1[i]);
    }

    //User specifies the new array size, stored in variable n2.
    printf("\nEnter new array size: ");
    int n2 = 0;
    scanf("%d", &n2);

    //Dynamically change the array to size n2
    a1 = my_realloc(a1, n2);

    //If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.

    if (n2 > n1)
    {
        for (int i = n1; i < n2; i++)
        {
            a1[i] = 0;
        }
    }

    for (i = 0; i < n2; i++)
    {
        //Print each element out (to make sure things look right)
        printf("%d ", a1[i]);
    }
    printf("\n");

    //Done with array now, done with program :D

    free(a1);

    return 0;
}

void *my_realloc(void *ptr, size_t size)
{
    if (size == 0)
    {
        free(ptr);
        return NULL;
    }
    else if (ptr == NULL)
    {
        ptr = malloc(size);
        return ptr;
    }
    else
    {
        size_t ptr_size = malloc_usable_size(ptr);
        if (ptr_size == size)
        {
            return ptr;
        }
        else
        {
            void *new = malloc(size);

            memcpy(new, ptr, ptr_size);
            free(ptr);

            return new;
        }
    }
}
