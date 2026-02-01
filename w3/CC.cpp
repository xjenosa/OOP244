/*************************************************************************************
* OOP244 - 2261
*
* Student Name : Maximilian Ali
* Student Email : mali291@myseneca.ca
* Workshop #  : 3
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
#include "cstr.h"
#include "CC.h"
using namespace std;
namespace seneca {
   void CC::aloCopy(const char* name) {
      m_name = new char[strlen(name) + 1];
      strcpy(m_name, name);
   }
   void CC::clear() {
      delete[] m_name;
      m_name = nullptr;
   }
   void CC::display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const{
      char lname[31]{};
      strcpy(lname, name, 30);
      cout << "| ";
      cout.width(30);
      cout.fill(' ');
      cout.setf(ios::left);
      cout << lname << " | ";
      prnNumber(number);
      cout << " | " << cvv << " | ";
      cout.unsetf(ios::left);
      cout.setf(ios::right);
      cout.width(2);
      cout << expMon << "/" << expYear << " |" << endl;
      cout.unsetf(ios::right);
   }
   bool CC::validate(const char *name, unsigned long long cardNo, short cvv, short expMon, short expYear) const {
      bool valid = true;
      if (name == nullptr || strlen(name) < 2) { // ai fixed here, used to be strlen > 2
         valid = false;
      }
      if (cardNo < 4000000000000000ull || cardNo > 4099999999999999ull) {
         valid = false;
      }
      if (cvv < 100 || cvv > 999) {
         valid = false;
      }
      if (expMon < 1 || expMon > 12) {
         valid = false;
      }
      if (expYear < 24 || expYear > 32) {
         valid = false;
      }
      return valid;
   }
   void CC::prnNumber(unsigned long long no) const {
      cout << no / 1000000000000ull << " ";
      no %= 1000000000000ull;
      cout.fill('0');
      cout.width(4);
      cout.setf(ios::right);
      cout << no / 100000000ull << " ";
      no %= 100000000ull;
      cout.width(4);
      cout << no / 10000ull << " ";
      no %= 10000ull;
      cout.width(4);
      cout << no;
      cout.unsetf(ios::right);
      cout.fill(' ');
   }
   void CC::set() {
      m_name = nullptr; // maybe clear();
      m_cvv = 0;
      m_expMon = 0;
      m_expYear = 0;
      m_number = 0;
   }
   bool CC::isEmpty() const {
      bool empty = true;
      if(m_name == nullptr){
         empty = true;
      }
      else{
         empty = false;
      }
      return empty;
   }
   void CC::set(const char *cc_name, unsigned long long cc_no, short cvv, short expMon, short expYear) {
      clear(); // could be wrong, set to empty state
      if (validate(cc_name, cc_no, cvv, expMon, expYear)) {
         aloCopy(cc_name);
         m_number = cc_no;
         m_cvv = cvv;
         m_expMon = expMon;
         m_expYear = expYear;
      }
      else {
         set();
      }
   }
   void CC::display() const {
      if (isEmpty()) {
            cout << "Invalid Credit Card Record" << endl;
      }
      else {
         display(m_name, m_number, m_expYear, m_expMon, m_cvv);
      }
   }
   CC::CC() {
      // do i need clear() here?
      m_name = nullptr;
      m_cvv = 0;
      m_expMon = 0;
      m_expYear = 0;
      m_number = 0;
   }
   CC::CC(const char *cc_name, unsigned long long cc_no, short cvv, short expMon, short expYear) {
      // do i need clear() here?
      m_name = nullptr;
      if(validate(cc_name, cc_no, cvv, expMon, expYear)){
         aloCopy(cc_name);
         m_number = cc_no;
         m_cvv = cvv;
         m_expMon = expMon;
         m_expYear = expYear;
      }
      else{
         set();
      }
   }
   CC::~CC() {
      clear();
   }
}