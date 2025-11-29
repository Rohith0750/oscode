#include <stdio.h>

int main() {
    int n, m;
    int alloc[10][10], request[10][10], avail[10];
    int work[10], finish[10];
    int i, j, k;
    int count = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    printf("\nEnter Allocation Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("\nEnter Request Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &request[i][j]);

    printf("\nEnter Available Resources:\n");
    for (i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    // Initialize Work = Available
    for (i = 0; i < m; i++)
        work[i] = avail[i];

    // Initialize Finish = 0
    for (i = 0; i < n; i++)
        finish[i] = 0;

    int safeSeq[10], y = 0;
    int found;

    while (count < n) {
        found = 0;

        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int canAllocate = 1;

                for (j = 0; j < m; j++) {
                    if (request[i][j] > work[j]) {
                        canAllocate = 0;
                        break;
                    }
                }

                if (canAllocate) {
                    for (k = 0; k < m; k++)
                        work[k] += alloc[i][k];

                    safeSeq[y++] = i;
                    finish[i] = 1;
                    count++;
                    found = 1;
                }
            }
        }

        if (!found)
            break;
    }

    // Check for deadlock
    int deadlock = 0;

    for (i = 0; i < n; i++) {
        if (finish[i] == 0) {
            deadlock = 1;
            break;
        }
    }

    if (deadlock) {
        printf("\nSystem is in DEADLOCK state!\n");
        printf("Deadlocked Processes: ");
        for (i = 0; i < n; i++)
            if (finish[i] == 0)
                printf("P%d ", i);
        printf("\n");
    } else {
        printf("\nSystem is in SAFE state.\n");
        printf("Safe Sequence: ");
        for (i = 0; i < n; i++)
            printf("P%d ", safeSeq[i]);
        printf("\n");
    }

    return 0;
}
