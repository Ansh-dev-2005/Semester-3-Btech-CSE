// activity selection  using greedy method

#include<stdio.h>
#include<stdlib.h>


void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void sort(int s[],int f[],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(f[j]>f[j+1])
            {
                swap(&f[j],&f[j+1]);
                swap(&s[j],&s[j+1]);
            }
        }
    }
}

void activity(int s[],int f[],int n)
{
    int i,j;
    i=0;
    printf("%d ",i);
    for(j=1;j<n;j++)
    {
        if(s[j]>=f[i])
        {
            printf("%d ",j);
            i=j;
        }
    }
}

int main()
{
    int n,i;
    printf("Enter the number of activities: ");
    scanf("%d",&n);
    int s[n],f[n];
    printf("Enter the start time and finish time of each activity: ");
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&s[i],&f[i]);
    }
    sort(s,f,n);
    activity(s,f,n);
    return 0;
}

// give algorithm
