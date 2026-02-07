/***********************************************************************
// OOP244 Workshop 4 lab: Account Module
//
// File	Account.h
// Version 0.5
// Date	2025/06/03
// Partialy implemented by	Fardad Soleimanloo
// to be completed by the students
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
* I used AI to help me with the following:
*  - Debugging and format optimization, as to why my outputs don't match the expected results.
*
**************************************************************************************/

#ifndef SENECA_ACCOUNT_H_
#define SENECA_ACCOUNT_H_
#include <iostream>

namespace seneca {
   const int NameMaxLen = 30;
   class Account {
      double m_balance;
      int m_number;
      char m_holderName[NameMaxLen + 1];
      void cpyName(const char* src); // copies the src into the m_holderName array
      bool isValidNumber(int number)const; // returns true if number is a valid account number
   public:
      Account(const char* holderName = nullptr);
      Account(const char* holderName, int number, double balance);
      std::ostream& display()const;


   };
  

}
#endif // SENECA_ACCOUNT_H_