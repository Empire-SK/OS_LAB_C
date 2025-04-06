#include <stdio.h>

int findLRU(int counter[], int frames) {
    int min = counter[0], pos = 0;
    for (int i = 1; i < frames; i++) {
        if (counter[i] < min) {
            min = counter[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int n, frames, pages[100], frame[10], counter[10], i, j, pageFaults = 0, time = 0;
    
    printf("Enter number of pages: ");
    scanf("%d", &n);
    
    printf("Enter reference string: ");
    for (i = 0; i < n; i++) 
        scanf("%d", &pages[i]);
    
    printf("Enter number of frames: ");
    scanf("%d", &frames);

    for (i = 0; i < frames; i++) 
        frame[i] = -1; 

    for (i = 0; i < n; i++) {
        int found = 0;
        for (j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                counter[j] = ++time;
                break;
            }
        }
        
        if (!found) {
            int pos = (i < frames) ? i : findLRU(counter, frames);
            frame[pos] = pages[i];
            counter[pos] = ++time;
            pageFaults++;
        }

        printf("\nFrames: ");
        for (j = 0; j < frames; j++) 
            printf("%d ", frame[j]);
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
    return 0;
}