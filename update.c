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
	struct flight newflight;
	
	int flag=0;
    FILE *fptr;
    FILE *buff;;
    fptr = fopen("flight.dat","r");
    buff = fopen("buffer2.dat","w+");
    char ident[10],variable[10];
    int seat,choice;
    
    printf("\n\n\n\tEnter ID of Flight to Update: \n\n\t");
    gets(ident);
    
    printf("\n\n\t Choose Option: \n\n\t");
    printf("1.Change Day \n\n\t");
    printf("2.Change Time \n\n\t");
    printf("3.Add/Remove Seats\n\n\t");
    scanf("%d",&choice);
    
    switch(choice){
    	case 1:
    		printf("\n\n\tEnter New Day of Flight: ");
    		scanf("%s",&variable);
    		while(fread(&readflight, sizeof(struct flight), 1, fptr))
   			{
   				newflight = readflight;
     			if(strcmp(ident,readflight.id)==0)
				{
					strcpy(newflight.day, variable);
					flag = 1; 	
				}   
				fwrite(&newflight, sizeof(struct flight), 1, buff);
			}
			break;
		case 2:
    		printf("\n\n\tEnter New Time of Flight: ");
    		scanf("%s",&variable);
    		while(fread(&readflight, sizeof(struct flight), 1, fptr))
   			{
   				newflight = readflight;
     			if(strcmp(ident,readflight.id)==0)
				{
					strcpy(newflight.time, variable);
					flag = 1;	
				}   
				fwrite(&newflight, sizeof(struct flight), 1, buff);
			}
			break;
		case 3:
    		printf("\n\n\tAdd(+)/Remove(-) Seats in Flight: ");
    		scanf("%d",&seat);
    		while(fread(&readflight, sizeof(struct flight), 1, fptr))
   			{
   				newflight = readflight;
     			if(strcmp(ident,readflight.id)==0)
				{
					if(newflight.seats>=newflight.booked)
					{
						newflight.seats = readflight.seats + seat;
						flag = 1;
					}
				}   
				fwrite(&newflight, sizeof(struct flight), 1, buff);
			}
			break;
		default:
			printf("Wrong Choice.");
			break;
    		
	}
	

    while(fread(&readflight, sizeof(struct flight), 1, fptr))
    {
     	if(strcmp(ident,readflight.id)==0)
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
		printf("\n\n\n\tUpdated.");
	}
	
	fclose(fptr);
    fclose(buff);
    
    FILE *fptr1;
    FILE *buff1;
    fptr1 = fopen("flight.dat","w+");
    buff1 = fopen("buffer2.dat","r");
    
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
