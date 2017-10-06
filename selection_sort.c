#include<stdio.h>
void SelectSort(int a[],int n);
int main()
{
    int a[10],i;
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
    SelectSort(a,10);
    printf("排序后的数组:\n");
    for(i=0;i<10;i++)
    printf("%3d",a[i]);

}
void SelectSort(int a[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)  //比较n-1次
    {
        int k=i; //  假设a[0]最小，k是下标
        for(j=i+1;j<n;j++)
            if(a[k]>a[j])
           k=j;  //k指向小数
        if(k!=i){
            int temp=a[i];a[i]=a[k];a[k]=temp;
        }
    }
}

