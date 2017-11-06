#include<stdio.h>
#include<stdarg.h>
int sum(int a, ... );

int main()
{
    printf("sum(1, 2, -1024) : %d\n ",
           sum(1, 2 , -1024));
    printf("sum(1, 2, 3, 4, -1024) : %d\n",
           sum(1, 2, 3, 4, -1024));

    return 0;
}
int sum(int a, ...)
{
    int sum = 0;
    int c=a;
    va_list ap;
    va_start ( ap,a );

    while( c != -1024 && c != 0)
    {
        sum += c;
        c=va_arg( ap , int );
    }
    va_end(ap);
    return sum;
}
