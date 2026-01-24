// box.cpp file
#include "box.h"
#include <iostream>
using namespace std;

namespace seneca{
    void Box::setWidth(double width) {
        if(m_width > 0){
            m_width = width;
        } else {
            m_width = 0;
        }
    }
    void Box::setHeight(double height) {
        if(height > 0){
            m_height = height;
        } else {
            m_height = 0;
        }
    }
    void Box::setSize(double width, double height) {
        setWidth(width);
        setHeight(height);
    }

    double Box::getWidth() const {
        return m_width;
    }

    double Box::getHeight() const {
        return m_height;
    }

    double Box::area() const {
        return m_width * m_height;
    }

    void Box::display() const {
        cout << "Width: " << m_width
        << ", Height: " << m_height
        << ", Area: " << area() << endl;
    }

    void modifyByValue(Box b) {
        cout << "Modify by Value Before" << endl;
        b.display();
        b.setSize(999, 999);
        cout << "Modify by Value After" << endl;
        b.display();
    }

    void modifyByPointer(Box *b) {
        cout << "Modify by Pointer Before" << endl;
        b->display();
        b->setSize(999, 999);
        cout << "Modify by Pointer After" << endl;
        b->display();
    }

    void modifyByReference(Box &b) {
        cout << "Modify by Reference Before" << endl;
        b.display();
        b.setSize(999, 999);
        cout << "Modify by Reference After" << endl;
        b.display();
    }

    int main() {
        Box b1;
        Box b2;

        b1.setSize(5.0, 10.0);
        b2.setSize(3.0, 6.0);

        modifyByValue(b1);
        modifyByPointer(&b2);
        modifyByReference(b1);

        b1.display();
        b2.display();
        return 0;
    }
}