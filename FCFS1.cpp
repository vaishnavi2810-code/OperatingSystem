#include<stdio.h>
int waiting_time(int processes[],int n,int burst_time[],int wait_time[]){
wait_time[0]=0;
for(int i=1;i<n;i++)
    wait_time[i]=burst_time[i-1]+wait_time[i-1];

}
int turn_around_time(int processes[],int n,int burst_time[],int wait_time[],int tat[]){
int i;
for(i=0;i<n;i++)
    tat[i]=burst_time[i]+wait_time[i];

}
int avg_time(int processes[],int n,int burst_time[]){
int wait_time[n],tat[n],total_wt=0,total_tat=0;
int i;
waiting_time(processes,n,burst_time,wait_time);
turn_around_time(processes,n,burst_time,wait_time,tat);
printf("Processes   BurstTime   WaitingTime   TurnAroundTime\n");
for(i=0;i<n;i++){
    total_wt=total_wt+wait_time[i];
    total_tat=total_tat+tat[i];
    printf("\n%d\t\t%d\t\t%d\t\t%d\t\t\n",i+1,burst_time[i],wait_time[i],tat[i]);
}
printf("Average waiting time=%f\n ",(float)total_wt/(float)n);
printf("Total Turn Around Time=%f\n ",(float)total_tat/(float)n);
}
int main(){

int processes[]={1,2,3,4};
int n =sizeof processes/sizeof processes[0];
int burst_time[]={2,2,3,4};
avg_time(processes,n,burst_time);

}

