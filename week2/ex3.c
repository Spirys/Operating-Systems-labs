#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const* argv[])
{
	int n; 
	sscanf(argv[1], "%i", &n);

	int size = n * 2 - 1;

	for (int i = 0; i < n; ++i)
	{
		char* str;
		str = (char*)malloc(size);

		int j;
		for (j = 0; j < (size-1)/2-i; ++j)
		{
			str[j] = ' ';
		}

		for (; j < (size-1)/2+i+1; ++j)
		{
			str[j] = '*';
		}

		for (; j < size; ++j)
		{
			str[j] = ' ';
		}

		printf("%s\n", str);
	}
}
