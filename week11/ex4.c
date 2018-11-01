#include <sys/fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <memory.h>

int main(int argc, char const *argv[])
{
    int file1 = open("ex1.txt", O_RDONLY, 0666);
    int file2 = open("ex1.memcpy.txt", O_RDWR | O_CREAT, 0666);

    struct stat stat_s = {};
    fstat(file1, &stat_s);

    size_t file1_len = (size_t)stat_s.st_size;

    ftruncate(file2, file1_len);

    void *file1_ad = mmap(NULL, file1_len, PROT_READ, MAP_PRIVATE, file1, 0);
    void *file2_ad = mmap(NULL, file1_len, PROT_READ | PROT_WRITE, MAP_SHARED, file2, 0);

    memcpy(file2_ad, file1_ad, file1_len);

    munmap(file1_ad, file1_len);
    munmap(file2_ad, file1_len);

    close(file1);
    close(file2);

    return 0;
}