#include <stdio.h>
int main()
{
    int a[4][4]={{1,4,3,2},
    {8,6,5,7},
    {10,7,2,5},
    {4,9,6,1}};
    int i,j,k,t;
    int b[16];
    k=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            b[k]=a[i][j];
            k++;
        }
    }
    int q,temp;
    for(t=0;t<15;t++)
    {
        for(q=0;q<15;q++)
            {
                if(b[q]<b[q+1])
                {
                    temp=b[q];
                    b[q]=b[q+1];
                    b[q+1]=temp;
                }

            }
    }
    int c[4][4];
    int pr,z;
    for( pr=0;pr<4;pr++)
        for( z=0;z<4;z++)
        c[pr][z]=b[pr*4+z];
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        printf("%3d",c[i][j]);
    printf("\n");
    }


    return 0;
}
