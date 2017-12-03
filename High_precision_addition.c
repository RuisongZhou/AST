#include<stdio.h>
#include<string.h>
int main()
{
   char a[200],b[200];  //定义字符串数组
   int c[500];
   scanf("%s%s",a,b);   //输入字符串数组
   int i,j,k=0,r=0;
   int lena,lenb;
   lena = strlen(a);
   lenb = strlen(b);
   for(i=lena-1,j=lenb-1;i>=0&&j>=0;i--,j--)
    {
      int p=(a[i]-'0')+(b[j]-'0')+r;
      r=p/10;       //进位
      c[k++]=p%10;  //余数加到数组中
    }
    while(i>=0)//如果b中的数加完了
     {
        int p=(a[i]-'0')+r;
        r=p/10;
        c[k++]=p%10;
        i--;
     }
     while(j>=0)//如果a中的数加完了
     {
        int p=(b[j]-'0')+r;
        r=p/10;
        c[k++]=p%10;
        j--;
     }
     if(r)//判断最高位有没有进位
     {
         c[k++]=r;
     }
     for( i=k-1;i>=0;i--)//输出结果
     {
         printf("%d",c[i]);
     }
     return 0;
 }
