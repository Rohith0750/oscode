#include <stdio.h>

int main() {
    int i, j, k;
    int f, pf = 0, count = 0;
    int rs[25], m[10], n;

    printf("\nEnter the length of reference string: ");
    scanf("%d", &n);

    printf("Enter the reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &rs[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Initialize frame array with -1 (empty)
    for (i = 0; i < f; i++)
        m[i] = -1;

    printf("\nThe Page Replacement Process is:\n");

    for (i = 0; i < n; i++) {

        // Check if page already exists in frame
        for (k = 0; k < f; k++) {
            if (m[k] == rs[i])
                break;
        }

        // If not found, replace oldest page (FIFO)
        if (k == f) {
            m[count] = rs[i];
            count = (count + 1) % f;   // circular FIFO
            pf++;
        }

        // Print frames
        for (j = 0; j < f; j++) {
            if (m[j] == -1)
                printf("\t-");
            else
                printf("\t%d", m[j]);
        }

        if (k == f)
            printf("\tPF No. %d", pf);

        printf("\n");
    }

    printf("\nTotal Page Faults using FIFO = %d\n", pf);

    return 0;
}
