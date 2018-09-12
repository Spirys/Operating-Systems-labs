#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    char command[256];
    char hostname[1024];
    gethostname(hostname, 1024);

    while (1)
    {
        printf("%s@%s > ", getlogin(), hostname);
        scanf("%s", command);
        system(command);
    }

    return 0;
}
