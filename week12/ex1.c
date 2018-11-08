#include <sys/fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    FILE *f = fopen("ex1.txt", "w");
    int randomData = open("/dev/urandom", O_RDONLY);

    char myRandomData[20];
    read(randomData, myRandomData, sizeof myRandomData);

    printf("%s\n", myRandomData);
    fprintf(f, "%s", myRandomData);

    close(randomData);
    fclose(f);

    return 0;
}
