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
*  - Debugging and format optimization, as to why my outputs don't match the expected results.
*
**************************************************************************************/

#include <cstring> // for strlen, strcpy
#include <iomanip> // for setw
#include "Menu.h"
#include "Utils.h"
#include "constants.h"
using namespace std;
namespace seneca {
    void MenuItem::setEmpty() {
        m_content = nullptr;
        m_indent = 0;
        m_indentSize = 0;
        m_row = -1;
    }
    MenuItem::MenuItem(const char* content, size_t indent, size_t indentSize, int row) {
        bool valid = true;
        // i used ai for content check, shorter and simpler
        if (!content) {
            valid = false;
        } else {
            bool onlySpace = true;
            for (int i = 0; content[i] != '\0' && onlySpace; i++) {
                // i used ai for space check, could've check one by one manually
                if (!isspace(content[i])) {
                    onlySpace = false;
                }
            }
            if (onlySpace) valid = false;
        }
        if (indent > 4 || indentSize > 4) valid = false;
        if (row > (int)MaximumNumberOfMenuItems) valid = false;
        if (!valid) {
            setEmpty();
        } else {
            m_indent = indent;
            m_indentSize = indentSize;
            m_row = row;

            m_content = new char[strlen(content) + 1];
            strcpy(m_content, content);
        }
    }
    MenuItem::~MenuItem() {
        delete[] m_content;
    }
    MenuItem::operator bool() const {
        return m_content != nullptr;
    }
    ostream& MenuItem::display(ostream& ostr) const {
        // i used ai for empty state check, shorter and simpler
        if (!*this) {
            ostr << "??????????";
        } else {
            for (size_t i = 0; i < m_indent * m_indentSize; i++) {
                ostr << ' ';
            }
            if (m_row >= 0) {
                ostr << setw(2) << m_row << "- ";
            }
            const char* content = m_content;
            while (isspace(*content)) {
                content++;
            }
            ostr << content;
        }
        return ostr;
    }
    Menu::Menu(const char* title, const char* exitOption, size_t indent, size_t indentSize)
        : m_title(title, indent, indentSize, -1),
        m_exitOption(exitOption, indent, indentSize, 0),
        m_prompt("> ", indent, indentSize, -1)
    {
        m_indent = indent;
        m_indentSize = indentSize;
        m_numItems = 0;
        for(size_t i = 0; i < MaximumNumberOfMenuItems; i++) {
            m_items[i] = nullptr;
        }
    }
    Menu::~Menu() {
        for (size_t i = 0; i < m_numItems; i++) {
            delete m_items[i];
            m_items[i] = nullptr;
        }
    }
    Menu& Menu::operator<<(const char* menuItemContent) {
        if (m_numItems < MaximumNumberOfMenuItems) {
            m_items[m_numItems] = new MenuItem(menuItemContent, m_indent, m_indentSize, m_numItems + 1);
            m_numItems++;
        }
        return *this;
    }
    size_t Menu::select() const {
        if (m_title) {
            m_title.display() << endl;
        }
        for(size_t i = 0; i < m_numItems; i++) {
            m_items[i]->display() << endl;
        }
        m_exitOption.display() << endl;
        m_prompt.display();
        return ut.getInt(0, m_numItems);
    }
    size_t operator<<(ostream& ostr, const Menu& m) {
        size_t selection = 0;
        if (&ostr == &cout) {
            selection = m.select();
        }
        return selection;
    }
}
