#include<stdio.h>

int sum(int a[] ,int );

int main()
{
    int a[100];
    int i=0;
    while(scanf("%d",&a[i])==1)
        i++;
    long k=sum (a,i);
    printf("%ld",k);
    return 0;
}
int sum(int a[],int n)
{
    int i;
    long k=0;
    for(i=0;i<n;i++)
        k+=a[i];
    return k;
}
