#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(int argc, char const *argv[])
{
    int int1;
    float flt1;
    double dbl1;

    int1 = INT_MAX;
    flt1 = FLT_MAX;
    dbl1 = DBL_MAX;

    printf("Size of int: %lu\nMax value of int: %i\n", sizeof(int1), int1);
    printf("Size of float: %lu\nMax value of float: %f\n", sizeof(flt1), flt1);
    printf("Size of double: %lu\nMax value of double: %f\n", sizeof(dbl1), dbl1);

    return 0;
}
