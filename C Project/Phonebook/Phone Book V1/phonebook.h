#ifndef PHONEBOOK_H
#define PHONEBOOK_H

/** Function prototype */
void addEntry();
void display(int index);
void displayAll();
void search_by_first_name(char *key);
void search_by_last_name(char *key);
void search_by_mobile_number(char *key);
void search_by_telephone_number(char *key);
void search_by_email_address(char *key);
void search_by_area(char *key);
void search_by_city(char *key);

void saveToFile();
void remove_by_mobile_number(char *mobileNumber);
void remove_by_telephone_number(char *telephoneNumber);
void remove_by_email_address(char *emailAddress);
void remove_by_first_name(char *firstName);
void remove_by_last_name(char *lastName);
void readFromFile();
void edit(char *mobileNumber);
void gotoxy(int x, int y);
void coord(int x, int y);

#endif // PHONEBOOK_H
