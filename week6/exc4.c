#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handler_aggregator(int sig)
{
    if (sig == SIGINT)
    {
        printf("SIGINT signal received: program was interrupted by user\n");
        exit(0);
    }
    else if (sig == SIGKILL)
    {
        printf("SIGKILL signal received: program was stopped\n");
    }
    else if (sig == SIGSTOP)
    {
        printf("SIGSTOP signal received: program was paused\n");
    }
    else if (sig == SIGUSR1)
    {
        printf("SIGUSR1 signal received\n");
    }
    else
    {
        printf("Cannot define signal\n");
    }

    exit(0);
}

int main(int argc, char const *argv[])
{
    signal(SIGINT, handler_aggregator);
    signal(SIGKILL, handler_aggregator);
    signal(SIGSTOP, handler_aggregator);
    signal(SIGUSR1, handler_aggregator);

    while (1)
    {
        sleep(1);
    }

    return 0;
}
