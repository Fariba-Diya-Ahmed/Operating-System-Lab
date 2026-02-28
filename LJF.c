#include <stdio.h>
#include <limits.h>

int main()
{
    printf("Enter number of processes: ");
    int n;
    scanf("%d", &n);

    char pid[n][10];
    int at[n],bt[n],ct[n],tat[n],wt[n],rt[n];
    int completed = 0, cpu_time = 0;
    int finished_process[n];

    printf("Enter PID, AT and BT respectively:\n");
    for(int i=0; i<n; i++)
    {
        scanf("%s%d%d", pid[i], &at[i], &bt[i]);
        finished_process[i] = 0;
    }

    while (completed != n)
    {
        int index = -1;
        int max_bt = INT_MIN;

        for(int i=0; i<n; i++)
        {
            if(at[i] <= cpu_time && finished_process[i] == 0)
            {
                if(bt[i] > max_bt || (bt[i] == max_bt && at[i] < at[index]))
                {
                    max_bt = bt[i];
                    index = i;
                }
            }
        }

        if(index == -1)
        {
            cpu_time++;
        }
        else
        {
            cpu_time += bt[index];
            ct[index] = cpu_time;

            tat[index] = ct[index] - at[index];
            wt[index] = tat[index] - bt[index];
            rt[index] = wt[index];

            finished_process[index] = 1;
            completed++ ;
        }
    }

    printf("\n---------------------------------------------------");

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i], rt[i]);
    }

    printf("---------------------------------------------------\n");
}