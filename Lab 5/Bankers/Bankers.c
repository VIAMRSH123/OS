#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, m, i, j, k;
    printf("Enter the number of processes and resources: ");
    scanf("%d %d", &n, &m);

    int alloc[n][m], max[n][m], need[n][m], avail[m];

    printf("Enter the Allocation Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter the Max Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Calculating Need Matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    printf("Enter the Available Resources:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
    }

    bool finish[n];
    int safeSeq[n];
    int count = 0;

    for (i = 0; i < n; i++) {
        finish[i] = false;
    }

    while (count < n) {
        bool found = false;
        for (i = 0; i < n; i++) {
            if (!finish[i]) {
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        break;
                    }
                }

                if (j == m) {
                    // Allocate the resources back to available
                    for (k = 0; k < m; k++) {
                        avail[k] += alloc[i][k];
                    }

                    // Update status
                    safeSeq[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }

        if (!found) {
            printf("System is not in a safe state!\n");
            return 0;  // Exit the program early
        }
    }

    printf("System is in a safe state!\n");
    printf("Safe Sequence: ");
    for (i = 0; i < n; i++) {
        printf("P%d", safeSeq[i]);
        if (i != n - 1)
            printf(" --> ");
    }
    printf("\n");

    return 0;
}
