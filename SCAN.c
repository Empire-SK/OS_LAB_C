#include <stdio.h>
#include <stdlib.h>

void SCAN(int requests[], int n, int head, int disk_size, int direction) {
    int total_seek_time = 0;
    int sorted[n + 2], index = 0;

    // Add head position and disk boundaries
    sorted[index++] = head;
    for (int i = 0; i < n; i++)
        sorted[index++] = requests[i];

    if (direction == 1)  // Moving towards larger track numbers
        sorted[index++] = disk_size - 1;  // End boundary
    else
        sorted[index++] = 0;  // Start boundary

    // Sort the requests including boundaries
    for (int i = 0; i < index - 1; i++) {
        for (int j = 0; j < index - i - 1; j++) {
            if (sorted[j] > sorted[j + 1]) {
                int temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }
    }

    // Find head index in sorted array
    int head_index;
    for (int i = 0; i < index; i++) {
        if (sorted[i] == head) {
            head_index = i;
            break;
        }
    }

    printf("Sequence of disk access:\n");
    
    // Move in the selected direction first
    if (direction == 1) {  // Moving right
        for (int i = head_index; i < index; i++) {
            printf("%d -> ", sorted[i]);
            if (i > head_index) total_seek_time += abs(sorted[i] - sorted[i - 1]);
        }
        for (int i = head_index - 1; i >= 0; i--) {
            printf("%d -> ", sorted[i]);
            total_seek_time += abs(sorted[i] - sorted[i + 1]);
        }
    } else {  // Moving left
        for (int i = head_index; i >= 0; i--) {
            printf("%d -> ", sorted[i]);
            if (i < head_index) total_seek_time += abs(sorted[i] - sorted[i + 1]);
        }
        for (int i = head_index + 1; i < index; i++) {
            printf("%d -> ", sorted[i]);
            total_seek_time += abs(sorted[i] - sorted[i - 1]);
        }
    }

    printf("\nTotal Seek Time: %d\n", total_seek_time);
}

int main() {
    int n, head, disk_size, direction;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int requests[n];
    printf("Enter the disk request queue: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &requests[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &disk_size);

    printf("Enter direction (1 for right, 0 for left): ");
    scanf("%d", &direction);

    SCAN(requests, n, head, disk_size, direction);

    return 0;
}
