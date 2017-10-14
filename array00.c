#include<stdio.h>

void swap(int *a,int *b);

int main()
{
    int a[4][4]={ {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
    int i,j,k,s;
    for(i=0;i<3;i++)
    {
        for(k=3;k>i;k--)
            swap(&a[i][k],&a[k][i]);
    }
    for(j=0;j<4;j++)
    {
        for(s=0;s<4;s++)
            printf("%3d",a[j][s]);
        printf("\n");
    }
    return 0;
}

void swap(int *a,int *b)
{
    int p;
   p=*a;
   *a=*b;
   *b=p;


}
