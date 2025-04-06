#include <stdio.h>

int main() {
    int n, frames, pages[100], frame[10], i, j, k, pageFaults = 0;
    
    printf("Enter number of pages: ");
    scanf("%d", &n);
    
    printf("Enter reference string: ");
    for (i = 0; i < n; i++) 
        scanf("%d", &pages[i]);
    
    printf("Enter number of frames: ");
    scanf("%d", &frames);

    for (i = 0; i < frames; i++) 
        frame[i] = -1;  // Initialize frames as empty
    
    j = 0;
    for (i = 0; i < n; i++) {
        int found = 0;
        for (k = 0; k < frames; k++) {
            if (frame[k] == pages[i]) {
                found = 1;
                break;
            }
        }
        
        if (!found) {  
            frame[j] = pages[i];  
            j = (j + 1) % frames;  // FIFO replacement
            pageFaults++;
        }
        
        // Print current frame status
        printf("\nFrames: ");
        for (k = 0; k < frames; k++) 
            printf("%d ", frame[k]);
    }
    
    printf("\nTotal Page Faults: %d\n", pageFaults);
    return 0;
}