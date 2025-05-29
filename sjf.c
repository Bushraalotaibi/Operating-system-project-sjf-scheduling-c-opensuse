#include <stdio.h>

int main() {
    int n, i, j;
    int process[10], burst[10], wait[10], turn[10], temp;
    float total_wait = 0, total_turn = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burst[i]);
        process[i] = i + 1;
    }

    // Sorting processes by burst time (SJF)
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(burst[i] > burst[j]) {
                // swap burst time
                temp = burst[i];
                burst[i] = burst[j];
                burst[j] = temp;

                // swap process number
                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }

    wait[0] = 0;
    total_wait = wait[0];

    for(i = 1; i < n; i++) {
        wait[i] = wait[i - 1] + burst[i - 1];
        total_wait += wait[i];
    }

    for(i = 0; i < n; i++) {
        turn[i] = wait[i] + burst[i];
        total_turn += turn[i];
    }

    printf("\nProcess\tBurst\tWaiting\tTurnaround\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", process[i], burst[i], wait[i], turn[i]);
    }

    printf("\nAverage Waiting Time = %.2f", total_wait / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_turn / n);

    return 0;
}
