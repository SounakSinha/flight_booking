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
    FILE *fptr;
    fptr = fopen("flight.dat", "ab+");
    struct flight readflight;
    struct flight newflight;
    char id[30], from[30], to[30], day[30], time[30];
    char id1[20] = "Flight-ID";
    char from1[20] = "Arrival";
    char to1[20] = "Destination";
    char day1[20] = "Day of Flight";
    char time1[20] = "Time of Flight";
    char seats1[20] = "Seats";
    char booked1[20] = "Booked Seats";
    char distance1[20] = "Distance(km)";
    int seats,distance;

	
start:
    printf("\n\n\n\tEnter New Flight ID : \n\n\t\t\t");
    gets(id);

    fseek(fptr, 0, SEEK_SET);
    while(fread(&readflight, sizeof(struct flight), 1, fptr))
    {
        if(strcmp(id, readflight.id) == 0)
        {
            printf("\n\n\n\t\tID occupied. Please try again.  \n\n\t\tPress any key to continue...");
            getch();
            system("cls");
            goto start;
        }
    }

    strcpy(newflight.id,id);

    printf("\n\tEnter Start Location:\n\n\t\t\t");
    gets(from);
    strcpy(newflight.from, from);
    printf("\n\tEnter Destination:\n\n\t\t\t");
    gets(to);
    strcpy(newflight.to, to);
     printf("\n\tEnter Day of Flight:\n\n\t\t\t");
    gets(day);
    strcpy(newflight.day, day);
    printf("\n\tEnter Time of Flight:\n\n\t\t\t");
    gets(time);
    strcpy(newflight.time, time);
    printf("\n\tEnter Flight Distance:\n\n\t\t\t");
    scanf("%d",&distance);
    newflight.distance = distance;
    printf("\n\tEnter Seats:\n\n\t\t\t");
    scanf("%d",&seats);
    newflight.seats =  seats;
    newflight.booked = 0;

    fwrite(&newflight, sizeof(struct flight), 1, fptr);

    printf("\n\n\tFlight registered successfully.\n\n");
    printf("\t-------------------------------------------------------------------------------------------------------------------------");
    printf("\n\t %-12s%-15s%-15s%-15s%-15s%-15s%-10s%-10s \n",id1,from1,to1,day1,time1,distance1,seats1,booked1);
    printf("\t-------------------------------------------------------------------------------------------------------------------------");
    printf("\n\n\t %-12s%-15s%-15s%-15s%-15s%-15d%-10d%-10d",newflight.id,newflight.from,newflight.to,newflight.day,newflight.time,newflight.distance,newflight.seats,newflight.booked);
    printf("\n\n\n\t");
	system("pause");

    fclose(fptr);

    return 0;
}
