#include<stdio.h>

int fun(int n)
{
    if(n>0) {
       return fun(n-1)+n;
    }
}

int main()
{
    int res = fun(5);
    printf("%d\n", res);
    return 0;
}