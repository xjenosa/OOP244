/*************************************************************************************
* OOP244 - 2261
*
* Student Name : Maximilian Ali
* Student Email : mali291@myseneca.ca
* Workshop #  : 6
* Course/Section: OOP244/NRA
*
* I declare that this assignment is my own work in accordance with the Seneca Academic
* Policy. No part of this assignment has been copied manually or electronically from/to
* any other source (including web sites) or distributed to other students.
*
* I have done all the coding by myself and only copied the code that my professor
* provided to complete my workshops and assignments.
*
* I used AI to help me with the following:
*  - Debugging and format optimization, as to why my outputs don't match the expected results.
*
**************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Numbers.h"
using namespace std;
namespace seneca{
    Numbers::~Numbers() {
        save();
        delete[] m_numbers;
        delete[] m_filename;
    }
    Numbers::Numbers(const Numbers& other) {
        setEmpty();
        m_isOriginal = false;
        if (other.m_numbers != nullptr) {
            m_numCount = other.m_numCount;
            m_numbers = new double[m_numCount];
            for (int i = 0; i < m_numCount; i++) {
                m_numbers[i] = other.m_numbers[i];
            }
        }
    }
    Numbers& Numbers::operator=(const Numbers& other) {
        if (this != &other) {
            delete[] m_numbers;
            m_numCount = other.m_numCount;
            m_numbers = new double[m_numCount];
            for (int i = 0; i < m_numCount; i++) {
                m_numbers[i] = other.m_numbers[i];
            }
        }
        return *this;
    }
    int Numbers::numberCount() const {
        int count = 0;
        ifstream file(m_filename);
        if (file) {
            char ch;
            while (file.get(ch)) {
                if(ch == '\n') count++;
            }
        }
        return count;
    }
    bool Numbers::load() {
        bool valid = false;
        if (m_numCount > 0) {
            m_numbers = new double[m_numCount];
            ifstream file(m_filename);
            if (file) {
                int i = 0;
                while (i < m_numCount && file >> m_numbers[i]) { // i used ai for this line, never seen it before
                    i++;
                }
                if (i == m_numCount) valid = true;
                else {
                    delete[] m_numbers;
                    setEmpty();
                    valid = false;
                }
            }
        }
        return valid;
    }
    void Numbers::save() const {
        if (m_isOriginal && !isEmpty()) {
            ofstream file(m_filename);
            for (int i = 0; i < m_numCount; i++) {
                file << m_numbers[i] << '\n';
            }
        }
    }
    Numbers& Numbers::operator+=(double value) {
        if (!isEmpty()) {
            double* temp = new double[m_numCount + 1];
            for (int i = 0; i < m_numCount; i++) {
                temp[i] = m_numbers[i];
            }
            m_numCount++;
            temp[m_numCount - 1] = value;
            delete[] m_numbers;
            m_numbers = temp;
            sort();
        }
        return *this;
    }
    ostream& Numbers::display(ostream& ostr) const {
        if (isEmpty()) ostr << "Empty list";
        else {
            ostr << fixed << setprecision(2);
            ostr << "=========================" << endl;
            if (m_isOriginal) ostr << m_filename << endl;
            else ostr << "*** COPY ***" << endl;
            for (int i = 0; i < m_numCount; i++) {
                ostr << m_numbers[i];
                if (i != m_numCount - 1) ostr << ", ";
            }
            ostr << endl;
            ostr << "-------------------------" << endl;
            ostr << "Total of " << m_numCount << " number(s)" << endl;
            double largest = m_numbers[0];
            double smallest = m_numbers[0];
            double sum = 0;
            for (int i = 0; i < m_numCount; i++) {
                if (m_numbers[i] > largest) largest = m_numbers[i];
                if (m_numbers[i] < smallest) smallest = m_numbers[i];
                sum += m_numbers[i];
            }
            double avg = sum / m_numCount;
            ostr << "Largest number:  " << largest << endl;
            ostr << "Smallest number: " << smallest << endl;
            ostr << "Average:         " << avg << endl;
            ostr << "=========================";
        }
        return ostr;
    }
    ostream& operator<<(ostream& os, const Numbers& N) {
        return N.display(os);
    }
    istream& operator>>(istream& istr, Numbers& N) {
        double value;
        istr >> value;
        if (istr) N += value;
        return istr;
    }
}