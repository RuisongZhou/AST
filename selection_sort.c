#include<stdio.h>
void SelectSort(int a[],int n);
int main()
{
    int a[10],i;
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
    SelectSort(a,10);
    printf("����������:\n");
    for(i=0;i<10;i++)
    printf("%3d",a[i]);

}
void SelectSort(int a[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)  //�Ƚ�n-1��
    {
        int k=i; //  ����a[0]��С��k���±�
        for(j=i+1;j<n;j++)
            if(a[k]>a[j])
           k=j;  //kָ��С��
        if(k!=i){
            int temp=a[i];a[i]=a[k];a[k]=temp;
        }
    }
}

