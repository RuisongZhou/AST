#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include<string.h>

int compare_high(const void *a , const void *b )
{
    return *(int*)a - *(int*)b;
}
int compare_low(const void *a , const void *b )
{
    return *(int*)b - *(int*)a;
}

void swap(const void* a, const void* b, int size)
{
    assert(a != NULL && b != NULL);
    char tmp = 0;
    int i = 0;
    while (size > 0) {
        tmp = *((char*)a + i);
        *((char*)a + i) = *((char*)b + i);
        *((char*)b + i) = tmp;
        ++i;
        --size;
    }
}
void Qsort(void* base, int left, int right, int size, int (*cmp)(const void* a, const void* b))
{
    assert(base != NULL && size >= 1 && cmp != NULL);    /* left may be < 0 because of the last - 1 */
    if (left >= right) return;
    char* pleft = (char*)base + left * size;
    char* pkey = (char*)base + (left + (right - left) / 2) * size;
    swap(pleft, pkey, size);
    int last = left;
    char* plast = (char*)base + last * size;
    int i;
    for( i = left + 1; i <= right; ++i) {
        char* pi = (char*)base + i * size;
        if (cmp(pi, pleft) < 0) {
            ++last;
            plast = (char*)base + last * size;
            swap(pi, plast, size);
        }
    }
    swap(pleft, plast, size);
    Qsort(base, left, last - 1, size, cmp);
    Qsort(base, last + 1, right, size, cmp);
}


void mysort( void *base , size_t num , size_t size , int (*cmp)(const void *a , const void *b ))
{
    Qsort( base, 0,  num,  size, cmp);
}


int main()
{
    int a[50];
    int i;
    for( i = 0 ; i < 50 ; i++ )
        a[i] = rand()%100;
    qsort( a , 50 , sizeof(int) , compare_high );
    for( i = 0 ; i < 50 ; i++ )
    {
        printf("%4d",a[i]);
        if( (i+1)%5==0 )
            printf("\n");
    }
    printf("\n\n");


    qsort( a , 50 , sizeof(int) , compare_low );
    for( i = 0 ; i < 50 ; i++ )
    {
        printf("%4d",a[i]);
        if( (i+1)%5==0 )
            printf("\n");
    }
    printf("\n\n");


    mysort( a , 50 , sizeof(int) , compare_high );
    for( i = 0 ; i < 50 ; i++ )
    {
        printf("%4d",a[i]);
        if( (i+1)%5==0 )
            printf("\n");
    }


    return 0;
}
