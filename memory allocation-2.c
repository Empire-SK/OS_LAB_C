#include <stdio.h>

#define MAX 100  // Maximum number of processes/blocks

// Function to implement First Fit
void firstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[MAX];

    for (int i = 0; i < n; i++)
        allocation[i] = -1;  // Initialize allocation array to -1

    for (int i = 0; i < n; i++) {  
        for (int j = 0; j < m; j++) {  
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];  // Reduce block size
                break;
            }
        }
    }

    // Display allocation result
    printf("\nFirst Fit Allocation:\n");
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1)
            printf("Process %d -> Block %d\n", i + 1, allocation[i] + 1);
        else
            printf("Process %d -> Not Allocated\n", i + 1);
    }
}

// Function to implement Best Fit
void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[MAX];

    for (int i = 0; i < n; i++)
        allocation[i] = -1;  

    for (int i = 0; i < n; i++) {  
        int bestIdx = -1;
        for (int j = 0; j < m; j++) {  
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx]) {
                    bestIdx = j;
                }
            }
        }

        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }

    // Display allocation result
    printf("\nBest Fit Allocation:\n");
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1)
            printf("Process %d -> Block %d\n", i + 1, allocation[i] + 1);
        else
            printf("Process %d -> Not Allocated\n", i + 1);
    }
}

// Function to implement Worst Fit
void worstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[MAX];

    for (int i = 0; i < n; i++)
        allocation[i] = -1;  

    for (int i = 0; i < n; i++) {  
        int worstIdx = -1;
        for (int j = 0; j < m; j++) {  
            if (blockSize[j] >= processSize[i]) {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx]) {
                    worstIdx = j;
                }
            }
        }

        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
        }
    }

    // Display allocation result
    printf("\nWorst Fit Allocation:\n");
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1)
            printf("Process %d -> Block %d\n", i + 1, allocation[i] + 1);
        else
            printf("Process %d -> Not Allocated\n", i + 1);
    }
}

// Main function
int main() {
    int blockSize[MAX], processSize[MAX];
    int m, n;

    // Get the number of blocks and their sizes
    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);
    printf("Enter the sizes of %d memory blocks: ", m);
    for (int i = 0; i < m; i++)
        scanf("%d", &blockSize[i]);

    // Get the number of processes and their sizes
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the sizes of %d processes: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &processSize[i]);

    // Create copies of block sizes for each algorithm
    int blockSize1[MAX], blockSize2[MAX], blockSize3[MAX];
    for (int i = 0; i < m; i++) {
        blockSize1[i] = blockSize[i];
        blockSize2[i] = blockSize[i];
        blockSize3[i] = blockSize[i];
    }

    // Perform allocations
    firstFit(blockSize1, m, processSize, n);
    bestFit(blockSize2, m, processSize, n);
    worstFit(blockSize3, m, processSize, n);

    return 0;
}