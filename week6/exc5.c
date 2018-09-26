#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    pid_t pid = fork();

    if (pid == 0)
    {
        while (1)
        {
            sleep(1);
            printf("I'm alive\n");
        }
    }

    if (pid > 0)
    {
        sleep(10);
        kill(pid, SIGTERM);
        printf("Child killed\n");
    }

    return 0;
}