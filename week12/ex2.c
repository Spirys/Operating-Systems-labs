#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char file_name[255] = "";
    char b;
    int fd;

    if (argc > 2)
    {
        if (strcmp(argv[1], "-a") == 0)
        {
            strcpy(file_name, argv[2]);
            fd = open(file_name, O_RDWR | O_APPEND);
        }
    }
    else
    {
        strcpy(file_name, argv[1]);
        fd = open(file_name, O_WRONLY);
    }
    
    while (read(STDIN_FILENO, &b, 1) > 0)
    {
        write(fd, &b, 1);
    }

    return 0;
}