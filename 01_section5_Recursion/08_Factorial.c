#include<stdio.h>

int factorial(int n)
{
    if(n<=0)
    {
        return 1;
    } else {
        return factorial(n-1)*n;
    }
}

int main()
{
    int res = factorial(5);
    printf("%d\n", res);
    return 0;
}