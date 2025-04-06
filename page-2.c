#include <stdio.h>

void printFrames(int frames[], int f) {
    for (int i = 0; i < f; i++) {
        if (frames[i] == -1)
            printf("- ");
        else
            printf("%d ", frames[i]);
    }
    printf("\n");
}

// FIFO
void fifo(int pages[], int n, int f) {
    int frames[10], index = 0, faults = 0;

    for (int i = 0; i < f; i++) frames[i] = -1;

    printf("\nFIFO Page Replacement:\n");

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            frames[index] = pages[i];
            index = (index + 1) % f;
            faults++;
        }

        printFrames(frames, f);
    }

    printf("Total Page Faults: %d\n", faults);
}

// Optimal
void optimal(int pages[], int n, int f) {
    int frames[10], faults = 0;

    for (int i = 0; i < f; i++) frames[i] = -1;

    printf("\nOptimal Page Replacement:\n");

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            int replace = -1, farthest = i;
            for (int j = 0; j < f; j++) {
                int k;
                for (k = i + 1; k < n; k++) {
                    if (frames[j] == pages[k]) break;
                }

                if (k > farthest) {
                    farthest = k;
                    replace = j;
                }
                if (k == n) {
                    replace = j;
                    break;
                }
            }

            if (replace == -1)
                for (int j = 0; j < f; j++)
                    if (frames[j] == -1) {
                        replace = j;
                        break;
                    }

            frames[replace] = pages[i];
            faults++;
        }

        printFrames(frames, f);
    }

    printf("Total Page Faults: %d\n", faults);
}

// LRU
void lru(int pages[], int n, int f) {
    int frames[10], time[10], faults = 0, counter = 0;

    for (int i = 0; i < f; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    printf("\nLRU Page Replacement:\n");

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                time[j] = ++counter;
                break;
            }
        }

        if (!found) {
            int lru = 0;
            for (int j = 1; j < f; j++) {
                if (time[j] < time[lru])
                    lru = j;
            }
            frames[lru] = pages[i];
            time[lru] = ++counter;
            faults++;
        }

        printFrames(frames, f);
    }

    printf("Total Page Faults: %d\n", faults);
}

int main() {
    int pages[50], n, f, choice;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter the page sequence: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    printf("\nChoose Page Replacement Algorithm:\n");
    printf("1. FIFO\n2. Optimal\n3. LRU\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1: fifo(pages, n, f); break;
        case 2: optimal(pages, n, f); break;
        case 3: lru(pages, n, f); break;
        default: printf("Invalid choice.\n");
    }

    return 0;
}
