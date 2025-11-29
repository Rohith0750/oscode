#include <stdio.h>

int main() {
    int n, m; // n = number of processes, m = number of resources
    int alloc[10][10], max[10][10], avail[10];
    int need[10][10], finish[10], safeSeq[10];
    int i, j, k, count = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    printf("\nEnter Allocation Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("\nEnter Maximum Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("\nEnter Available Resources:\n");
    for (i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    // Calculate Need matrix = Max - Allocation
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Initialize finish flags
    for (i = 0; i < n; i++)
        finish[i] = 0;

    printf("\nNeed Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            printf("%d ", need[i][j]);
        printf("\n");
    }

    int y = 0;

    // Safety Algorithm
    while (count < n) {
        int found = 0;

        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {  // Not yet allocated in safe sequence
                int flag = 0;

                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0) {
                    // Resources can be allocated
                    for (k = 0; k < m; k++)
                        avail[k] += alloc[i][k];

                    safeSeq[y++] = i;
                    finish[i] = 1;
                    count++;
                    found = 1;
                }
            }
        }

        if (found == 0) {
            printf("\nSystem is in an UNSAFE state — Deadlock may occur!\n");
            return 0;
        }
    }

    printf("\nSystem is in a SAFE state.\nSafe Sequence: ");
    for (i = 0; i < n; i++)
        printf("P%d ", safeSeq[i]);

    printf("\n");

    return 0;
}
