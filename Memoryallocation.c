#include <stdio.h>

int main() {
    int p[10], np, b[10], nb, ch;
    int bf[10], wf[10], ff[10];   // copies for best, worst, first fit
    int flag[10], i, j;

    printf("\nEnter the number of processes: ");
    scanf("%d", &np);

    printf("\nEnter the number of memory blocks: ");
    scanf("%d", &nb);

    printf("\nEnter the size of each process:\n");
    for (i = 0; i < np; i++) {
        printf("Process %d: ", i);
        scanf("%d", &p[i]);
        flag[i] = 0;  // initialize
    }

    printf("\nEnter the size of each memory block:\n");
    for (j = 0; j < nb; j++) {
        printf("Block %d: ", j);
        scanf("%d", &b[j]);
        ff[j] = b[j];
        bf[j] = b[j];
        wf[j] = b[j];
    }

    printf("\n------ MEMORY ALLOCATION MENU ------");
    printf("\n1. First Fit");
    printf("\n2. Best Fit");
    printf("\n3. Worst Fit");
    printf("\n4. Exit");

    do {
        printf("\n\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {

        // -----------------------------------------------------------
        case 1:
            printf("\n----- FIRST FIT -----\n");

            for (i = 0; i < np; i++) {
                int allocated = 0;

                for (j = 0; j < nb; j++) {
                    if (p[i] <= ff[j] && ff[j] != 0) {
                        printf("Process %d of size %d allocated to Block %d of size %d\n",
                               i, p[i], j, ff[j]);
                        ff[j] = 0;   // mark allocated
                        allocated = 1;
                        break;
                    }
                }
                if (!allocated)
                    printf("Process %d of size %d is NOT allocated\n", i, p[i]);
            }
            break;

        // -----------------------------------------------------------
        case 2:
            printf("\n----- BEST FIT -----\n");

            // Sort blocks in ASCENDING order
            for (i = 0; i < nb; i++) {
                for (j = i + 1; j < nb; j++) {
                    if (bf[i] > bf[j]) {
                        int temp = bf[i];
                        bf[i] = bf[j];
                        bf[j] = temp;
                    }
                }
            }

            for (i = 0; i < np; i++) {
                int allocated = 0;

                for (j = 0; j < nb; j++) {
                    if (p[i] <= bf[j] && bf[j] != 0) {
                        printf("Process %d of size %d allocated to Block %d of size %d\n",
                               i, p[i], j, bf[j]);
                        bf[j] = 0;   // allocate
                        allocated = 1;
                        break;
                    }
                }

                if (!allocated)
                    printf("Process %d of size %d is NOT allocated\n", i, p[i]);
            }
            break;

        // -----------------------------------------------------------
        case 3:
            printf("\n----- WORST FIT -----\n");

            // Sort blocks in DESCENDING order
            for (i = 0; i < nb; i++) {
                for (j = i + 1; j < nb; j++) {
                    if (wf[i] < wf[j]) {
                        int temp = wf[i];
                        wf[i] = wf[j];
                        wf[j] = temp;
                    }
                }
            }

            for (i = 0; i < np; i++) {
                int allocated = 0;

                for (j = 0; j < nb; j++) {
                    if (p[i] <= wf[j] && wf[j] != 0) {
                        printf("Process %d of size %d allocated to Block %d of size %d\n",
                               i, p[i], j, wf[j]);
                        wf[j] = 0;
                        allocated = 1;
                        break;
                    }
                }

                if (!allocated)
                    printf("Process %d of size %d is NOT allocated\n", i, p[i]);
            }
            break;

        // -----------------------------------------------------------
        case 4:
            printf("\nExiting...\n");
            break;

        default:
            printf("\nInvalid Choice! Try again.\n");
        }

    } while (ch >= 1 && ch <= 3);

    return 0;
}
