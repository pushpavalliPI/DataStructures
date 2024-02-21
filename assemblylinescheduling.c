#include <stdio.h> 
#define NUM_LINE 2 
#define NUM_STATION 3 
int min(int a, int b) 
{ 
    return (a < b) ? a : b;
} 
void printSchedule(int schedule[][NUM_STATION], int lastStation, int line)
{
    if (lastStation == 0)
    {
        printf("Station %d", lastStation + 1);
    }
    else
    {
        printSchedule(schedule, lastStation - 1, schedule[line][lastStation]);
        printf(" -> Station %d", lastStation + 1);
    }
}
int Assembly(int a[][NUM_STATION], int t[][NUM_STATION], int *e, int *x) 
{ 
    int T1[NUM_STATION], T2[NUM_STATION], i; 
    int schedule[NUM_LINE][NUM_STATION];

    T1[0] = e[0] + a[0][0]; 
    T2[0] = e[1] + a[1][0]; 
    for (i = 1; i < NUM_STATION; ++i) 
    { 
        if ((T1[i-1] + a[0][i]) <= (T2[i-1] + t[1][i] + a[0][i]))
        {
            T1[i] = T1[i-1] + a[0][i];
            schedule[0][i] = 0; 
        }
        else
        {
            T1[i] = T2[i-1] + t[1][i] + a[0][i];
            schedule[0][i] = 1;
		}

        if ((T2[i-1] + a[1][i]) <= (T1[i-1] + t[0][i] + a[1][i]))
        {
            T2[i] = T2[i-1] + a[1][i];
            schedule[1][i] = 1;
		}
        else
        {
            T2[i] = T1[i-1] + t[0][i] + a[1][i];
            schedule[1][i] = 0; 
        }
    }
    printf("Schedule for Line 1: ");
    printSchedule(schedule, NUM_STATION - 1, 0);
    printf("\n");

    printf("Schedule for Line 2: ");
    printSchedule(schedule, NUM_STATION - 1, 1);
    printf("\n");

    return min(T1[NUM_STATION-1] + x[0], T2[NUM_STATION-1] + x[1]); 
} 
int main() 
{ 
    int a[][NUM_STATION] = {{10,4,7}, 
                {7,6,8}}; 
    int t[][NUM_STATION] = {{0, 3,3}, 
                {0, 1,2}}; 
    int e[] = {4,5}, x[] = {6,5}; 
    printf("Minimum time: %d\n", Assembly(a, t, e, x)); 
    return 0; 
}