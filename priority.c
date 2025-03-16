#include <stdio.h>
int pid[20], burst[20], n, waiting[20], turnaround[20], time = 0, priority[20];

void input()
{
    printf("Enter the no . of processes:");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        printf("enter burst time for P%d:", i + 1);
        scanf("%d", &burst[i]);
        printf("enter priority for P%d:", i + 1);
        scanf("%d", &priority[i]);
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
    float avg;
    for (int i = 0; i < n; i++)
    {
        sum = sum + a[i];
    }
    avg = sum / n;
    return avg;
}

void sort()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (priority[j] > priority[j + 1])
            {
                int temp = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp;

                temp = burst[j];
                burst[j] = burst[j + 1];
                burst[j + 1] = temp;

                temp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = temp;
            }
        }
    }
}

void display()
{
    printf("PID\tBurst time\tPriority time\tWaiting time\tTurnaround time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], burst[i], priority[i],
            waiting[i], turnaround[i]);
    }
}

void main()
{
    input();
    sort();
    calculateWaiting();
    calculateTurnaround();
    display();
    printf("\nAverage waiting time is :%f", calcAverage(waiting));
    printf("\nAverage Turnaround time is :%f\n", calcAverage(turnaround));
}
