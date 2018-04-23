#include <stdio.h>
#include <stdlib.h>
#include "head.h"


int main(void)
{
    int m,n;
    CirList circle;
    printf("the number of people.\n");
    scanf("%d",&n);

    printf("The initial value of m when the number is first reported.\n");
    scanf("%d",&m);

    createCirList( &circle , n );    //创建约瑟夫环
    JosephCircle( &circle , m );    //循环约瑟夫环
    return 0;
}
