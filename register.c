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
    fptr = fopen("users.dat", "ab+");
    struct userDetails readUser;
    struct userDetails newUser;
    char name[30], password[30];

start:
    printf("\n\n\n\tEnter Username (should not contain white spaces):\n\n\t");
    gets(name);

    fseek(fptr, 0, SEEK_SET);
    while(fread(&readUser, sizeof(struct userDetails), 1, fptr))
    {
        if(strcmp(name, readUser.name) == 0)
        {
            printf("\n\n\n\tUsername already chosen. Please try again.  \n\n\t\tPress any key to continue...");
            getch();
            system("cls");
            goto start;
        }
    }

    strcpy(newUser.name,name);

    printf("\n\tEnter Password to Register:\n\n\t");
    gets(password);
    strcpy(newUser.password, password);

    fwrite(&newUser, sizeof(struct userDetails), 1, fptr);

	printf("\n\n\t-----------------------------------------------");
    printf("\n\tUser registered successfully, you can now login.\n");
    printf("\t-----------------------------------------------\n\n\n");
    system("pause");

    fclose(fptr);

    return 0;
}
