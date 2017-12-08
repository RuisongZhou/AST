#include<stdio.h>
int main()
{
    int e[10][10],dis[10],book[10];
    int i,j,line,point,p1,p2,distance,u,v,min;
    int inf = 1000;
    scanf("%d %d",&point,&line);

    // intialization
    for ( i = 1 ; i < point ; i ++ )
        for( j = 1 ; j < point ; j++ )
            if ( i == j )
                e[i][j] = 0;
            else e[i][j] = inf;

    //read in line
    for ( i = 0 ; i <line ; i++ )
    {
        scanf("%d %d %d",&p1 , &p2, &distance);
        e[p1][p2] = distance;
    }

    // intialize Array dis ,this is the initial distance between p1 and other points
    for (int i = 1; i < point; ++i)
    {
        dis[i] = e[1][i];
    }

    // intialize Array book
    for (int i = 0; i < point; ++i) {
        book[i] = 0;
    }
    book[1] = 1;

    // Dijkstra Algorithm
    for (int i = 1; i < point-1 ; ++i )
    {
        min = inf;
        for (int j = 1; j <=point ; ++j )
        {
            if ( book[j]==0 && dis[j]<min )
            {
                min =dis[j];
                u = j;
            }
        }
        book[u] = 1;
        for (int v = 1; v <= point; ++v)
        {
            if( e[u][v]<inf)
            {
                if( dis[v] > dis[u]+e[u][v] )
                    dis[v] = dis[u]+e[u][v];
            }
        }
    }

    // print the result
    for (int i = 1; i <= point ; ++i)
    {
        printf("%d ", dis[i]);
    }
    return 0;
}