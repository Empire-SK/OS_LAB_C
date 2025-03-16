#include<stdio.h>
int burst[20], process[20], n, waiting[20], turnaround[20], time = 0;

void input(){
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        printf("enter burst time for P%d: ", i + 1);
        scanf("%d", &burst[i]);
        process[i] = i + 1;  // Initialize process numbers
    }
}

void calculateWaiting(){
    for(int i=0;i<n;i++){
        waiting[i] = time;
        time += burst[i];
    }
}

void calculateTurnaround(){
    for(int i=0;i<n;i++){
        turnaround[i] = waiting[i] + burst[i];
    }
}

float calcaverage(int a[20]){
    float sum = 0;
    float avg = 0;
    for(int i=0;i<n;i++){
        sum = sum + a[i];
    }
    avg = sum / n;
    return avg;
}

void sort(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(burst[j] > burst[j+1]){
                // Swap burst times
                int temp = burst[j];
                burst[j] = burst[j+1];
                burst[j+1] = temp;
                
                // Swap process numbers
                temp = process[j];
                process[j] = process[j+1];
                process[j+1] = temp;
            }
        }
    }
}

void display(){
    printf("\nSJF\n\n");
    printf("Process  Burst Time  Waiting Time  Turnaround Time\n");
    for(int i=0;i<n;i++){
        printf("P%d        %d            %d            %d\n", process[i], burst[i], waiting[i], turnaround[i]);
    }
    printf("\nAverage Waiting time is : %f", calcaverage(waiting));
    printf("\nAverage Turnaround time is : %f", calcaverage(turnaround));
}

void main(){
    input();
    sort();
    calculateWaiting();
    calculateTurnaround();
    display();
}