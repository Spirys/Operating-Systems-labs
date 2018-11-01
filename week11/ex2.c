#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    char *s = "Hello";

    for (int i = 0; i < 5; i++)
    {
        printf("%c", s[i]);
        sleep(1);
    }

    fflush(stdout);

    return 0;
}