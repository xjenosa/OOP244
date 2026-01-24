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
* I used AI to help me with the following:
*  - Debugging and format optimization, as to why my outputs don't match the expected results.
*
**************************************************************************************/

#include "cstr.h"
#include "dma.h"

namespace seneca{
    struct Samples *CreateSamples(const char *title){
        Samples *s = new Samples;
        s->m_title = new char[strlen(title) + 1]; // could be title + 1
        strcpy(s->m_title, title);
        s->m_data = nullptr;
        s->m_size = 0;
        return s;
    }
    
    void add(Samples &S, const int data[], int size){
        if(S.m_data == nullptr){
            S.m_data = new int[size];
            for(int i = 0; i < size; i++){
                S.m_data[i] = data[i];
            }
            S.m_size = size;
        } else {
            append(S.m_data, S.m_size, data, size);
            S.m_size += size;
        }
    }

    void append(int *&data, int size, const int appendedData[], int dataSize){
        int *buff = new int[size + dataSize];
        for(int i = 0; i < size; i++){
            buff[i] = data[i];
        }
        for(int i = 0; i < dataSize; i++){
            buff[size + i] = appendedData[i];
        }
        delete [] data;
        data = buff;
    }

    void freemem(Samples *&s){
        delete [] s->m_title;
        delete [] s->m_data;
        delete s;
        s = nullptr;
    }
}