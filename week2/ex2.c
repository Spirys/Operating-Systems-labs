#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    printf("Enter string:\n");
    char str[256];

    fgets(str, sizeof(str), stdin);

    int len = strlen(str);
    char new_str[len];

    for (register int i = 0; i < len; ++i)
    {
        new_str[i] = str[len - 1 - i];
    }

    printf("Reversed string: %s", new_str);

    return 0;
}
