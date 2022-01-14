#include <stdio.h>

int tribo(int n)
{
    if (n < 2)
        return 0;
    if (n == 2)
        return 1;
    return tribo(n-1) + tribo(n-2) + tribo(n-3);
}

int main()
{
    int x, i;
    for (i = 0; i < 15; i++)
    {
        x = tribo(i);
        printf("%d\n", x);
    }
    return 0;
}