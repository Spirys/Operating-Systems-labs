#include <stdio.h>
#include <unistd.h>

#define MAX_LENGTH 256

int main(int argc, char const *argv[])
{
    char *text = "Some text here";
    char notext[256];

    int pipefd[2];
    pipe(pipefd);

    write(pipefd[1], text, MAX_LENGTH);
    read(pipefd[0], notext, MAX_LENGTH);

    printf("Not no text string: %s\n", notext);

    return 0;
}
