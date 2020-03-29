#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>

#include "types.h"
#include "phonebook.h"

void clear();


int main()
{
    //system("COLOR F0");
    //char name[15];
    //char pass[15];
    //int count=0,i;

//    system("cls");
//start:
//    gotoxy(55, 1);
//    printf("LOGIN \n");
//    gotoxy(50, 2);
//    printf("Enter user name :");
//    gotoxy(68, 2);
//    strcpy(gets(name),name);
//    gotoxy(50, 3);
//    printf("Enter password  :");
//    gotoxy(68, 3);
//
//    i=0;
//    do
//    {
//        pass[i] = getch();
//        if(pass[i] == 13 )
//        {
//            break;
//        }
//        else if(pass[i]==8 && i>0)
//        {
//            printf("%c%c%c",8,32,8);
//            i--;
//        }
//        else
//        {
//            printf("*");
//            i++;
//        }
//    }
//    while(pass[i]!=13);
//    pass[i] = '\0';
//
//    if(strcmp(name,"BUBT") || strcmp(pass,"CSE"))
//    {
//        system("cls");
//        gotoxy(50, 1);
//        printf("Invalid User name and Password");
//        count++;
//        gotoxy(50, 2);
//        printf("%d chance left!!!",3-count);
//        gotoxy(50, 3);
//        getch();
//        system("cls");
//        if(count==3)
//            exit(0);
//        else
//            goto start;
//    }
//    else
//    {
        gotoxy(50, 1);
        printf("User name and Password Matched.");
        gotoxy(50, 2);
        printf("Login successful!!!");
        system("cls");
        //readFromFile();
        char selection[41];
        int choice;
        while(1)
        {
            back:
                gotoxy(40, 1);
            puts("Phone Book Application Main Menu.");
            gotoxy(45, 2);
            puts("1. Add a contact.");
            gotoxy(45, 3);
            puts("2. Display all contacts");
            gotoxy(45, 4);
            puts("3. Search a contact.");
            gotoxy(45, 5);
            puts("4. Delete a contact. ");
            gotoxy(45, 6);
            puts("5. Edit a contact.");
            gotoxy(45, 7);
            puts("0. Exit");
            do
            {
                gb:
                gotoxy(45, 8);
                printf("Enter your choice: ");
                gets(selection);
                choice = atoi(selection);
                //printf("choice: %d ", choice);
            }
            while(choice < 0 || choice > 5);

            switch(choice)
            {
            case 1:
                system("cls");
                addEntry();
                saveToFile();
                clear();
                break;
            case 2:
                system("cls");
                displayAll();
                clear();
                break;
            case 3:
                system("cls");
                while(1)
                {
                    gotoxy(40, 1);
                    puts("Phone Book Application Search Menu.");
                    gotoxy(45, 2);
                    puts("1. Search by first name.");
                    gotoxy(45, 3);
                    puts("2. Search by last name.");
                    gotoxy(45, 4);
                    puts("3. Search by mobile Number.");
                    gotoxy(45, 5);
                    puts("4. Search by telephone Number.");
                    gotoxy(45, 6);
                    puts("5. Search by area.");
                    gotoxy(45, 7);
                    puts("6. Search by city.");
                    gotoxy(45, 8);
                    puts("7. Search by email address.");
                    gotoxy(45, 9);
                    puts("Press 0 to return to main menu.");
                    do
                    {
                        gotoxy(45, 10);
                        printf("Enter your choice: ");
                        gets(selection);
                        choice = atoi(selection);
                    }
                    while(choice < 0 || choice > 7);

                    switch(choice)
                    {
                    case 1:
                        system("cls");
                        gotoxy(40, 1);
                        puts("Enter first name to search: ");
                        gotoxy(68, 1);
                        gets(selection);
                        system("cls");
                        search_by_first_name(selection);
                        puts("");
                        clear();
                        break;
                    case 2:
                        system("cls");
                        gotoxy(40, 1);
                        puts("Enter last name to search: ");
                        gotoxy(68, 1);
                        gets(selection);
                        system("cls");
                        search_by_last_name(selection);
                        puts("");
                        clear();
                        break;
                    case 3:
                        system("cls");
                        gotoxy(40, 1);
                        puts("Enter mobile number to search: ");
                        gotoxy(72, 1);
                        gets(selection);
                        system("cls");
                        search_by_mobile_number(selection);
                        puts("");
                        clear();
                        break;
                    case 4:
                        system("cls");
                        gotoxy(40, 1);
                        puts("Enter telephone number to search: ");
                        gotoxy(78, 1);
                        gets(selection);
                        system("cls");
                        search_by_telephone_number(selection);
                        puts("");
                        clear();
                        break;
                    case 5:
                        system("cls");
                        gotoxy(40, 1);
                        puts("Enter area name to search: ");
                        gotoxy(68, 1);
                        gets(selection);
                        system("cls");
                        search_by_area(selection);
                        puts("");
                        clear();
                        break;
                    case 6:
                        system("cls");
                        gotoxy(40, 1);
                        puts("Enter city name to search: ");
                        gotoxy(68, 1);
                        gets(selection);
                        system("cls");
                        search_by_city(selection);
                        puts("");
                        clear();
                        break;
                    case 7:
                        system("cls");
                        gotoxy(40, 1);
                        puts("Enter email address to search: ");
                        gotoxy(72, 1);
                        gets(selection);
                        system("cls");
                        search_by_email_address(selection);
                        puts("");
                        clear();
                        break;
                    case 0:
                        system("cls");
                        goto back;

                    default:
                        gotoxy(40, 1);
                        puts("Wrong choice...\a");
                        break;
                    }
                }
                break;
            case 4:
                while(1)
                {
                    //clear();
                    system("cls");
                    gotoxy(40, 1);
                    puts("Phone Book Application Deletion Menu.");
                    gotoxy(40, 2);
                    puts("Search an entry to delete: ");
                    gotoxy(40, 3);
                    puts("1. by first name.");
                    gotoxy(40, 4);
                    puts("2. by last name.");
                    gotoxy(40, 5);
                    puts("3. by mobile Number.");
                    gotoxy(40, 6);
                    puts("4. by telephone Number.");
                    gotoxy(40, 7);
                    puts("5. by email address.");
                    gotoxy(40, 8);
                    puts("Press 0 to return to main menu.");
                    do
                    {
                        gotoxy(40, 9);
                        printf("Enter your choice: ");
                        //gotoxy(60, 9);
                        gets(selection);
                        choice = atoi(selection);
                    }
                    while(choice <0 || choice > 6);

                    switch(choice)
                    {
                    case 1:
                        system("cls");
                        gotoxy(40, 1);
                        puts("Enter first name to delete: ");
                        gotoxy(68, 1);
                        gets(selection);
                        remove_by_first_name(selection);
                        //saveToFile();  ///***
                        clear();
                        break;
                    case 2:
                        system("cls");
                        gotoxy(40, 1);
                        puts("Enter last name to delete: ");
                        gotoxy(68, 1);
                        gets(selection);
                        remove_by_last_name(selection);
                        //saveToFile();  ///***
                        clear();
                        break;
                    case 3:
                        system("cls");
                        gotoxy(40, 1);
                        puts("Enter mobile number to delete: ");
                        gotoxy(68, 1);
                        gets(selection);
                        remove_by_mobile_number(selection);
                        //saveToFile();  ///***
                        clear();
                        break;
                    case 4:
                        system("cls");
                        gotoxy(40, 1);
                        puts("Enter telephone number to delete: ");
                        gotoxy(68, 1);
                        gets(selection);
                        remove_by_telephone_number(selection);
                        //saveToFile();  ///***
                        clear();
                        break;
                    case 5:
                        system("cls");
                        gotoxy(40, 1);
                        puts("Enter email address to delete: ");
                        gotoxy(68, 1);
                        gets(selection);
                        remove_by_email_address(selection);
                        //saveToFile();  ///***
                        clear();
                        break;
                    case 0:
                        system("cls");
                        //clear();
                        goto back;
                        clear();
                        break;
                    default:
                        gotoxy(40, 1);
                        puts("Wrong choice...\a");
                        break;
                    }
                }
                break;
            case 5:
                //system("cls");
                gotoxy(45, 9);
                puts("Enter mobile number: ");
                gotoxy(65, 9);
                gets(selection);
                edit(selection);
                clear();
                break;
            case 0:
               // printf("1");

                exit(0);
                break;
            default:
                gotoxy(40, 1);
                puts("Wrong choice...\a");
                goto gb;
                break;
            }
        }


       // } /// end curly brace of else statement of Password section.

        return 0;
    }

void clear()
{
    system("PAUSE");  /// press any key to continue
    system("CLS");    /// clear the screen
}
