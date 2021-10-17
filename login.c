#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


struct userDetails
{
    char name[30];
    char password[30];
};


int main()
{
    FILE *fptr;
    fptr = fopen("users.dat", "r");
    struct userDetails readUser;
    char name[30], password[30];
    int flag = 0;
    char choice;

    printf("\n\n\n\tEnter Username:\n\n\t");
    gets(name);

    while(fread(&readUser, sizeof(struct userDetails), 1, fptr))
    {
        if(strcmp(name, readUser.name) == 0)
        {
            /*This block checks whether the entered username is valid or not*/
            flag=1;
            break;
        }
    }
    

    if(flag != 0)
    {
        /*This block asks for password if the username exists*/
enterPass:
        system("cls");
		printf("\n\n\n\tUsername:\n\n\t%s",name);
        printf("\n\n\tEnter Password:\n\n\t");
        gets(password);

        if(strcmp(password, readUser.password) == 0)
        {
            /*If the username and password correct user is logged in*/
            printf("\n\t-------------------");
            printf("\n\tLog in successful.\n");
            printf("\t-------------------\n\n");
            printf("\t-------------------");
            printf("\n\tSelect an Option:\n");
            printf("\t-------------------\n");

            FILE *fptr1;
            fptr1 = fopen("curUser","w");
            fputs(readUser.name,fptr1);
            fclose(fptr1);
            
   			printf("\n\t1. Book Flight");
    		printf("\n\t2. Cancel Flight");
    		printf("\n\t3. View Flights");
    		printf("\n\t4. Logout\n");
    		printf("\n\t");

    choice=getch();

    while(choice!='4')
    {
        switch(choice)
        {

        case '1':
            system("start book_flight.exe");
            break;
        case '2':
            //system("start cancel_flight.exe");
            break;
        case '3':
            system("start View_Flight.exe");
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
            goto enterPass; //If entered password is incorrect sends program back to ask password.
        }
    }

    else
    {
        printf("\n\n\tUser not found.\n\n\t"); //If username is not found in database, gives a prompt to user.
    }

    system("pause");

    fclose(fptr);

    return 0;
}
