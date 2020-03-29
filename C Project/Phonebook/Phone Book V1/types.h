#ifndef TYPES_H  // include Guarding ///
#define TYPES_H

/* structure to hold information of a single contact */
typedef struct {
    char firstName[40];
    char lastName[40];
    char mobileNumber[12];
    char telephoneNumber[10];
    char emailAddress[40];
//    char localAddress[40];
    char houseNumber[20];
    char roadNumber[10];
    char area[30];
    char city[30];
} Contact;

#endif // TYPES_H
