#include<stdio.h>
#incng.h>
struct student {
    int id;
    double grades;

};
void struct_sort(struct student *st,int );
int main()
{
    struct student person[100];
    int i=0;
    printf("Please enter the student 1's id:");
    while(scanf("%d",&person[i].id)==1)
    {
        printf("Please enter the student %d 's grade:",i+1);
        scanf("%lf",&person[i].grades);
        i++;
        printf("\nPlease enter the %d student id(enter q to break):",i+1);

    }
    struct_sort(person,i);
    return 0;

}
void struct_sort(struct student *st ,int n)
{
    int i=0;
    int j,k,m;
    struct student temp;
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
            if(st[j].grades>st[j+1].grades)
           k=j;
        if(k!=i){
             temp=st[i];
            st[i]=st[k];
            st[k]=temp;
        }
    }
    printf("id\tgrades\n");
    for(m=0;m<n;m++)
        printf("%d\t%f\n",st[m].id,st[m].grades);
}
