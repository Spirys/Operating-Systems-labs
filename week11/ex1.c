#include <sys/fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <memory.h>

const char s[] = "This is a nice day";

int main(int argc, char const *argv[])
{
    int file = open("ex1.txt", O_RDWR);

    ftruncate(file, sizeof(s));

    struct stat stat_s = {};
    fstat(file, &stat_s);

    size_t len = (size_t)stat_s.st_size;

    void *ad = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED, file, 0);

    memcpy(ad, s, sizeof(s));

    munmap(ad, sizeof(s));
    close(file);

    return 0;
}