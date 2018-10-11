#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main(int argc, char const *argv[])
{
    int *arr;
    for (int i = 0; i < 10; i++)
    {
        arr = malloc(10 * 1024 * 1024);
        memset(arr, 0, 10 * 1024 * 1024);

        struct rusage usage;
        getrusage(RUSAGE_SELF, &usage);

        printf("Iteration %d. Memory used: %lu mb\n", i, usage.ru_idrss);

        sleep(1);
    }

    return 0;
}
