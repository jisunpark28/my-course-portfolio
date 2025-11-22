#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int routeTime(int, int);
int numBuses(int, int);
void printOutboundRoute(int, int, int, int);

int routeTime(int numStops, int travelTimeBetweenStops){
    int totalMin;

    totalMin = (numStops-1)*travelTimeBetweenStops*2 + (numStops-2)*2 + 35;

    return totalMin;
}

int numBuses(int routeTime, int isRegular){
    int numBus;
    if(isRegular==1){
        if(routeTime%15==0){
            numBus = routeTime/15;
        }else{
            numBus = routeTime/15 + 1;
        }
    }else{
        if(routeTime%6==0){
            numBus = routeTime/6;
        }else{
            numBus = routeTime/6 + 1;
        }
    }
    return numBus;
}

void printOutboundRoute(int startHour, int startMin, int numStops, int timeBetweenStops){
    int totalMinutes;
    int currentHour, currentMin;
    int i;

        totalMinutes = startHour*60 + startMin;

        for (i = 1; i <= numStops; i++) {
        printf("Stop %d\t", i);
        }
        printf("\n");

        for (i = 1; i <= numStops; i++) {
            currentHour = totalMinutes / 60;
            currentMin = totalMinutes % 60;
            printf("%02d:%02d\t", currentHour, currentMin);
            if (i==numStops-1){
                totalMinutes += (timeBetweenStops+5);
            }else{
                totalMinutes += (timeBetweenStops+1);
            }
    }
    printf("\n");
}

int main(){
    int numStops;
    int travelTimeBetweenStops;
    int isRegular;
    int routTimes;
    int numBus;
    int startHour = 6;
    int startMin = 0;

    printf("Enter the number of stops: ");
    scanf("%d", &numStops);
    printf("Enter the time between stops (in minutes): ");
    scanf("%d", &travelTimeBetweenStops);
    printf("Is this a regular route? (1 for yes, 0 for no): ");
    scanf("%d", &isRegular);
    printf("\n");
    routTimes = routeTime(numStops, travelTimeBetweenStops);
    numBus = numBuses(routTimes, isRegular);
    printf("The route time is: %d\n", routTimes);
    printf("Number of buses neede: %d\n\n", numBus);

    printf("Schedule\n\n");

    printOutboundRoute(startHour, startMin, numStops, travelTimeBetweenStops);

    return 0;
}