#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    int n = 645;
    pid_t pid = fork();

    if (pid > 0)
    {
        printf("Hello from parent %d\n", pid - n);
    }
    else
    {
        printf("Hello from child %d\n", pid - n);
    }

    return 0;
}
