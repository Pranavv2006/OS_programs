#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void fcfs(int n, int bt[]) {
    int wt[MAX], tat[MAX], total_wt = 0, total_tat = 0;
    wt[0] = 0;  // first process has zero waiting time :contentReference[oaicite:5]{index=5}
    for(int i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];  // cumulative burst sum :contentReference[oaicite:6]{index=6}

    for(int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        total_wt += wt[i];
        total_tat += tat[i];
        printf("P%d\t%3d\t%3d\t%3d\n", i+1, bt[i], wt[i], tat[i]);
    }

    printf("Avg WT=%.2f\tAvg TAT=%.2f\n\n",
           (float)total_wt/n, (float)total_tat/n);
}

void roundRobin(int n, int bt[], int tq) {
    int rt[MAX], wt[MAX]={0}, tat[MAX]={0};
    int t = 0, rem = n;

    for(int i = 0; i < n; i++)
        rt[i] = bt[i];  // remaining times :contentReference[oaicite:7]{index=7}

    printf("P#\tBurst\tWT\tTAT\n");
    while(rem) {
        for(int i = 0; i < n; i++) {
            if(rt[i] > 0) {
                int exec = (rt[i] > tq) ? tq : rt[i];
                t += exec;
                rt[i] -= exec;
                if(rt[i] == 0) {
                    tat[i] = t;           // completion time :contentReference[oaicite:8]{index=8}
                    wt[i]  = tat[i] - bt[i];
                    rem--;
                    printf("P%d\t%3d\t%3d\t%3d\n",
                           i+1, bt[i], wt[i], tat[i]);
                }
            }
        }
    }
    float total_wt=0, total_tat=0;
    for(int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }
    printf("Avg WT=%.2f\tAvg TAT=%.2f\n\n",
           total_wt/n, total_tat/n);
}

int main() {
    int n, choice, tq;
    int bt[MAX];

    printf("Enter no. of processes: ");
    scanf("%d", &n);

    printf("Enter burst times:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &bt[i]);

    printf("Select algorithm:\n1.FCFS\n2.Round Robin\nChoice: ");
    scanf("%d", &choice);

    if(choice == 1) {
        printf("\nFCFS Scheduling:\nP#\tBurst\tWT\tTAT\n");
        fcfs(n, bt);  // non-preemptive FCFS :contentReference[oaicite:9]{index=9}
    } else if(choice == 2) {
        printf("Enter time quantum: ");
        scanf("%d", &tq);
        printf("\nRound Robin Scheduling:\n");
        roundRobin(n, bt, tq);  // preemptive RR :contentReference[oaicite:10]{index=10}
    } else {
        printf("Invalid choice\n");
    }
    return 0;
}