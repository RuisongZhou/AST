#include <stdio.h>

int h[101]; //������Ŷѵ�����
int n; //�ѵĴ�С

void swap ( int x,int y )
{
    int t;
    t =h[x];
    h[x]=h[y];
    h[y]=t;
}

//���µ�������
void siftdown ( int i)
{
    int t,flag  = 0 ;
    //���ڵ�i�ж��ӣ���������Ҫ����ʱ��ѭ����ִ��

    while ( i*2<n && flag == 0)
    {
        //���жϺ�����ӹ�ϵ
        if( h[i] > h[i*2] )
            t = i*2;
        else
            t = i;
        //������Ҷ��ӣ����½�С�Ľڵ���
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

// �����Ѻ���
void creat()
{
    int i ;
    for( i = n/2 ; i >=0 ; i--)
    {
        siftdown(i);
    }
}

//ɾ�����Ԫ��
int deletemax()
{
    int t;
    t = h[1]; //��һ����ʱ������¼�Ѷ���ֵ
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
