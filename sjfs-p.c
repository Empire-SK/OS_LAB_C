<<<<<<< HEAD
#include <stdio.h>
#include <limits.h>

int n, burst[20], remaining[20], arrival[20], waiting[20], turnaround[20], completion[20];

void input()
{
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival time and burst time for P%d: ", i + 1);
        scanf("%d %d", &arrival[i], &burst[i]);

        remaining[i] = burst[i]; // Copy burst times to remaining times
    }
}

void calculateTimes()
{
    int completed = 0, currentTime = 0, shortest = -1, minBurst = INT_MAX;
    int isCompleted[20] = {0}; // Track completed processes

    while (completed < n)
    {
        shortest = -1;
        minBurst = INT_MAX;

        // Find the process with the shortest remaining burst time at the current time
        for (int i = 0; i < n; i++)
        {
            if (arrival[i] <= currentTime && !isCompleted[i] && remaining[i] < minBurst)
            {
                minBurst = remaining[i];
                shortest = i;
            }
        }

        if (shortest == -1)
        {
            currentTime++; // If no process is available, move time forward
            continue;
        }

        remaining[shortest]--; // Execute process for 1 unit of time

        // If the process is completed
        if (remaining[shortest] == 0)
        {
            completed++;
            completion[shortest] = currentTime + 1;
            turnaround[shortest] = completion[shortest] - arrival[shortest];
            waiting[shortest] = turnaround[shortest] - burst[shortest];
            isCompleted[shortest] = 1;
        }
        currentTime++;
    }
}

// Function to calculate average waiting and turnaround time
float calcAverage(int arr[20])
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum / n;
}

// Function to display results
void display()
{
    printf("\nPreemptive SJF (SRTF) Scheduling\n");
    printf("\nProcess  Arrival  Burst  Completion  Turnaround  Waiting\n");

    for (int i = 0; i < n; i++)
    {
        printf("P%d        %d        %d        %d          %d          %d\n",
            i + 1, arrival[i], burst[i], completion[i], turnaround[i], waiting[i]);
    }

    printf("\nAverage Waiting Time: %.2f", calcAverage(waiting));
    printf("\nAverage Turnaround Time: %.2f\n", calcAverage(turnaround));
}

// Main function
int main()
{
    input();
    calculateTimes();
    display();
    return 0;
}
=======
#include <stdio.h>
#include <limits.h>

int n, burst[20], remaining[20], arrival[20], waiting[20], turnaround[20], completion[20];

void input()
{
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival time and burst time for P%d: ", i + 1);
        scanf("%d %d", &arrival[i], &burst[i]);

        remaining[i] = burst[i]; // Copy burst times to remaining times
    }
}

void calculateTimes()
{
    int completed = 0, currentTime = 0, shortest = -1, minBurst = INT_MAX;
    int isCompleted[20] = {0}; // Track completed processes

    while (completed < n)
    {
        shortest = -1;
        minBurst = INT_MAX;

        // Find the process with the shortest remaining burst time at the current time
        for (int i = 0; i < n; i++)
        {
            if (arrival[i] <= currentTime && !isCompleted[i] && remaining[i] < minBurst)
            {
                minBurst = remaining[i];
                shortest = i;
            }
        }

        if (shortest == -1)
        {
            currentTime++; // If no process is available, move time forward
            continue;
        }

        remaining[shortest]--; // Execute process for 1 unit of time

        // If the process is completed
        if (remaining[shortest] == 0)
        {
            completed++;
            completion[shortest] = currentTime + 1;
            turnaround[shortest] = completion[shortest] - arrival[shortest];
            waiting[shortest] = turnaround[shortest] - burst[shortest];
            isCompleted[shortest] = 1;
        }
        currentTime++;
    }
}

// Function to calculate average waiting and turnaround time
float calcAverage(int arr[20])
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum / n;
}

// Function to display results
void display()
{
    printf("\nPreemptive SJF (SRTF) Scheduling\n");
    printf("\nProcess  Arrival  Burst  Completion  Turnaround  Waiting\n");

    for (int i = 0; i < n; i++)
    {
        printf("P%d        %d        %d        %d          %d          %d\n",
            i + 1, arrival[i], burst[i], completion[i], turnaround[i], waiting[i]);
    }

    printf("\nAverage Waiting Time: %.2f", calcAverage(waiting));
    printf("\nAverage Turnaround Time: %.2f\n", calcAverage(turnaround));
}

// Main function
int main()
{
    input();
    calculateTimes();
    display();
    return 0;
}
>>>>>>> 95782fa0065487f7fdd75540991dddb97af0516a
