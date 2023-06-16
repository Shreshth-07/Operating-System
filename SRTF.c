#include<stdio.h>

typedef struct process
{
 int ct,at,brt,tat,wt,rt;
}process;

int sorting(process arr[], int n)
{
    int i, j;
    process k;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {

            if (arr[i].brt > arr[j].brt)
            {
                k = arr[i];
                arr[i] = arr[j];
                arr[j] = k;
            }
        }
    }
    return 0;
}

int main()
{
int n,total;
float AvTat=0,AvWt=0,AvRt=0,Tput=0,Util=0,TotCt=0;
printf("Abhyuday pratap singh / Sec - M / Rollno - 68\n");
printf("Enter the number of process:");
scanf("%d",&n);
int tct[n];
process arr[n];
printf("Enter the arival time and brust time:\n");
for(int i=0;i<n;i++)
{
    printf("Enter the %d process AT:",i+1);
	scanf("%d",&arr[i].at);
    printf("Enter the %d process BT:",i+1);
    scanf("%d",&arr[i].brt);
}

sorting(arr,n);

arr[0].ct = arr[0].at + arr[0].brt;
	for(int i=1 ; i<n ; i++)
	{
		if(arr[i-1].ct<arr[i].at)
			arr[i].ct = arr[i].at + arr[i].brt;
		else
			arr[i].ct = arr[i-1].ct + arr[i].brt;
	}
	
	for(int i=0 ; i<n ; i++)
		arr[i].tat = arr[i].ct - arr[i].at;
		
	for(int i=0 ; i<n ; i++)
		arr[i].wt = arr[i].tat - arr[i].brt;
	
	for(int i=0 ; i<n ; i++)
	    arr[i].rt = arr[i].at+arr[i].wt;
	printf("\nID\tAT\tBT\tCT\tTAT\tWT\tRT\n");	
	for(int i=0 ; i<n ; i++)
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i+1,arr[i].at,arr[i].brt,arr[i].ct,arr[i].tat,arr[i].wt,arr[i].rt);
		
	for(int i=0 ; i<n ; i++)
	    total+= arr[i].brt;
	Tput = 1.0*(n)/total;
	printf("Through put : %f\n",Tput);
	
	for(int i=0 ; i<n ; i++)
	{
	    AvWt += arr[i].wt;
	    AvRt += arr[i].rt;
        AvTat+= arr[i].tat;
        TotCt+= arr[i].ct;
	}
	AvWt = AvWt/n;
	AvRt = AvRt/n;
    AvTat= AvTat/n;
    Util = (TotCt/(TotCt+(n-1))*100);
	
	printf("Average response time : %f\nAverage waiting time : %f\nAverage Turn-Around time : %f\nAverage CPU Utilization : %f\n",AvRt,AvWt,AvTat,Util);

return 0;
}

