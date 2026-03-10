/*************************************************************************************
* OOP244 - 2261
*
* Student Name : Maximilian Ali
* Student Email : mali291@myseneca.ca
* Project #  : 1
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
*  - Debugging and code review, as to why my outputs don't match the expected results.
*
**************************************************************************************/

#ifndef SENECA_MENU_H
#define SENECA_MENU_H
#include <iostream>
#include "constants.h"
namespace seneca {
    class Menu;
    class MenuItem {
        // i used ai, {} to make sure initialize to safe empty state
        char* m_content{};
        size_t m_indent{};
        size_t m_indentSize{};
        int m_row{};
        void setEmpty();
        friend class Menu;
        MenuItem(const char* content = nullptr, size_t indent = 0, size_t indentSize = 0, int row = -1);
        ~MenuItem();
        MenuItem(const MenuItem&); // delete
        MenuItem& operator=(const MenuItem&); // delete
        operator bool() const;
        std::ostream& display(std::ostream& ostr = std::cout) const;
    };
    class Menu {
        size_t m_indent{};
        size_t m_indentSize{};
        size_t m_numItems{};
        MenuItem m_title; // {}
        MenuItem m_exitOption; // {}
        MenuItem m_prompt; // {}
        MenuItem* m_items[MaximumNumberOfMenuItems]{};
        public:
        Menu(const char* title,
            const char* exitOption = "Exit",
            size_t indent = 0,
            size_t indentSize = 3);
        ~Menu();
        Menu(const Menu&) = delete; // delete
        Menu& operator=(const Menu&) = delete; // delete
        Menu& operator<<(const char* menuItemContent);
        // std::ostream& operator<<(const char* menuItemContent);
        size_t select() const;
    };
    size_t operator<<(std::ostream& ostr, const Menu& m);
    // std::ostream& operator<<(std::ostream& ostr, const Menu& m);
}
#endif
