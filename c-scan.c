#include<stdio.h>
int main()
{
    int arr[20],n,head,i,j,k,seek=0,max,diff,temp,arr1[20],arr2[20],
                        temp1=0,temp2=0;
    float avg;
    printf("\nShreshth Pratap Singh / Sec - M / Roll_no - 51\n\n");
    printf("Enter the max range of disk\n");
    scanf("%d",&max);
    printf("Enter the initial head position\n");
    scanf("%d",&head);
    printf("Enter the size of arr request\n");
    scanf("%d",&n);
    printf("Enter the arr of disk positions to be read\n");
    for(i=1; i<=n; i++)
    {
        scanf("%d",&temp);
        if(temp>=head)
        {
            arr1[temp1]=temp;
            temp1++;
        }
        else
        {
            arr2[temp2]=temp;
            temp2++;
        }
    }
    for(i=0; i<temp1-1; i++)
    {
        for(j=i+1; j<temp1; j++)
        {
            if(arr1[i]>arr1[j])
            {
                temp=arr1[i];
                arr1[i]=arr1[j];
                arr1[j]=temp;
            }
        }
    }
    for(i=0; i<temp2-1; i++)
    {
        for(j=i+1; j<temp2; j++)
        {
            if(arr2[i]>arr2[j])
            {
                temp=arr2[i];
                arr2[i]=arr2[j];
                arr2[j]=temp;
            }
        }
    }
    for(i=1,j=0; j<temp1; i++,j++)
        arr[i]=arr1[j];
    arr[i]=max;
    arr[i+1]=0;
    for(i=temp1+3,j=0; j<temp2; i++,j++)
        arr[i]=arr2[j];
    arr[0]=head;
    for(j=0; j<=n+1; j++)
    {
        diff=abs(arr[j+1]-arr[j]);
        seek+=diff;
        printf("%d->%d difference = %d\n",arr[j],arr[j+1],diff);
    }
    printf("Total seek time is %d\n",seek);
    avg=seek/(float)n;
    printf("Average seek time is %f\n",avg);
    return 0;
}
