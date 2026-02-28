#include<stdio.h>
int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    char PID[n][12];
    int AT[n], BT[n], CT[n], TAT[n], WT[n], RT[n];

    // Input
    printf("\nEnter PID, AT, BT consecutively:\n");
    for(int i=0; i<n; i++){
        scanf("%s%d%d", PID[i], &AT[i], &BT[i]);
    }
   int CPU_time = 0;

    for(int i=0; i<n; i++)
    {
        if(CPU_time < AT[i])
        {
            CPU_time = AT[i];
        }

        CT[i] = CPU_time + BT[i];

        TAT[i] = CT[i] - AT[i];

        WT[i] = TAT[i] - BT[i];

        RT[i] = WT[i];


        CPU_time = CT[i];
    }

    printf("\n\n---------------------------------------------------");

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(int i = 0; i < n; i++)
    {
        printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\n", PID[i], AT[i], BT[i], CT[i], TAT[i], WT[i], RT[i]);
    }

    printf("---------------------------------------------------\n");
}




