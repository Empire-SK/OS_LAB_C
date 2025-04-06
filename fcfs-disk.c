#include <stdio.h>
#include <stdlib.h>

void FCFS(int requests[], int n, int head) {
    int total_seek_time = 0;
    
    printf("Sequence of disk access:\n");
    printf("%d", head);
    
    for (int i = 0; i < n; i++) {
        printf(" -> %d", requests[i]);
        total_seek_time += abs(requests[i] - head);
        head = requests[i]; // Move head to current request
    }
    
    printf("\nTotal Seek Time: %d\n", total_seek_time);
}

int main() {
    int n, head;
    
    // Get the number of requests
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);
    
    int requests[n];

    // Get the requests
    printf("Enter the disk request queue: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    // Get the initial head position
    printf("Enter initial head position: ");
    scanf("%d", &head);

    // Call FCFS function
    FCFS(requests, n, head);

    return 0;
}
