#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void SSTF(int requests[], int n, int head) {
    int total_seek_time = 0;
    bool visited[n];  // Array to track served requests

    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    printf("Sequence of disk access:\n");
    printf("%d", head);

    // Process all requests using SSTF
    for (int i = 0; i < n; i++) {
        int min_distance = __INT_MAX__;  // Large initial value
        int closest_index = -1;

        // Find the closest unvisited request
        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                int distance = abs(requests[j] - head);
                if (distance < min_distance) {
                    min_distance = distance;
                    closest_index = j;
                }
            }
        }

        // Move to the closest request
        total_seek_time += min_distance;
        head = requests[closest_index];
        visited[closest_index] = true;

        printf(" -> %d", head);
    }

    printf("\nTotal Seek Time: %d\n", total_seek_time);
}

int main() {
    int n, head;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int requests[n];

    printf("Enter the disk request queue: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    SSTF(requests, n, head);

    return 0;
}
