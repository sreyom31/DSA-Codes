#include <stdio.h>

//! This process takes 9 steps to calculate the result
// int power(int m, int n)
// {
//     if(n==0)
//         return 1;
//     return power(m, n-1)*m;
// }

//! While this process takes 6 steps to calculate the result
int power(int m, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return power(m * m, n / 2);
    else
        return m * power(m * m, (n - 1) / 2);
}

int main()
{
    int res = power(2, 9);
    printf("%d\n", res);
    return 0;
}