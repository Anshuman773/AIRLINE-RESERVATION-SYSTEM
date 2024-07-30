#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>

struct passappa_airline
{
    char passport[8];
    char name[20];
    int seat_num;
    char email[30];
    struct passappa_airline *following;
}
    *begin,
    *stream;
struct passappa_airline *dummy;

void main()
{
    void reserve(int x), cancel(), display(), savefile(); // function prototypes
    int choice;
    begin = stream = NULL; // initialize the struct pointers to NULL
    int num = 1;
    do
    {

        printf("\n\n\t\t ********************************************************************");
        printf("\n\t\t                   Welcome to PASSAPPA airline system                   ");
        printf("\n\n\t\t ********************************************************************");
        printf("\n\n\n\t\t Please enter your choice from below (1-4):");
        printf("\n\n\t\t 1. Reservation");
        printf("\n\n\t\t 2. Cancel");
        printf("\n\n\t\t 3. Display Records");
        printf("\n\n\t\t 4. Exit");
        printf("\n\n\t\t Feel free to ask us");
        printf("\n\n\t\t Enter your choice : ");

        scanf("%d", &choice);
        fflush(stdin);
        system("cls");
        switch (choice)
        {
        case 1:
            reserve(num);
            num++;
            break;
        case 2:
            cancel();
            break;
        case 3:
            display();
            break;
        case 4:
        {
            savefile();
            break;
        }
        default:
            printf("\n\n\t SORRY INVALID CHOICE!");
            printf("\n\n\t PLEASE CHOOSE FROM 1-4");
            printf("\n\n\t Do not forget to choose from 1-4");
        }
        getch();
    } while (choice != 4);
}
// ***********************GOOD LUCK PASSAPPA PASSENGERS****************************
void details()
{
    printf("\n\t Enter your passport number : ");
    gets(stream->passport);
    fflush(stdin); // reads a line from stdin and stores it into the string pointed
    printf("\n\t Enter your name :");
    gets(stream->name);
    fflush(stdin);
    printf("\n\t Enter your email address :");
    gets(stream->email);
    fflush(stdin);
}

// ************************GOOD LUCK PASSAPPA PASSENGERS****************************
void details();

void reserve(int x)
{
    stream = begin;
    if (begin == NULL)
    {
        // first user
        begin = stream = (struct passappa_airline *)malloc(sizeof(struct passappa_airline));
        details();
        stream->following = NULL;
        printf("\n\t Seat booking successful!");
        printf("\n\t Your seat number is : Seat A-%d", x);
        stream->seat_num = x;
        return;
    }
    else if (x > 15) // FULL SEATS
    {
        printf("\n\t\t Seat Full.");
        return;
    }
    else
    {
        // next user
        while (stream->following)
            stream = stream->following;
        stream->following = (struct passappa_airline *)malloc(sizeof(struct passappa_airline));
        stream = stream->following;
        details();
        stream->following = NULL;
        printf("\n\t Congratulations!!!! Your seat is successfully booked!");
        printf("\n\t Your seat number is: Seat A-%d", x);
        stream->seat_num = x;
        return;
    }
}
// ***********************GOOD LUCK PASSAPPA*******************************

void savefile()
{
    FILE *fpointer = fopen("passappa records", "w");
    if (!fpointer)
    {
        printf("\n Error in opening file!");
        return;
        Sleep(800);
    }
    stream = begin;
    while (stream)
    {
        fprintf(fpointer, "%-8s", stream->passport);
        fprintf(fpointer, "%-20s", stream->name);
        fprintf(fpointer, "%-20s", stream->email);
        stream = stream->following;
    }
    printf("\n\n\t Details have been saved to a file (passappa records)");
    fclose(fpointer);
}
//****************************GOOD LUCK PASSAPPA****************************

void display()
{
    stream = begin;
    while (stream)
    {
        printf("\n\n*===================!!!!HAPPY JOURNEY!!!!=======================*");
        printf("\n\n Passport Number : %-8s", stream->passport);
        printf("\n Name : %-20s", stream->name);
        printf("\n Email address : %-30s", stream->email);
        printf("\n Seat number : A-%d", stream->seat_num);
        printf("\n\n*===================!!!!HAPPY JOURNEY!!!!=======================*");
        stream = stream->following;
    }
}
//**************************GOOD LUCK PASSAPPA******************************

void cancel()
{
    stream = begin;
    system("cls");
    char passport[8];
    printf("\n\n Enter passort number to delete record :");
    gets(passport);
    fflush(stdin);
    if (strcmp(begin->passport, passport) == 0)
    {
        dummy = begin;
        begin = begin->following;
        free(dummy);
        printf("Booking has been deleted!!");
        Sleep(800);
        return;
    }

    while (stream->following)
    {
        if (strcmp(stream->following->passport, passport) == 0)
        {
            dummy = stream->following;
            stream->following = stream->following->following;
            free(dummy);
            printf("Has been deleted ");
            getch();
            Sleep(800);
            return;
        }
        stream = stream->following;
    }
    printf("Passport number is wrong please check your passport");
}