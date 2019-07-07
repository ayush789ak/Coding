#include<stdio.h>
int main()
{
	int i,j,n,k,sum;
	printf("Enter the number of processes");
	scanf("%d",&n);
	int at[n], bt[n],pp[n],wt[n],tu[n];
	int count=0,count1,waiting,turn,temp;
	float avg,avgt,thr,cpu;
	printf("Enter arrival time, priority and burst time");
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d",&at[i],&pp[i],&bt[i]);
		wt[i]=0;
		count=count+bt[i];
	}

	for(i=0; i<n; i++)
        {
                for(j=0; j<n; j++)
                {
                if(pp[i]>pp[j])
                {
                        temp=pp[i];
                        pp[i]=pp[j];
                        pp[j]=temp;
                        temp=bt[i];
                        bt[i]=bt[j];
                        bt[j]=temp;
                        temp=at[i];
                        at[i]=at[j];
                        at[j]=temp;
                }
                }
        }
	count1=count;
	waiting=0;
	for(i=1;i<n;i++)
	{
		sum=0;
		for(k=0;k<i;k++)
			sum=sum+bt[k];
		if(sum<0)
			sum=0;
		wt[i]=sum-at[i];
		waiting=waiting+wt[i];
	}
	avg=(float)waiting / n;
	turn=0;







	for(i=n-1;i>=0;i--)
	{
		tu[i]=count-at[i];
		count=count-bt[i];
		turn=turn+tu[i];
	}
	avgt=(float) turn/n;
	thr=(float) n/count1;
	cpu=(count1/count1)*100;
	printf("Process \t Burst time \t Priority \n");
	for(i=0;i<n;i++)
	{
		printf("%d \t\t %d \t\t %d \n",i+1,bt[i],pp[i]);
	}
	printf("CPU utilization is %f \n",cpu);
	printf("Average response time is %f \n",avg);
	printf("Average waiting time is %f \n",avg);
	printf("Average turn around time is %f \n",avgt);
	printf("Throughtput is %f \n",thr);
return 0;
}
