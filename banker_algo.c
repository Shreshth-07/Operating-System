#include<stdio.h>
typedef struct process
{
    int alloc[20][20];
    int max[20][20];
    int need[20][20];
}process;


void main()
{
    int n, m, i, j, k,available[20];
    int f[20],ans[20], ind=0;

    printf("Shreshth Pratap Singh / Sec-M / Roll_no.-51\n");
    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter the number of Resources: ");
    scanf("%d",&m);

    process arr[n];

    printf("Enter the Values of Allocation Matrix: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("Enter value at position (%d%d) :",i+1,j+1);
            scanf("%d",&arr[i].alloc[i][j]);
        }
    }

        printf("Enter the Values of Max Matrix: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("Enter value at position (%d%d) :",i+1,j+1);
            scanf("%d",&arr[i].max[i][j]);
        }
    }

    printf("Enter the values in available: \n");
    for(j=0;j<m;j++)
    {
        printf("Enter value at position (%d) :",j+1);
        scanf("%d",&available[j]);
    }

    for(k=0;k<n;k++)
    {
        f[k]=0;
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            arr[i].need[i][j] = arr[i].max[i][j] - arr[i].alloc[i][j];
        }
    }

    int y=0;

    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            if(f[i]==0)
            {
                int flag = 0;
                for(j=0;j<m;j++)
                {
                    if(arr[i].need[i][j] > available[j])
                    {
                        flag=1;
                        break;
                    }
                }

                if(flag==0)
                {
                    ans[ind++] = i;
                    for(y=0;y<m;y++)
                    {
                        available[y] = available[y] + arr[i].alloc[i][y];
                    }
                    f[i]=1;
                }
            }
        }
    }

    printf("The SAFE SEQUENCE is: \n");
    for(i=0;i<n-1;i++)
    {
        printf(" P%d ->", ans[i]);
    }
    printf(" P%d", ans[n-1]);

}
