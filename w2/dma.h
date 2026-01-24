/*************************************************************************************
* OOP244 - 2261
*
* Student Name : Maximilian Ali
* Student Email : mali291@myseneca.ca
* Workshop #  : 2
* Course/Section: OOP244/NRA
*
* I declare that this assignment is my own work in accordance with the Seneca Academic
* Policy. No part of this assignment has been copied manually or electronically from/to
* any other source (including web sites) or distributed to other students.
*
* I have done all the coding by myself and only copied the code that my professor
* provided to complete my workshops and assignments.
*
**************************************************************************************/

#ifndef SENECA_DMA_H
#define SENECA_DMA_H

namespace seneca{
    struct Samples {
    char* m_title;   // Dynamically allocated title
    int* m_data;     // Dynamically allocated array of integers
    int m_size;   // Number of elements in m_data
    };

    struct Samples* CreateSamples(const char *title);
    void add(Samples &S, const int data[], int size);
    void append(int *&data, int size, const int appendedData[], int dataSize);
    void freemem(Samples *&s);
}

#endif // !SENECA_DMA_H