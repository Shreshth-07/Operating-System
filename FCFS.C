#include<stdio.h>
#include<conio.h>

typedef struct process
{
 int ct,at,brt,tat,wt,rt;
}process;

int sort(process [], int);
int main()
{
int n,total;
float AvTat=0,AvWt=0,AvRt=0,Tput=0,Util=0,TotCt=0;
printf("\nShreshth Pratap Singh / Sec - M / Roll_no - 51\n\n");
printf("Enter the number of process:");
scanf("%d",&n);
int tct[n];
process arr[n];
printf("Enter the arival time and brust time:\n");
for(int i=0;i<n;i++)
{
	scanf("%d \t%d",&arr[i].at,&arr[i].brt);
}

//Sorting on the base of Arrival Time
sort(arr,n);

arr[0].ct = arr[0].at + arr[0].brt;

	//Completion Time
	for(int i=1 ; i<n ; i++)
	{
		if(arr[i-1].ct<arr[i].at)
			arr[i].ct = arr[i].at + arr[i].brt;
		else
			arr[i].ct = arr[i-1].ct + arr[i].brt;
	}
	
	//Turn Around Time
	for(int i=0 ; i<n ; i++)
		arr[i].tat = arr[i].ct - arr[i].at;
	
	//Waiting Time
	for(int i=0 ; i<n ; i++)
		arr[i].wt = arr[i].tat - arr[i].brt;
	
	//Resource Time
	for(int i=0 ; i<n ; i++)
	    arr[i].rt = arr[i].at+arr[i].wt;

	printf("\nID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
	
	//Print All Document	
	for(int i=0 ; i<n ; i++)
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i+1,arr[i].at,arr[i].brt,arr[i].ct,arr[i].tat,arr[i].wt,arr[i].rt);
	
	//Throughput 
	for(int i=0 ; i<n ; i++)
	    total+= arr[i].brt;
	Tput = 1.0*(n)/total;

	//Average of WT,RT,TAT and CPU Utilization Time
	for(int i=0 ; i<n ; i++)
	{
	    AvWt += arr[i].wt;
	    AvRt += arr[i].rt;
        AvTat+= arr[i].tat;
        TotCt+= arr[i].brt;
	}
	AvWt = AvWt/n;
	AvRt = AvRt/n;
    AvTat= AvTat/n;
    Util = (TotCt/(TotCt+(n-1))*100);
	
	printf("Average CPU Utilization : %f\nAverage waiting time : %f\nAverage Turn-Around time : %f\nAverage response time : %f\nThrough put : %f\n",Util,AvWt,AvTat,AvRt,Tput);


return 0;
}

int sort(process arr[], int n)
{
    int i, j;
    process k;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {

            if (arr[i].at > arr[j].at)
            {
                k = arr[i];
                arr[i] = arr[j];
                arr[j] = k;
            }
        }
    }
    return 0;
}