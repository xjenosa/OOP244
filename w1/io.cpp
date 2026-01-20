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

// io.cpp
#include "io.h"
#include "cstr.h"
using namespace seneca;
using namespace std;

namespace seneca {
    void read(char *name){
        cout << "Name\n> ";
        cin >> name;
    }

    void print(long long phoneNumber){
        cout << " (" << (phoneNumber / 10000000) << ") ";
        cout << ((phoneNumber % 10000000) / 10000) << "-";
        cout << (phoneNumber % 10000) << endl;
    }

    void print(const PhoneRec &pr, size_t &rowNum, const char *filter){
       if(filter == nullptr || strstr(pr.lastName, filter) != nullptr || strstr(pr.firstName, filter) != nullptr){
            cout << rowNum << ": " << pr.firstName << " " << pr.lastName;
            print(pr.phoneNumber);
            rowNum++;
       }
    }

    bool read(PhoneRec &pr, FILE *file){
        bool tf;
        if(fscanf(file, "%s %s %lld", pr.firstName, pr.lastName, &pr.phoneNumber) == 3){
            tf = true;
        }
        else tf = false;
        return tf;
    }

    void print(PhoneRec *pr[], size_t size, const char *filter){
        size_t rowNum = 1;
        for(size_t i = 0; i < size; i++){
            print(*pr[i], rowNum, filter);
        }
    }

    void setPointers(PhoneRec *pr[], PhoneRec records[], size_t size){
        for(size_t i = 0; i < size; i++){
            pr[i] = &records[i];
        }
    }

    void sort(PhoneRec *pr[], size_t size, bool flag){
        PhoneRec *buff;
        for(size_t i = 0; i < size; i++){
            for(size_t j = i + 1; j < size; j++){
                if(flag){
                    if(strcmp((*pr[i]).lastName, (*pr[j]).lastName) > 0){
                        buff = pr[i];
                        pr[i] = pr[j];
                        pr[j] = buff;
                    }
                }
                else{
                    if(strcmp((*pr[i]).firstName, (*pr[j]).firstName) > 0){
                        buff = pr[i];
                        pr[i] = pr[j];
                        pr[j] = buff;
                    }
                }
            }
        }
    }
}