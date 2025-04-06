#include <stdio.h>
#include <stdlib.h>

void fifo(int pages[], int n, int f)
{
    if (f > 10)
    {
        printf("Error: Frame size too large!\n");
        return;
    }
    int frame[10], i, j, k = 0, flag, pageFaults = 0;
    for (i = 0; i < f; i++)
        frame[i] = -1;

    printf("\nFIFO Page Replacement\n");
    for (i = 0; i < n; i++)
    {
        flag = 1;
        for (j = 0; j < f; j++)
        {
            if (frame[j] == pages[i])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            frame[k] = pages[i];
            k = (k + 1) % f;
            pageFaults++;
        }
        printf("Frames: ");
        for (j = 0; j < f; j++)
            frame[j] != -1 ? printf("%d ", frame[j]) : printf("- ");
        printf("\n");
    }
    printf("Total Page Faults: %d\n", pageFaults);
}

void optimal(int pages[], int n, int f)
{
    if (f > 10)
    {
        printf("Error: Frame size too large!\n");
        return;
    }
    int frame[10], i, j, k, pageFaults = 0;
    int future[10], index, farthest;

    for (i = 0; i < f; i++)
        frame[i] = -1;

    printf("\nOptimal Page Replacement\n");
    for (i = 0; i < n; i++)
    {
        int flag = 0;
        for (j = 0; j < f; j++)
        {
            if (frame[j] == pages[i])
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            if (i < f)
            {
                frame[i] = pages[i];
            }
            else
            {
                for (j = 0; j < f; j++)
                {
                    future[j] = -1;
                    for (k = i + 1; k < n; k++)
                    {
                        if (frame[j] == pages[k])
                        {
                            future[j] = k;
                            break;
                        }
                    }
                }
                farthest = -1;
                index = -1;
                for (j = 0; j < f; j++)
                {
                    if (future[j] == -1)
                    {
                        index = j;
                        break;
                    }
                    if (future[j] > farthest)
                    {
                        farthest = future[j];
                        index = j;
                    }
                }
                frame[index] = pages[i];
            }
            pageFaults++;
        }
        printf("Frames: ");
        for (j = 0; j < f; j++)
            frame[j] != -1 ? printf("%d ", frame[j]) : printf("- ");
        printf("\n");
    }
    printf("Total Page Faults: %d\n", pageFaults);
}

void lfu(int pages[], int n, int f)
{
    if (f > 10)
    {
        printf("Error: Frame size too large!\n");
        return;
    }
    int frame[10], count[10] = {0}, time[10] = {0};
    int i, j, temp, flag, least, minTime, hit = 0;

    for (i = 0; i < f; i++)
        frame[i] = -1;

    printf("\nLFU Page Replacement\n");
    for (i = 0; i < n; i++)
    {
        flag = 1;
        int foundIndex = -1;
        for (j = 0; j < f; j++)
        {
            if (frame[j] == pages[i])
            {
                hit++;
                count[j]++;
                time[j] = i;
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            int emptyFrame = -1;
            for (j = 0; j < f; j++)
            {
                if (frame[j] == -1)
                {
                    emptyFrame = j;
                    break;
                }
            }
            if (emptyFrame != -1)
            {
                frame[emptyFrame] = pages[i];
                count[emptyFrame] = 1;
                time[emptyFrame] = i;
            }
            else
            {
                least = 0;
                minTime = time[0];
                for (j = 1; j < f; j++)
                {
                    if (count[j] < count[least] || (count[j] == count[least] && time[j] < minTime))
                    {
                        least = j;
                        minTime = time[j];
                    }
                }
                frame[least] = pages[i];
                count[least] = 1;
                time[least] = i;
            }
        }
        printf("Frames: ");
        for (j = 0; j < f; j++)
            frame[j] != -1 ? printf("%d ", frame[j]) : printf("- ");
        printf("\n");
    }
    printf("Total Page Hits: %d\n", hit);
    printf("Total Page Faults: %d\n", n - hit);
}

int main()
{
    int n, f, choice, i;
    int pages[50];

    printf("Enter number of pages: ");
    scanf("%d", &n);
    if (n > 50)
    {
        printf("Error: Too many pages!\n");
        return 1;
    }

    printf("Enter page numbers: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);
    if (f > 10)
    {
        printf("Error: Frame size too large!\n");
        return 1;
    }

    while (1)
    {
        printf("Choose the algorithm:\n1. FIFO\n2. Optimal\n3. LFU\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            fifo(pages, n, f);
            break;
        case 2:
            optimal(pages, n, f);
            break;
        case 3:
            lfu(pages, n, f);
            break;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
