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
#include <cstring>
#include <iostream>
#include <iomanip>
#include "Professor.h"
using namespace std;
namespace seneca {
    Professor::Professor() {
        m_subject = nullptr;
        m_sections = 0;
    }

    Professor::Professor(const char* name, char* subject, int sections, size_t employeeNo, double salary) : Employee(name, employeeNo, salary) {
        size_t len = strlen(subject);
        m_subject = new char[len + 1];
        strncpy(m_subject, subject, len);
        m_subject[len] = '\0';
        m_sections = sections;
    }

    Professor::~Professor() {
        delete[] m_subject;
    }

    double Professor::devPay() const {
        return (salary() * 0.01) * m_sections;
    }

    istream& Professor::read(istream& istr) {
        char buffer[1024];
        Employee::read(istr);
        istr.ignore();
        istr.getline(buffer, 1024, ',');
        size_t len = strlen(buffer);
        delete[] m_subject;
        m_subject = new char[len + 1];
        strcpy(m_subject, buffer);
        istr >> m_sections;
        return istr;
    }

    ostream& Professor::write(ostream& ostr) const {
        char subjectPrint[21]{};
        ostr.unsetf(ios::right);
        ostr << " ";
        Employee::write(ostr);
        if(m_subject) {
            int i;
            for(i = 0; i < 20 && m_subject[i] != '\0'; i++) {
                 subjectPrint[i] = m_subject[i];
            }
            subjectPrint[i] = '\0';
        }
        ostr << " " << left << setw(20) << subjectPrint << " | "
        << right << setw(5) << m_sections << " | "
        << fixed << setprecision(2) << setw(8) << devPay() << " |";
        return ostr;
    }

    ostream& Professor::title(ostream& ostr) const {
        Employee::title(ostr);
        ostr << " Teaching Subject | Sec # | $Dev Pay |";
        return ostr;
    }

    ostream& operator<<(ostream& ostr, const Professor& P) {
        return P.write(ostr);
    }

    istream& operator>>(istream& istr, Professor& P) {
        return P.read(istr);
    }
}