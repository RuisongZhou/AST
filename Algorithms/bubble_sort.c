#include <stdio.h>

int main() {
    int a[100],j,i,k,t;
    for(i=0;i<100;i++)
        scanf("%d",&a[i]);
    printf("\n");
    for(i=0;i<99;i++)
    {
      for(j=i+1;j<100-i;j++)
       {
           if(a[i]>a[j])
         {t=a[i];
          a[i]=a[j];
          a[j]=t;}
       }
   }printf("the sort number is\n");
    for(i=0;i<100;i++)
printf("%3d",a[i]);
return 0;
}
