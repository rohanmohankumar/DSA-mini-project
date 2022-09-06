#include<stdio.h>
#define MAX 200
int main()
{
int i, limit, total = 0, x, counter = 0, time_quantum;
int wait_time = 0, turnaround_time = 0, burst_time[MAX], temp[MAX];
float average_wait_time, average_turnaround_time;
printf("Enter Total Number of Processes:");
scanf("%d", &limit);
x = limit;
for(i = 0; i < limit; i++) //enter burst time for each process
{
printf("Enter Burst Time[%d]: ", i + 1);
scanf("%d", &burst_time[i]);
temp[i] = burst_time[i];//copy each burst time to temporary variable
}
printf("Enter Time Quantum: ");
scanf("%d", &time_quantum);
printf("\nProcess ID\tBurst Time\tTurnaround Time\t\tWaiting Time\n");
total=0;
i=0;
while(x!=0)
{
if(temp[i] <= time_quantum && temp[i] > 0) //iterate through each
{ // process when burst time is less
total = total + temp[i]; // than time quantum
temp[i] = 0;
x--;
printf("\nProcess[%d]\t%d\t\t%d\t\t\t%d",i+1,
burst_time[i], total, total - burst_time[i]);
wait_time = wait_time + total - burst_time[i];
turnaround_time = turnaround_time + total;
}
else if(temp[i] > 0)
{
temp[i] = temp[i] - time_quantum;
total = total + time_quantum;
}
if(i == limit - 1) // when reached the final process of each cycle
i = 0;
else
i++;
}
average_wait_time = wait_time * 1.0 / limit;
average_turnaround_time = turnaround_time * 1.0 / limit;
printf("\n\nAverage Waiting Time:%.2f", average_wait_time);
printf("\nAverage Turnaround Time:%.2f\n", average_turnaround_time);
return 0;
}
