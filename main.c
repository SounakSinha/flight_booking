#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    char choice;

    printf("\n\n\n\t\t\tWelcome to Airline Reservation \n");
	printf("\t\t\t--------------------------------");
    printf("\n\n\t\t\tSelect an Option:\n");
    printf("\n\t\t\t1. Log in");
    printf("\n\t\t\t2. Register");
    printf("\n\t\t\t3. Log in (Admin)");
    printf("\n\t\t\t4. Quit\n");
    printf("\n\t\t\t");

    choice=getch();

    while(choice!='4')
    {
        switch(choice)
        {

        case '1':
            system("start login.exe");
            break;
        case '2':
            system("start register.exe");
            break;
        case '3':
            system("start login_admin.exe");
            break;
        }

        choice=getch();
    }

    system("cls");
    printf("\n\n\n\n\t\t\tThank you for your patronage.");
    printf("\n\n\n\t\t\t");
    system("pause");

    return 0;
}
