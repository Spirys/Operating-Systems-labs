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
        fgets(command, sizeof(command), stdin);
        system(command);
    }

    return 0;
}
