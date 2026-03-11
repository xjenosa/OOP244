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
#ifndef SENECA_PROFESSOR_H
#define SENECA_PROFESSOR_H
#include "Employee.h"
namespace seneca{
    class Professor : public Employee {
        char* m_subject{};
        int m_sections{};
        double devPay() const;
    public:
        Professor();
        Professor(const char* name, char* subject, int sections, size_t employeeNo, double salary);
        ~Professor();
        std::istream& read(std::istream& istr = std::cin);
        std::ostream& write(std::ostream& ostr = std::cout) const;
        std::ostream& title(std::ostream& ostr = std::cout) const;
    };
    std::ostream& operator<<(std::ostream& ostr, const Professor& P);
    std::istream& operator>>(std::istream& istr, Professor& P);
}

#endif // SENECA_PROFESSOR_H