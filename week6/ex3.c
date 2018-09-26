#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handler(int sig)
{
    printf("SIGINT(%d) signal received: program was interrupted by user\n", sig);

    exit(0);
}

int main(int argc, char const *argv[])
{
    signal(SIGINT, handler);

    while (1)
    {
        sleep(1);
    }

    return 0;
}
