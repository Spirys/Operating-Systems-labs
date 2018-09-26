#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define MAX_LENGTH 256

int main(int argc, char const *argv[])
{
    char *text = "Some text here";
    char notext[256];

    int pipefd[2];
    pipe(pipefd);

    pid_t pid = fork();

    if (pid == 0)
    {
        close(pipefd[0]);
        write(pipefd[1], text, MAX_LENGTH);
        close(pipefd[1]);
    }
    else if (pid > 0)
    {
        close(pipefd[1]);
        read(pipefd[0], notext, MAX_LENGTH);

        printf("Not no text string: %s\n", notext);

        close(pipefd[0]);
    }
    else
    {
        return 1;
    }

    return 0;
}
