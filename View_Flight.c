#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct flight
{
    char id[30];
    char from[30];
    char to[30];
    char day[30];
    char time[30];
    int distance;
    int seats;
    int booked;
};

int main()
{
	struct flight readflight;
	
    FILE *fptr;
    fptr = fopen("flight.dat", "r");
    
    char id[20] = "Flight-ID";
    char from[20] = "Arrival";
    char to[20] = "Destination";
    char day[20] = "Day of Flight";
    char time[20] = "Time of Flight";
    char seats[20] = "Seats";
    char booked[20] = "Booked Seats";
    char distance[20] = "Distance(km)";

    printf("\n\n\n All Flights : \n");
    printf("------------------------------------------------------------------------------------------------------------------------------------");
    printf("\n %-10s%-20s%-20s%-20s%-20s%-15s%-10s%-10s \n",id,from,to,day,time,distance,seats,booked);
    printf("------------------------------------------------------------------------------------------------------------------------------------");

    while(fread(&readflight, sizeof(struct flight), 1, fptr))
    {
        printf("\n\n %-10s%-20s%-20s%-20s%-20s%-15d%-10d%-10d", readflight.id,readflight.from,readflight.to,readflight.day,readflight.time,readflight.distance,readflight.seats, readflight.booked);
    }
	
	printf("\n\n\n");

    system("pause");

    fclose(fptr);

    return 0;
}
