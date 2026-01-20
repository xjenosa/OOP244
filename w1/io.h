/*************************************************************************************
* OOP244 - 2261
*
* Student Name : Maximilian Ali
* Student Email : mali291@myseneca.ca
* Workshop #  : 1
* Course/Section: OOP244/NRA
*
* I declare that this assignment is my own work in accordance with the Seneca Academic
* Policy. No part of this assignment has been copied manually or electronically from/to
* any other source (including web sites) or distributed to other students.
*
* I have done all the coding by myself and only copied the code that my professor
* provided to complete my workshops and assignments.
*
* I have received help from the following students:
*  - Tuan Khai Ngo / NCC
*
* I have helped the following students:
*  - Christian Rafael / NCC
*
**************************************************************************************/

// io.h
#ifndef SENECA_IO_H
#define SENECA_IO_H
#define MAX_FIRSTNAME_LEN 16
#define MAX_LASTNAME_LEN 26
#include <iostream>

namespace seneca {
    struct PhoneRec {
        char firstName[MAX_FIRSTNAME_LEN];
        char lastName[MAX_LASTNAME_LEN];
        long long phoneNumber;
    };
    
    void read(char *name);
    void print(long long phoneNumber);
    void print(const PhoneRec &pr, size_t &rowNum, const char *filter = nullptr);
    bool read(PhoneRec &pr, FILE *file);
    void print(PhoneRec *pr[], size_t size, const char *filter = nullptr);
    void setPointers(PhoneRec *pr[], PhoneRec records[], size_t size);
    void sort(PhoneRec *pr[], size_t size, bool flag);
}

#endif // !SENECA_IO_H