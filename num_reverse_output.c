#include<stdio.h>
int main()
{
    unsigned long long int n;
    scanf("%lld",&n);
    int m;
    while(n!=0)
    {
        m=n%10;
        printf("%d",m);
        n=n/10;

    }
    return 0;
}
