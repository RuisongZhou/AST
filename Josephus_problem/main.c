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
    createCirList( &circle , n );
    JosephCircle( &circle , m );
    return 0;
}
