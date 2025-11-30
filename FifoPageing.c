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
-------------------------------------------------------------------------------------------------------------------


LRU PAGE REPLACEMENT:

#include <stdio.h>
int main()
{
 int i, j, k, min, rs[25], m[10], count[10], flag[25], n, f, pf = 0, next = 1;
 // clrscr(); <-- Removed (not needed)
 printf("Enter the length of reference string -- ");
 scanf("%d", &n);
 printf("Enter the reference string -- ");
 for (i = 0; i < n; i++)
 {
 scanf("%d", &rs[i]);
 flag[i] = 0;
 }
 printf("Enter the number of frames -- ");
 scanf("%d", &f);
 for (i = 0; i < f; i++)
 {
 count[i] = 0;
 m[i] = -1;
 }
 printf("\nThe Page Replacement process is -- \n");
 for (i = 0; i < n; i++)
 {
 // check if page already exists
 for (j = 0; j < f; j++)
 {
 if (m[j] == rs[i])
 {
 flag[i] = 1;
 count[j] = next;
 next++;
 break; // stop checking once found
 }
 }
 if (flag[i] == 0)
 {
 // if frame not full yet
 if (i < f)
 {
 m[i] = rs[i];
 count[i] = next;
 next++;
 }
 else
 {
 // find least recently used page
 min = 0;
 for (j = 1; j < f; j++)
 {
 if (count[min] > count[j])
 min = j;
 }
 m[min] = rs[i];
 count[min] = next;
 next++;
 }
 pf++;
 }
 // print current frame status
 for (j = 0; j < f; j++)
 printf("%d\t", m[j]);
 if (flag[i] == 0)
 printf("PF No. -- %d", pf);
 printf("\n");
 }
 printf("\nThe number of page faults using LRU are %d\n", pf);
 // getch(); <-- Removed (not needed)
 return 0;
}
-------------------------------------------------------------------------------------------------------
LFU PAGE REPLACEMENT:

#include <stdio.h>
int main()
{
 int rs[50], i, j, k, m, f, cntr[20], a[20], min, pf = 0;
 printf("\nEnter number of page references -- ");
 scanf("%d", &m);
 printf("\nEnter the reference string -- ");
 for (i = 0; i < m; i++)
 scanf("%d", &rs[i]);
 printf("\nEnter the available no. of frames -- ");
 scanf("%d", &f);
 for (i = 0; i < f; i++)
 {
 cntr[i] = 0;
 a[i] = -1;
 }
 printf("\nThe Page Replacement Process is -- \n");
 for (i = 0; i < m; i++)
 {
 int flag = 0;
 // Check if page already in frame
 for (j = 0; j < f; j++)
 {
 if (rs[i] == a[j])
 {
 cntr[j]++; // increase usage count
 flag = 1; // page found (no fault)
 break;
 }
 }
 // If not found (page fault)
 if (flag == 0)
 {
 int empty = -1;
 // check for an empty frame
 for (j = 0; j < f; j++)
 {
 if (a[j] == -1)
 {
 empty = j;
 break;
 }
 }
 if (empty != -1)
 {
 a[empty] = rs[i];
 cntr[empty] = 1;
 }
 else
 {
 // find least frequently used page
 min = 0;
 for (k = 1; k < f; k++)
 {
 if (cntr[k] < cntr[min])
 min = k;
 }
 a[min] = rs[i];
 cntr[min] = 1;
 }
 pf++;
 }
 // Print frame contents after each reference
 printf("\n");
 for (j = 0; j < f; j++)
 printf("\t%d", a[j]);
 if (flag == 0)
 printf("\tPF No. %d", pf);
 }
 printf("\n\nTotal number of page faults -- %d\n", pf);
 return 0;
}
