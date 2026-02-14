/***********************************************************************
// OOP244 Workshop 5: Mark Module
//
// File	Mark.cpp
// Version 1.0
// Date	2025/06/12
// Author	partially done by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

/*************************************************************************************
* OOP244 - 2261
*
* Student Name : Maximilian Ali
* Student Email : mali291@myseneca.ca
* Workshop #  : 5
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

#include <iostream>
#include <iomanip>
#include <cmath> // for round function
#include "Mark.h"
using namespace std;
namespace seneca {
   bool Mark::isValid()const {
      return  (m_value >= 0 && m_value <= 100);
   }
   Mark::Mark(int value, char type) {
      *this = type;
      m_value = double(value);
   }

   Mark::Mark(double value) {
      m_type = MARK;
      m_value = value;
   }

   Mark& Mark::operator+=(const Mark& M) {
      m_value += M.m_value;
      return *this;
   }

   Mark& Mark::operator-=(const Mark& M) {
      m_value -= M.m_value;
      return *this;
   }

   Mark Mark::operator+(const Mark& M) const {
      return Mark(*this) += M;
   }

   Mark Mark::operator-(const Mark& M)const {
      return Mark(*this) -= M;
   }

   Mark& Mark::operator/=(int other) {
      m_value = m_value / other;
      return *this;
   }

   Mark Mark::operator/(int other) const {
      return Mark(m_value / other);
   }

   Mark& Mark::operator=(int value) {
      m_value = value;
      return *this;
   }

   Mark& Mark::operator=(char type) {
      m_type = MARK;
      if (type == GRADE || type == GPA) {
         m_type = type;
      }
      return *this;
   }

   double Mark::raw() const {
      return m_value;
   }

   Mark::operator int() const {
      int value = -1;
      if (isValid()) {
         value = int(std::round(m_value < 0 ? 0 : m_value));
      }
      return value;
   }
   Mark::operator bool() const {
      return isValid();
   }


   // returns the GPA not the m_value!!!
   Mark::operator double() const {
      double gpa = 0;
      if (!isValid()) gpa = -1;
      else gpa = m_value * 0.04;
      return gpa;
   }

   Mark::operator const char* () const {
      // removes the constantness of m_grade!
      // You will learn this at the end of the semester.
      char* grade = const_cast<char*>(m_grade);

      int value = int(*this);
      grade[1] = grade[2] = '\0';
      if (value < 0 || value > 100) grade[0] = 'X';
      else if (value >= 90) grade[0] = 'A', grade[1] = '+';
      else if (value >= 80) grade[0] = 'A';
      else if (value >= 75) grade[0] = 'B', grade[1] = '+';
      else if (value >= 70) grade[0] = 'B';
      else if (value >= 65) grade[0] = 'C', grade[1] = '+';
      else if (value >= 60) grade[0] = 'C';
      else if (value >= 55) grade[0] = 'D', grade[1] = '+';
      else if (value >= 50) grade[0] = 'D';
      else grade[0] = 'F';
      return m_grade;
   }

   // student helper function implementations go here
   ostream& Mark::display(ostream& os) const{
      if(!isValid()) {
         if(m_type == GRADE){
            os << "**";
         }
         else{
            os << "***";
         }
      }
      else if(m_type == GPA){
         os << fixed << setprecision(1) << setw(3) << (double)(*this);
      }
      else if(m_type == MARK){
         os << right << setfill('_') << setw(3) << (int)(*this);
      }
      else if(m_type == GRADE){
         os << left << setfill(' ') << setw(3) << (const char*)(*this);
      }
      return os;
   }

   ostream& display(const Mark &mark, char type, std::ostream& os){ // ai fixed this for me, completely different from fardad instructions
      Mark temp = mark;
      temp = MARK;
      temp.display(os);
      if(type != MARK){
         os << ": ";
         temp = mark;
         temp = type;
         temp.display(os);
      }
      return os;
   }

   ostream& operator<<(ostream& os, const Mark& mark){
      return mark.display(os);
   }

   istream& operator>>(istream& is, Mark& mark) {
      int value = 0;
      char nextChar = '\0';
      bool run = true;
      while (run) {
         is >> value; // different from fardad instructions
         if (is.fail()) { // had to find this in course notes
            cout << "Invalid integer, try again.\n> ";
            is.clear();
            is.ignore(10000, '\n');
         }
         else {
            nextChar = is.get(); // had to find this in course notes
            if (nextChar != '\n') {
               cout << "Invalid trailing characters. Please enter only an integer.\n> ";
               is.ignore(10000, '\n');
            }
            else {
               if (value < 0 || value > 100) {
                  cout << "Invalid mark. Enter a value between 0 and 100.\n> ";
               }
               else {
                  mark = value;
                  run = false;
               }
            }
         }
      }
      return is;
   }

   ifstream& operator>>(ifstream& ifs, Mark& mark){
      int value = 0;
      char comma = '\0';
      char type = '\0';
      ifs >> value >> comma >> type;
      if(ifs && comma == ','){
         mark = value;
         mark = type;
      }
      return ifs;
   }

   double operator+(double value, const Mark& mark){
      return value + mark.raw(); // testing if ai works
   }

   int operator+(int value, const Mark& mark){
      return value + int(mark);
   }

   double operator-(double value, const Mark& mark){
      return value - mark.raw(); // testing if ai works
   }

   int operator-(int value, const Mark& mark){
      return value - int(mark);
   }

   double operator/(double value, const Mark& mark){
      return value / double(mark.m_value);
   }

   int operator/(int value, const Mark& mark){
      return value / int(mark.m_value + 0.5);
   }
}