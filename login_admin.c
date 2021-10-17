#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


int main()
{
    char admins[][10] = {{"sahil"}, {"ritam"}, {"sounak"}, {"nitish"}};
    char adminPassword[][10] = {{"sahil123"}, {"ritam123"}, {"sounak123"}, {"nitish123"}};
    char username[10], enteredPassword[10];
    int i=0, flag=0;
    char choice;

    printf("\n\n\n\tEnter Admin Name:\n\n\t");
    gets(username);

    for(i; i<4; ++i)
    {
        if(strcmp(username,admins[i])==0)
        {
            flag=1;
            break;
        }
    }

    if(flag !=0)
    {
enterPass:
        system("cls");
        
		printf("\n\n\n\tAdmin:\n\n\t%s",username);
        printf("\n\n\n\tEnter Admin Password:\n\n\t");
        gets(enteredPassword);

        if(strcmp(enteredPassword, adminPassword[i]) == 0)
        {
        	printf("\n\t-------------------");
            printf("\n\tLog in successful.");
            printf("\n\t-------------------\n\n");
            printf("\t-------------------");
            printf("\n\tSelect an Option:\n");
            printf("\t-------------------\n");
            printf("\n\t1. View All Flights");
            printf("\n\t2. Add Flight");
            printf("\n\t3. Update Flight");
            printf("\n\t4. Delete Flight");
            printf("\n\t5. Search");
            printf("\n\t6. Logout");
            
            choice=getch();

    while(choice!='6')
    {
        switch(choice)
        {

        case '1':
            system("start View_Flight.exe");
            break;
        case '2':
            system("start flight_register.exe");
            break;
        case '3':
            system("start update.exe");
            break;
        case '4':
        	system("start delete.exe");
        	break;
        default:
            printf("\n\nInvalid Choice.");
            break;
        }

        choice=getch();
    }

        }

        else
        {
            printf("\n\n\tThe password you entered was incorrect.");
            printf("\n\tTry again.");
            printf("\n\n\t");
            system("pause");
            goto enterPass;
        }
    }

    else{
        printf("\n\n\tAdmin %s not found.", username);
        printf("\n\n\t");
    }
    
    printf("\n\n\n");

    system("pause");

    return 0;
}
