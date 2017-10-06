#include<stdio.h>
void swap(int*,int*);
int main(void){
int a[100],i,j,k,n;
for(i=0;i<100;i++)
    a[i]=i+1;
for(j=0;j<50;j++)
swap(&a[j],&a[99-j]);
printf("The new array is\n");
for(k=0;k<10;k++)
{
    for(n=0;n<10;n++)
        printf("%4d",a[10*k+n]);

    printf("\n");
}

}
void swap(int *a,int *b)
{
    int i;
    i=*a;*a=*b;*b=i;

}
