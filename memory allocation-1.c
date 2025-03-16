/**
 * The program simulates memory allocation using first fit, best fit, and worst fit strategies for
 * processes and memory blocks.
 */
#include <stdio.h>

struct process {
    int pid;
    int size;
    int blockIndex;  // Index of allocated block (-1 if not allocated)
} p[10];

struct block {
    int size;
    int remainingSize; // Tracks remaining space in block
    int allocated;
} b[10];

int bn, pn;

void display() {
    printf("\nProcess ID | Process Size | Block Allocated\n");
    for (int i = 0; i < pn; i++) {
        if (p[i].blockIndex == -1) {
            printf("%9d | %12d | Not Allocated\n", p[i].pid, p[i].size);
        } else {
            printf("%9d | %12d | %14d\n", p[i].pid, p[i].size, p[i].blockIndex + 1);
        }
    }
}

void resetBlocks() {
    for (int i = 0; i < bn; i++) {
        b[i].remainingSize = b[i].size;
        b[i].allocated = 0;
    }
    for (int i = 0; i < pn; i++) {
        p[i].blockIndex = -1;
    }
}

void firstFit() {
    printf("\nFirst Fit Allocation\n");
    resetBlocks();
    for (int i = 0; i < pn; i++) {
        for (int j = 0; j < bn; j++) {
            if (b[j].remainingSize >= p[i].size) {
                p[i].blockIndex = j;
                b[j].remainingSize -= p[i].size;
                break;
            }
        }
    }
    display();
}

void bestFit() {
    printf("\nBest Fit Allocation\n");
    resetBlocks();
    for (int i = 0; i < pn; i++) {
        int bestIdx = -1;
        for (int j = 0; j < bn; j++) {
            if (b[j].remainingSize >= p[i].size) {
                if (bestIdx == -1 || b[j].remainingSize < b[bestIdx].remainingSize) {
                    bestIdx = j;
                }
            }
        }
        if (bestIdx != -1) {
            p[i].blockIndex = bestIdx;
            b[bestIdx].remainingSize -= p[i].size;
        }
    }
    display();
}

void worstFit() {
    printf("\nWorst Fit Allocation\n");
    resetBlocks();
    for (int i = 0; i < pn; i++) {
        int worstIdx = -1;
        for (int j = 0; j < bn; j++) {
            if (b[j].remainingSize >= p[i].size) {
                if (worstIdx == -1 || b[j].remainingSize > b[worstIdx].remainingSize) {
                    worstIdx = j;
                }
            }
        }
        if (worstIdx != -1) {
            p[i].blockIndex = worstIdx;
            b[worstIdx].remainingSize -= p[i].size;
        }
    }
    display();
}

int main() {
    printf("Enter the number of memory blocks: ");
    scanf("%d", &bn);
    
    for (int i = 0; i < bn; i++) {
        printf("Enter size of block %d: ", i + 1);
        scanf("%d", &b[i].size);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &pn);
    
    for (int i = 0; i < pn; i++) {
        printf("Enter size of process %d: ", i + 1);
        scanf("%d", &p[i].size);
        p[i].pid = i + 1;
    }

    firstFit();
    bestFit();
    worstFit();
    
    return 0;
}