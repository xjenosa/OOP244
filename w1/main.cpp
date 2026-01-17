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

#include <iostream>
#include "io.h"
#include "cstr.h"
using namespace seneca;
using namespace std;

void displayMenu();

int main() {
    bool run = true;
    while(run == true) {
        int selection = 0;
        displayMenu();
        cout << "Select an option\n";
        cin >> selection;

        if (selection == 1) {
            // Display records
        } else if (selection == 2) {
            // Sort by last name
        } else if (selection == 3) {
            // Sort by first name
        } else if (selection == 4) {
            // Revert to original order
        } else if (selection == 5) {
            // Search
        } else if (selection == 0) {
            cout << "\nGoodbye!\n";
            run = false;
        }
    }

    return 0;
}

void displayMenu() {
    cout << "---------------------------\n";
    cout << "1- Display records\n";
    cout << "2- Sorted by last name\n";
    cout << "3- Sorted by first name\n";
    cout << "4- revert to original order\n";
    cout << "5- Search\n";
    cout << "---------------------------\n";
    cout << "0- Exit\n";
}