#include<stdio.h>
#include<string.h>
int main()
{
    char a[100];
    double num[100];
    scanf("%s",a);
    int i=strlen(a);
    double s=0;
    int j=0;
    int c,k;
    for(k=0;k<i;k++)
    {
        if((a[k]<='9'&&a[k]>='0')|| a[k]=='.')
        {
            while(a[k]<='9' &&a[k]>='0')       //integer part
            {
                s=s*10+a[k]-'0';
                k++;
            }
            if(a[k]='.')
            {
                double b=0.1;
                k++;               //decimal part
                while (a[k]<='9' &&a[k]>='0')
                {
                    s=s+b*(a[k]-'0');
                    b=b*0.1;
                    k++;

                }
                num[j++]=s;
                s=0;
            }
        }
        else if(s!=0)
            {
                num[j++]=s;
                s=0;
            }
    }
    if(s!=0)            //the last num
    {
        num[j++]=s;
        s=0;
    }
    for(c=0;c<j;c++)
        printf("%f\n",num[c]);
    return 0;
}
