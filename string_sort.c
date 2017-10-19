#include<stdio.h>
#include<string.h>
int main()
{
    char a[100];
    int num[100];
    scanf("%s",a);
    int i=strlen(a);
    int s=0,j=0;
    int c,k;

    for(k=0;k<i;k++)
    {
        if(a[k]<='9' &&a[k]>='0')
        {
            s=s*10+a[k]-'0';
        }
        else if(s!=0)
        {
            num[j++]=s;
            s=0;
        }
    }
    if(s!=0)
    {
        num[j++]=s;
        s=0;
    }
    for(c=0;c<j;c++)
        printf("%d\n",num[c]);
    return 0;

}
