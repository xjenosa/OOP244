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
**************************************************************************************/

// io.cpp
#include <iostream>
#include <cstring>
#include "io.h"
#define MAX_FIRSTNAME_LEN 15 + 1
#define MAX_LASTNAME_LEN 25 + 1
using namespace std;

namespace seneca {
    struct PhoneRec {
        char firstName[MAX_FIRSTNAME_LEN];
        char lastName[MAX_LASTNAME_LEN];
        long long phoneNumber;
    };

    void read(char *name){
        cin >> name;
    }

    void print(long long phoneNumber){
        cout << "(" << (phoneNumber / 10000000) << ") ";
        cout << ((phoneNumber / 10000) % 1000) << "-";
        cout << (phoneNumber % 10000) << endl;
    }

    bool read(PhoneRec &rec, FILE *fp) {
        return fscanf(fp, "%s %s %lld",
                    rec.firstName,
                    rec.lastName,
                    &rec.phoneNumber) == 3;
    }

    void print(PhoneRec* records[], size_t size, const char* filter = nullptr) {
        size_t row = 1;

        for (size_t i = 0; i < size; i++)
        {
            print(*records[i], row, filter);
            row++;
        }
    }

    void setPointers(PhoneRec* ptrs[], PhoneRec recs[], size_t size) {
        for (size_t i = 0; i < size; i++)
        {
            ptrs[i] = &recs[i];
        }
    }

    void sort(PhoneRec* ptrs[], size_t size, bool byLastName) {
        for (size_t i = 0; i < size - 1; i++)
        {
            for (size_t j = i + 1; j < size; j++)
            {
                int cmp;

                if (byLastName)
                {
                    cmp = strcmp(ptrs[i]->lastName, ptrs[j]->lastName);
                }
                else
                {
                    cmp = strcmp(ptrs[i]->firstName, ptrs[j]->firstName);
                }

                if (cmp > 0)
                {
                    PhoneRec* temp = ptrs[i];
                    ptrs[i] = ptrs[j];
                    ptrs[j] = temp;
                }
            }
        }
    }
}