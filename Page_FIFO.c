#include <stdio.h>

int search(int n, int a[])
{
    for(int i=0;i<3;i++)
    {
        if(n==a[i])
        {
            return 1;
        }
    }
    return -1;
}

int main() {
    printf("Shreshth pratap singh / Sec - M / Rollno - 51\n");
    int a[100],n,page[3]={};
    printf("Enter the number of pages:");
    scanf("%d",&n);
    printf("Enter the page number:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    for(int j=0;j<3;j++)
    {
        page[j]=-1;
    }

    int index=-1,hit=0,miss=0,size=-1;

    for(int i=0;i<n;i++)
    {
        if(size<3)
        {
            page[(index+1)%3]=a[i];
            size++;
            miss++;
            index++;
        }
        else
        {
            int f = search(a[i],page);
            if(f==1)
            {
                hit++;
            }
            else
            {
                miss++;
                page[(index+1)%3]=a[i];
                index=(index+1 %3);
            }
        }
        printf("The array is :");
        for(int k=0;k<3;k++)
        {
            printf("%d",page[k]);
        }
        printf("\n");
    }
    printf("Hit is %d, and Miss is %d",hit,miss);

    return 0;
}
