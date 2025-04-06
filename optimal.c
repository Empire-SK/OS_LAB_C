#include <stdio.h>

int findOptimal(int pages[], int frame[], int n, int index, int frames) {
    int farthest = -1, pos = -1;
    for (int i = 0; i < frames; i++) {
        int j;
        for (j = index; j < n; j++) {
            if (frame[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    pos = i;
                }
                break;
            }
        }
        if (j == n) return i;
    }
    return (pos == -1) ? 0 : pos;
}

int main() {
    int n, frames, pages[100], frame[10], i, j, pageFaults = 0;
    
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
                break;
            }
        }
        
        if (!found) {
            if (i < frames)
                frame[i] = pages[i];
            else {
                int pos = findOptimal(pages, frame, n, i + 1, frames);
                frame[pos] = pages[i];
            }
            pageFaults++;
        }
        
        printf("\nFrames: ");
        for (j = 0; j < frames; j++) 
            printf("%d ", frame[j]);
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
    return 0;
}