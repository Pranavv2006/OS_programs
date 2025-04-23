#include <stdio.h>
#include <stdlib.h>

void fcfs(int disk[], int n, int head) {
    int distance = 0;
    for (int i = 0; i < n; i++) {
        distance += abs(disk[i] - head);
        head = disk[i];
    }
    printf("Total head movement in FCFS: %d\n", distance);
}

int main() {
    int n, head, max;
    printf("Enter the number of requests: ");
    scanf("%d", &n);

    int disk[n];
    printf("Enter the requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &disk[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Enter the maximum disk size: ");
    scanf("%d", &max); 

    fcfs(disk, n, head);

    return 0;
}
