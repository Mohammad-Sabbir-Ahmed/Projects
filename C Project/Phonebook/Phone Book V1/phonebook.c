#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "types.h"
#include "phonebook.h"
#include "utilities.h"

#define MAX_SIZE 100

/** Array to hold our contact */
Contact phonebook[MAX_SIZE];

/** current seize of the phonebook array */
int currentSize = 0;



void addEntry()
{
    int len, i;
    char num[41];
    if(currentSize == MAX_SIZE)
    {
        gotoxy(40, 1);
        puts("\aError: phone book is full!");
        return;
    }
    Contact c;
    gotoxy(40, 2);
    printf("Enter First Name   : ");
    gets(c.firstName);
    gotoxy(40, 3);
    printf("Enter Last Name    : ");
    gets(c.lastName);
    gotoxy(40, 4);



    ///*************
    printf("Enter Mobile Number: ");
    gets(num);
    len = strlen(num);
    while( len!= 11)
    {
        gotoxy(40, 4);
        printf("Enter a valid number: ");
        gets(num);
        len = strlen(num);
    }
    for( i=0; i<len; i++)
    {
        c.mobileNumber[i] = num[i];
    }
    c.mobileNumber[i] = '\0';
    ///************






    ///************
    gotoxy(40, 5);
    printf("Enter Telephone Number: ");
    gets(num);
    len = strlen(num);
    while(len < 9 || len > 9)
    {
        gotoxy(40, 5);
        //printf("Wrong number!!!\n");
        printf("Enter a valid number: ");
        gets(num);
        len = strlen(num);
    }
    for( i=0; i<len; i++)
    {
        c.telephoneNumber[i] = num[i];
    }
    c.telephoneNumber[i] = '\0';
    ///****************





    ///****************
    gotoxy(40, 6);
    printf("Enter Email Address : ");
    gets(num);
    len = strlen(num);
    int done = 0;
    while(!done)
    {
        for(int i=0; i<len; i++)
        {
            if(( num[i]=='@' && num[i+1]=='g' &&
                    num[i+2]=='m' && num[i+3]=='a' &&
                    num[i+4]=='i' && num[i+5]=='l' &&
                    num[i+6]=='.' && num[i+7]=='c' &&
                    num[i+8]=='o' && num[i+9]=='m' ) ||
                    ( num[i]=='@' && num[i+1]=='y' &&
                      num[i+2]=='a' && num[i+3]=='h' &&
                      num[i+4]=='o' && num[i+5]=='o' &&
                      num[i+6]=='.' && num[i+7]=='c' &&
                      num[i+8]=='o' && num[i+9]=='m' ))
            {
                int j ;
                for( j=0; j<len; j++)
                {
                    c.emailAddress[j] = num[j];
                }
                c.emailAddress[j] = '\0';
                done = 1;
                break;
            }

        }
        if(!done)
        {
            gotoxy(40, 6);
            printf("Enter a valid email: ");
            gets(num);
        }


    }
    ///****************


    gotoxy(40, 7);
    printf("Enter House number : ");
    gets(c.houseNumber);
    gotoxy(40, 8);
    printf("Enter Road number : ");
    gets(c.roadNumber);
    gotoxy(40, 9);
    printf("Enter Your Area Name : ");
    gets(c.area);
    gotoxy(40, 10);
    printf("Enter Your City Name : ");
    gets(c.city);

    phonebook[currentSize] = c;
    ++currentSize;
}




void gotoxy(int x, int y)
{
    COORD C;
    C.X = x;
    C.Y = y; /// X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), C);
}



void display(int index)
{
    int plus = index + 2 ;

    int x = 5;
    int y = plus += 1;
    if(index < 0 || index >= currentSize)
    {
        puts("\aError: Invalid index!");
        return;
    }
    Contact c = phonebook[index];
    gotoxy(x,y);
    printf("%d.", index+1);
    gotoxy(x+5, y);
    printf("%s ", c.firstName);
    printf("%s", c.lastName);
    gotoxy(x+20, y);
    printf("%s ", c.mobileNumber);
    gotoxy(x+35, y);
    printf("%s ", c.telephoneNumber);
    gotoxy(x+50, y);
    printf("%s ", c.emailAddress);
    gotoxy(x+80, y);
    printf("%s, ", c.houseNumber);
    printf("%s, ", c.roadNumber);
    printf("%s, ", c.area);
    printf("%s", c.city);

}


void displayAll()
{
    readFromFile();
    if(currentSize == 0)
    {
        gotoxy(40, 2);
        puts("\aPhonebook is empty!");
        return;
    }
    int i;
    gotoxy(50,0);
    puts("All contacts.\n");
    gotoxy(5,1);
    puts("Ser. ");
    gotoxy(10,1);
    puts("Name");
    gotoxy(25,1);
    puts("Mobile");
    gotoxy(40,1);
    puts("Telephone");
    gotoxy(55,1);
    puts("Email ");
    gotoxy(85,1);
    puts("Address");
    gotoxy(5,2);

    for( i=0; i<= 85+25; i++)
        printf("*");
    puts("");
    for( i=0; i<currentSize; i++)
    {
        display(i);
        puts("");                        /// extra new line ///
    }

}

//void search(char *key, search_t type)
void search_by_first_name(char *key) /// search by first name
{
    readFromFile();
    int found = 0;
    int i, j, len;

    strtolower(key);
    char content[41];
    len = strlen(key);

    for(i=0; i<currentSize; i++)
    {
        strcpy(content,phonebook[i].firstName);
        strtolower(content);
        if(strcmp(content, key) == 0)
        {
op1:
            display(i);
            found = 1;
        }
        else
        {
            for(j=0; j<len; j++)
            {
                if(content[j]==key[j])
                {
                    if(j==len-1)
                    {
                        goto op1;
                    }
                }
                else
                    break;
            }
        }
    }

}

void search_by_last_name(char *key) /// search by last name
{
    readFromFile();
    int found = 0;
    int i, j, len;

    strtolower(key);
    char content[41];
    len = strlen(key);

    for(i=0; i<currentSize; i++)
    {
        strcpy(content,phonebook[i].lastName);
        strtolower(content);

        if(strcmp(content, key) == 0)
        {
op2:
            display(i);
            found = 1;
        }
        else
        {
            for(j=0; j<len; j++)
            {
                if(content[j]==key[j])
                {
                    if(j==len-1)
                    {
                        goto op2;
                    }
                }
                else
                    break;
            }
        }
    }
}

void search_by_mobile_number(char *key) ///search by mobile number
{
    readFromFile();
    int found = 0;
    int i, j,  len;

    strtolower(key);
    char content[41];
    len = strlen(key);

    for(i=0; i<currentSize; i++)
    {
        strcpy(content,phonebook[i].mobileNumber);
        strtolower(content);

        if(strcmp(content, key) == 0)
        {
op2:
            display(i);
            found = 1;
        }
        else
        {
            for(j=0; j<len; j++)
            {
                if(content[j]==key[j])
                {
                    if(j==len-1)
                    {
                        goto op2;
                    }
                }
                else
                    break;
            }
        }
    }
}

void search_by_telephone_number(char *key) ///search by telephone number
{
    readFromFile();
    int found = 0;
    int i, j,  len;

    strtolower(key);
    char content[41];
    len = strlen(key);

    for(i=0; i<currentSize; i++)
    {
        strcpy(content,phonebook[i].telephoneNumber);
        strtolower(content);

        if(strcmp(content, key) == 0)
        {
op2:
            display(i);
            found = 1;
        }
        else
        {
            for(j=0; j<len; j++)
            {
                if(content[j]==key[j])
                {
                    if(j==len-1)
                    {
                        goto op2;
                    }
                }
                else
                    break;
            }
        }
    }
}


void search_by_email_address(char *key) ///search by email address
{
    readFromFile();
    int found = 0;
    int i, j, len;

    strtolower(key);
    char content[41];
    len = strlen(key);

    for(i=0; i<currentSize; i++)
    {
        strcpy(content,phonebook[i].emailAddress);
        strtolower(content);

        if(strcmp(content, key) == 0)
        {
op2:
            display(i);
            found = 1;
        }
        else
        {
            for(j=0; j<len; j++)
            {
                if(content[j]==key[j])
                {
                    if(j==len-1)
                    {
                        goto op2;
                    }
                }
                else
                    break;
            }
        }
    }
}

void search_by_area(char *key) ///search by area
{
    readFromFile();
    int found = 0;
    int i, j, len;

    strtolower(key);
    char content[41];
    len = strlen(key);

    for(i=0; i<currentSize; i++)
    {
        strcpy(content,phonebook[i].area);
        strtolower(content);

        if(strcmp(content, key) == 0)
        {
op2:
            display(i);
            found = 1;
        }
        else if (content[0]==key[0])
        {
            for(j=0; j<len; j++)
            {
                if(content[j]==key[j])
                {
                    if(j==len-1)
                    {
                        found = 1;
                        goto op2;
                    }
                }
                else
                    break;
            }
        }
        if(!found)
        {
            gotoxy(40, 2);
            puts("\aNot found in the phone book");

        }
    }
}

void search_by_city(char *key) ///search by city
{
    readFromFile();
    int found = 0;
    int i, j, len;

    strtolower(key);
    char content[41];
    len = strlen(key);

    for(i=0; i<currentSize; i++)
    {
        strcpy(content,phonebook[i].city);
        strtolower(content);

        if(strcmp(content, key) == 0)
        {
op2:
            display(i);
            found = 1;
        }
        else if(content[0]==key[0])
        {
            for(j=0; j<len; j++)
            {
                if(content[j]==key[j])
                {
                    if(j==len-1)
                    {
                        found = 1;
                        goto op2;
                    }
                }
                else
                    break;
            }
        }
        if(!found)
        {
            gotoxy(40, 2);
            puts("\aNot found in the phone book");

        }

    }
} /****  ****/

//    else{
//            gotoxy(40, 2);
//        puts("\aError: invalid search type!!!");
//        return;
//    }
//    if(!found){
//            gotoxy(40, 2);
//        puts("\aNot found in the phone book");
//    }
//}



void readFromFile()
{
    FILE *fp;

    /**	Open for reading in binary mode.  */
    if((fp = fopen("phonebook.db", "rb")) == NULL)
    {
        gotoxy(40, 1);
        puts("\aError: can't load the database file!");
        return;
    }

    /*** read the size of the phonebook */
    else if(fread(&currentSize, sizeof(currentSize), 1, fp) != 1)
    {
        gotoxy(40, 2);
        puts("\aError: can't read data! 1");
        return;
    }

    /** read the actual phonebook content */
    else if(fread(phonebook, sizeof(phonebook), 1, fp) != 1)
    {
        gotoxy(40, 1);
        // puts("\aError: can't read data! ");
        return;
    }
}

void saveToFile()
{
    FILE *fp;
    if((fp = fopen("phonebook.db", "wb"))== NULL)   ///Open for writing in binary mode.
    {
        gotoxy(40, 2);
        puts("\aError: can't create a database file");
        return;
    }

    if(fwrite(&currentSize, sizeof(currentSize), 1, fp)!= 1)
    {
        gotoxy(40, 2);
        puts("\aError: can't save data!");
        return;
    }
    /** save the phonebook contents */
    if(fwrite(phonebook, sizeof(phonebook), 1, fp) != 1)
    {
        gotoxy(40, 2);
        puts("\aError: can't save data!");
        return;
    }
    //gotoxy(40, 11);
    //puts("Phone book saved to file successfully!");

}



void remove_by_first_name(char *firstName)  /// search by first name to delete
{
    if(currentSize == 0)
    {
        gotoxy(40, 2);
        puts("Phonebook is empty! Nothing to delete!");
        return;
    }

    int i, j, count = 0;
    for( i=0; i<currentSize; i++)
    {
        if(strcmp(phonebook[i].firstName, firstName) == 0)
        {
            for( j=i; j<currentSize-1; j++)
            {
                phonebook[j] = phonebook[j+1];
            }

            strcpy(phonebook[j].firstName, "");
            strcpy(phonebook[j].lastName, "");
            strcpy(phonebook[j].mobileNumber, "");
            strcpy(phonebook[j].telephoneNumber, "");
            strcpy(phonebook[j].emailAddress, "");
            strcpy(phonebook[j].houseNumber, "");
            strcpy(phonebook[j].roadNumber, "");
            strcpy(phonebook[j].area, "");
            strcpy(phonebook[j].city, "");

            currentSize -= 1;
            ++count;
        }
    }
    if(count == 0)
    {
        gotoxy(40, 2);
        puts("\aNo entry deleted\n");
    }
    else
    {
        gotoxy(40, 2);
        printf("\a%d entry(ies) deleted\n", count);
        saveToFile();
    }
}



void remove_by_last_name(char *lastName)   /// search by last name to delete
{
    if(currentSize == 0)
    {
        gotoxy(40, 2);
        puts("Phonebook is empty! Nothing to delete!");
        return;
    }

    int i, j, count = 0;
    for( i=0; i<currentSize; i++)
    {
        if(strcmp(phonebook[i].lastName, lastName) == 0)
        {
            for( j=i; j<currentSize-1; j++)
            {
                phonebook[j] = phonebook[j+1];
            }

            strcpy(phonebook[j].firstName, "");
            strcpy(phonebook[j].lastName, "");
            strcpy(phonebook[j].mobileNumber, "");
            strcpy(phonebook[j].telephoneNumber, "");
            strcpy(phonebook[j].emailAddress, "");
            strcpy(phonebook[j].houseNumber, "");
            strcpy(phonebook[j].roadNumber, "");
            strcpy(phonebook[j].area, "");
            strcpy(phonebook[j].city, "");

            currentSize -= 1;
            ++count;
        }
    }
    if(count == 0)
    {
        gotoxy(40, 2);
        puts("\aNo entry deleted\n");
    }
    else
    {
        gotoxy(40, 2);
        printf("\a%d entry(ies) deleted\n", count);
        saveToFile();
    }
}



void remove_by_mobile_number(char *mobileNumber)  /// search by mobile number to delete
{
    if(currentSize == 0)
    {
        gotoxy(40, 2);
        puts("Phonebook is empty! Nothing to delete!");
        return;
    }

    int i, j, count = 0;
    for( i=0; i<currentSize; i++)
    {
        if(strcmp(phonebook[i].mobileNumber, mobileNumber) == 0)
        {
            for( j=i; j<currentSize-1; j++)
            {
                phonebook[j] = phonebook[j+1];
            }

            strcpy(phonebook[j].firstName, "");
            strcpy(phonebook[j].lastName, "");
            strcpy(phonebook[j].mobileNumber, "");
            strcpy(phonebook[j].telephoneNumber, "");
            strcpy(phonebook[j].emailAddress, "");
            strcpy(phonebook[j].houseNumber, "");
            strcpy(phonebook[j].roadNumber, "");
            strcpy(phonebook[j].area, "");
            strcpy(phonebook[j].city, "");

            currentSize -= 1;
            ++count;
        }
    }
    if(count == 0)
    {
        gotoxy(40, 2);
        puts("\aNo entry deleted\n");
    }
    else
    {
        gotoxy(40, 2);
        printf("\a%d entry(ies) deleted\n", count);
        saveToFile();
    }
}


void remove_by_telephone_number(char *telephoneNumber)  /// search by telephone number to delete
{
    if(currentSize == 0)
    {
        gotoxy(40, 2);
        puts("Phonebook is empty! Nothing to delete!");
        return;
    }

    int i, j, count = 0;
    for( i=0; i<currentSize; i++)
    {
        if(strcmp(phonebook[i].telephoneNumber, telephoneNumber) == 0)
        {
            for( j=i; j<currentSize-1; j++)
            {
                phonebook[j] = phonebook[j+1];
            }

            strcpy(phonebook[j].firstName, "");
            strcpy(phonebook[j].lastName, "");
            strcpy(phonebook[j].mobileNumber, "");
            strcpy(phonebook[j].telephoneNumber, "");
            strcpy(phonebook[j].emailAddress, "");
            strcpy(phonebook[j].houseNumber, "");
            strcpy(phonebook[j].roadNumber, "");
            strcpy(phonebook[j].area, "");
            strcpy(phonebook[j].city, "");

            currentSize -= 1;
            ++count;
        }
    }
    if(count == 0)
    {
        gotoxy(40, 2);
        puts("\aNo entry deleted\n");
    }
    else
    {
        gotoxy(40, 2);
        printf("\a%d entry(ies) deleted\n", count);
        saveToFile();
    }
}



void remove_by_email_address(char *emailAddress)  /// search by email address to delete
{
    if(currentSize == 0)
    {
        gotoxy(40, 2);
        puts("Phonebook is empty! Nothing to delete!");
        return;
    }

    int i, j, count = 0;
    for( i=0; i<currentSize; i++)
    {
        if(strcmp(phonebook[i].emailAddress, emailAddress) == 0)
        {
            for( j=i; j<currentSize-1; j++)
            {
                phonebook[j] = phonebook[j+1];
            }

            strcpy(phonebook[j].firstName, "");
            strcpy(phonebook[j].lastName, "");
            strcpy(phonebook[j].mobileNumber, "");
            strcpy(phonebook[j].telephoneNumber, "");
            strcpy(phonebook[j].emailAddress, "");
            strcpy(phonebook[j].houseNumber, "");
            strcpy(phonebook[j].roadNumber, "");
            strcpy(phonebook[j].area, "");
            strcpy(phonebook[j].city, "");

            currentSize -= 1;
            ++count;
        }
    }
    if(count == 0)
    {
        gotoxy(40, 2);
        puts("\aNo entry deleted\n");
    }
    else
    {
        gotoxy(40, 2);
        printf("\a%d entry(ies) deleted\n", count);
        saveToFile();
    }
}


void edit(char *mobileNumber)    /// search by mobile number to edit an entry
{
    int len = 0, j;
    readFromFile();
    char input[41];
    if(currentSize == 0)
    {
        gotoxy(40, 2);
        puts("\aPhonebook is empty! Nothing to edit!");
        return;
    }

    int  count = 0;

    for(int i=0; i<currentSize; i++)
    {
//        if(strcmp(phonebook[i].mobileNumber, mobileNumber) == 0){
        if(strcmp(phonebook[i].mobileNumber, mobileNumber) == 0)
        {
            system("cls");
            gotoxy(30, 2);
            puts("Edit first name: ");
            gotoxy(50, 2);
            gets(input);
            strcpy(phonebook[i].firstName, input);
            gotoxy(30, 3);
            puts("Edit last name: ");
            gotoxy(50, 3);
            gets(input);
            strcpy(phonebook[i].lastName, input);

            ///************

            gotoxy(30, 4);
            puts("Edit tel. number: ");
            gotoxy(50, 4);
            gets(input);
            len = strlen(input);
            while(len < 9 || len > 9)
            {
                gotoxy(30, 4);
                printf("Enter a valid number: ");
                gets(input);
                len = strlen(input);
            }
//            for( j=0; j<len; j++)
//            {
//                phonebook[i].telephoneNumber[j] = input[j];
//            }
//            phonebook[i].telephoneNumber[j] = '\0';
                strcpy(phonebook[i].telephoneNumber, input);
             //strcpy(phonebook[i].telephoneNumber, input);

            ///****************


            ///*****************
            gotoxy(30, 5);
            puts("Edit email address: ");
            gotoxy(50, 5);
            gets(input);

            len = strlen(input);
            int done = 0, j;
            while(!done)
            {
                for(j=0; j<len; j++)
                {
                    if(( input[j]=='@' && input[j+1]=='g' &&
                            input[j+2]=='m' && input[j+3]=='a' &&
                            input[j+4]=='i' && input[j+5]=='l' &&
                            input[j+6]=='.' && input[j+7]=='c' &&
                            input[j+8]=='o' && input[j+9]=='m' ) ||
                            ( input[j]=='@' && input[j+1]=='y' &&
                              input[j+2]=='a' && input[j+3]=='h' &&
                              input[j+4]=='o' && input[j+5]=='o' &&
                              input[j+6]=='.' && input[j+7]=='c' &&
                              input[j+8]=='o' && input[j+9]=='m' ))
                    {
//                        int k ;
//                        for( k=0; k<len; k++)
//                        {
//                            phonebook[i].emailAddress[k] = input[k];
//                        }
//                        phonebook[i].emailAddress[k] = '\0';
                        strcpy(phonebook[i].emailAddress, input);
                        done = 1;
                        count = 1;
                        saveToFile();
                        break;
                    }

                }
                if(!done)
                {
                    gotoxy(30, 5);
                    printf("Enter a valid email: 1");
                    gets(input);
                }


            }

        }
    }
    if(!count)
    {
        gotoxy(45, 10);
        printf("Not found...");
    }
}
