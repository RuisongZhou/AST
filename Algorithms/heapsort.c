#include <stdio.h>

int h[101]; //用来存放堆的数组
int n; //堆的大小

void swap ( int x,int y )
{
    int t;
    t =h[x];
    h[x]=h[y];
    h[y]=t;
}

//向下调整函数
void siftdown ( int i)
{
    int t,flag  = 0 ;
    //当节点i有儿子，并且有需要调整时候循环就执行

    while ( i*2<n && flag == 0)
    {
        //先判断和左儿子关系
        if( h[i] > h[i*2] )
            t = i*2;
        else
            t = i;
        //如果有右儿子，更新较小的节点编号
        if ( i*2+1 <=n-1 )
        {
            if ( h[t] > h[i*2+1] )
            t = i*2+1;
        }
        if (t!=i)
        {
            swap(t,i);
            i = t;
        }
        else
            flag = 1;

    }
}

// 建立堆函数
void creat()
{
    int i ;
    for( i = n/2 ; i >=0 ; i--)
    {
        siftdown(i);
    }
}

//删除最大元素
int deletemax()
{
    int t;
    t = h[1]; //用一个临时变量记录堆顶的值
    h[1] = h[n];
    n--;
    siftdown(1);
    return t;
}

int main()
{
    int i,num;
    scanf("%d", &num);
    for ( i = 1 ; i <= num ; i ++)
        scanf("%d", &h[i] );
    n = num;

    creat();

    for ( i = 1 ; i <= num ; i ++ )
    {
        printf("%d ",deletemax());
    }

    return 0;
}
