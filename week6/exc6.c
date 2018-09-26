#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    pid_t child1_pid, child2_pid;

    int pipefd[2];
    pipe(pipefd);

    child1_pid = fork();

    if (child1_pid == 0)
    {
        int status;
        printf("Child process 1 has started\n");

        read(pipefd[0], &status, sizeof(status));
        printf("Got %d\n", status);
        
        kill(status, SIGSTOP);
        printf("Child process 2 was killed\n");
        
        return 0;
    }
    else
    {
        child2_pid = fork();

        if (child2_pid == 0)
        {
            printf("Child process 2 has started\n");
            
            while (1)
            {
                printf("I'm alive\n");
                sleep(1);
            }
        }
        else
        {
            printf("Parent process has started\n");
            printf("child1_pid %d\n", child1_pid);
            printf("child2_pid %d\n", child2_pid);

            write(pipefd[1], &child2_pid, sizeof(child2_pid));
            
            waitpid(child2_pid, 0, 0);
        }
    }

    return 0;
}