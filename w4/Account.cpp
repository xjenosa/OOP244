/***********************************************************************
// OOP244 Workshop 4 lab: Account Module
//
// File	Account.cpp
// Version 0.5
// Date	2025/06/03
// Partialy implemented by	Fardad Soleimanloo
// to be completed by the students
// You may modify any code in this file to suit your requirements.
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
* I have received help from the following students:
*  - Christian Rafael / NCC
*
* I used AI to help me with the following:
*  - Debugging and format optimization, as to why my outputs don't match the expected results.
*
**************************************************************************************/

#include <iostream>
#include "Account.h"

using namespace std;
namespace seneca {
   void Account::cpyName(const char* src) {
      int i;
      for (i = 0; src && src[i] && i < NameMaxLen; i++) {
         m_holderName[i] = src[i];
      }
      m_holderName[i] = char(0);
   }
   bool Account::isValidNumber(int number) const {
      return number >= 10000 && number <= 99999;
   }
   Account::Account(const char* holderName) {  
      m_holderName[0] = char(0);
      m_number = -1;
      m_balance = 0.0;
      if (holderName && holderName[0]) {
         cpyName(holderName);
         m_number = 0;
      }
   }
   Account::Account(const char* holderName, int number, double balance ) {
      m_holderName[0] = char(0);
      m_number = -1;
      m_balance = 0.0;
      if (holderName && holderName[0] && isValidNumber(number)
         && balance > 0) {
         cpyName(holderName);
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout.fill(' ');
         cout.width(NameMaxLen);
         cout.setf(ios::left);
         cout << m_holderName;
         cout.unsetf(ios::left);
         cout << " | ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << " ";
         cout.fill(' ');
         cout.width(30);
         cout.setf(ios::left);
         cout << m_holderName;
         cout.unsetf(ios::left);
         cout << " |  NEW  |         0.00 ";
      }
      else {
         cout << " Bad Account                    | ----- | ------------ ";
      }
      return cout;
   }
   Account::operator bool() const {
    return isValidNumber(m_number);
   }

   Account::operator int() const {
      return m_number;
   }

   Account::operator double() const {
      return m_balance;
   }

   Account::operator const char* () const {
      return m_holderName;
   }
   char& Account::operator[](int index) {
      int len = strlen(m_holderName);
      if (len > 0) {
         index %= len;
         if (index < 0) index += len;
      } else {
         index = 0;
      }
      return m_holderName[index];
   }
   const char Account::operator[](int index) const {
      int len = strlen(m_holderName);
      if (len > 0) {
         index %= len;
         if (index < 0) index += len;
      } else {
         index = 0;
      }
      return m_holderName[index];
   }
   Account &Account::operator=(int value) {
      if(m_number == 0) {
         if(isValidNumber(value)) {
            m_number = value;
         } else {
            m_number = -1;
         }
      }
      return *this;
   }
   Account &Account::operator=(double value){
      if(value >= 0) {
         m_balance = value;
      } else {
         m_balance = 0.0;
      }
      return *this;
   }
   Account &Account::operator+=(double value){
      if(value > 0) {
         m_balance += value;
      }
      return *this;
   }
   Account &Account::operator-=(double value){
      if(value > 0 && m_balance >= value) {
         m_balance -= value;
      }
      return *this;
   }
   Account &Account::operator<<(Account& other){
      if(this != &other && other) {
         double transferAmount = other.m_balance;
         m_balance += transferAmount;
         other.m_balance = 0.0;
      }
      return *this;
   }
   Account &Account::operator>>(Account& other){
      if(this != &other && other) {
         double transferAmount = m_balance;
         other.m_balance += transferAmount;
         m_balance = 0.0;
      }
      return *this;
   }
   bool Account::operator~() const{
      return m_holderName[0] != '\0' && m_number != 0 && m_balance == 0.0;
   }
   Account& Account::operator++(){ // prefix
      if(*this) {
         m_balance += 1.0;
      }
      return *this;
   }
   Account Account::operator++(int){ // postfix
      Account temp = *this;
      if(*this) {
         m_balance += 1.0;
      }
      return temp;
   }
   Account& Account::operator--(){ // prefix
      if(*this) {
         m_balance -= 1.0;
         if(m_balance < 0) {
            m_balance = 0.0;
         }
      }
      return *this;
   }
   Account Account::operator--(int){ // postfix
      Account temp = *this;
      if(*this) {
         m_balance -= 1.0;
         if(m_balance < 0) {
            m_balance = 0.0;
         }
      }
      return temp;
   }
}