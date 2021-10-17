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
	
	int flag=0;
    FILE *fptr;
    FILE *buff;;
    fptr = fopen("flight.dat","r");
    buff = fopen("buffer.dat","w+");
    char del[10];
    
    printf("\n\n\n\tEnter ID of Flight to Remove: \n\n\t");
    gets(del);

    while(fread(&readflight, sizeof(struct flight), 1, fptr))
    {
     	if(strcmp(del,readflight.id)==0)
		{
			flag = 1;
			continue; 	
		}   
		fwrite(&readflight, sizeof(struct flight), 1, buff);
	}
	
	if(flag==0)
	{
		printf("\n\n\n\tNo such Flight.");
	}
	else
	{
		printf("\n\n\n\tDeleted.");
	}
	
	fclose(fptr);
    fclose(buff);
    
    FILE *fptr1;
    FILE *buff1;
    fptr1 = fopen("flight.dat","w+");
    buff1 = fopen("buffer.dat","r");
    
    while(fread(&readflight, sizeof(struct flight), 1, buff1))
    {
		fwrite(&readflight, sizeof(struct flight), 1, fptr1);
	}
	
	fclose(fptr1);
    fclose(buff1);
	
	
	
	printf("\n\n\n");

    system("pause");

    
    
	
    return 0;
}
