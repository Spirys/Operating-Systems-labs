#include <stdio.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    DIR *dirp = opendir("./tmp");
    struct dirent *dp;
    while ((dp = readdir(dirp)) != NULL)
    {
        struct stat buff;
        stat(dp->d_name, &buff);
        if (buff.st_nlink > 1)
        {
            printf("%s: %ld\n", dp->d_name, buff.st_ino);
        }
    }

    return 0;
}