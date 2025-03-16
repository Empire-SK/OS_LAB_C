#include <stdio.h>
int burst[20], n, waiting[20], turnaround[20], time = 0;

void input()
{
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("enter burst time for P%d: ", i + 1);
        scanf("%d", &burst[i]);
    }
}

void calculateWaiting()
{
    for (int i = 0; i < n; i++)
    {
        waiting[i] = time;
        time += burst[i];
    }
}

void calculateTurnaround()
{
    for (int i = 0; i < n; i++)
    {
        turnaround[i] = waiting[i] + burst[i];
    }
}

float calcAverage(int a[20])
{
    float sum = 0;
    float avg = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + a[i];
    }
    avg = sum / n;
    return avg;
}

void display(){
    printf("\nSJF\n\n");
    printf("Process  Burst Time  Waiting Time  Turnaround Time\n");
    for(int i=0;i<n;i++){
        printf("P%d        %d            %d            %d\n",i+1, burst[i], waiting[i], turnaround[i]);
    }
    printf("\nAverage Waiting time is : %f", calcAverage(waiting));
    printf("\nAverage Turnaround time is : %f", calcAverage(turnaround));
}

void main()
{
    input();
    calculateWaiting();
    calculateTurnaround();
    display();
}