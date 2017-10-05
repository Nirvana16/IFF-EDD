//gcc -std=c99 -o vararray vararray.c
#include <stdio.h>

void foo(int n)
{
    float vals[n];

    for (int i = 0; i < n; i++)
	{
        vals[i] = 5*i;
		printf("[%d]:%f \n", i, vals[i]);
	}
}

int main(void)
{
	foo(5);
}
