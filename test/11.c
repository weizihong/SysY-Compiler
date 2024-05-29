#include <stdio.h>

int i = 5;
int func(int a, int b, int c)
{
    i = 4;
    return a + b + c;
}

int a[3] = {1,2,3};

int b[3] = {func(3,1,2), i, a[2]};

int c = func(b[0],b[1],b[2]);

int main()
{
    printf("%d\n", c);
    return 0;
}