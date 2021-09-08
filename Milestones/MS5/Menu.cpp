/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.cpp
Version 1.0
Author	Vlado Tomovic
Revision History
-----------------------------------------------------------
Date      Reason
2021/06/27  Preliminary release
2021/07/10  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"
#include "utils.h"

using namespace std;
namespace sdds
{
    Menu::Menu(const char* MenuContent, int NoOfSelections)
    {
        delete[] m_text;
        if (MenuContent != nullptr)
        {
            int size = strlen(MenuContent) + 1;
            m_text = new char[size];
            strcpy(m_text, MenuContent);
        }
        m_noOfSel = NoOfSelections;
    }

    Menu::Menu(const Menu& src)
    {
        operator=(src);
    }
    
    Menu& Menu::operator=(const Menu& src) 
    {
        if (this != &src)
        {
            delete[] m_text;
            m_text = new char[strlen(src.m_text) + 1];
            strcpy(m_text, src.m_text);
            m_noOfSel = src.m_noOfSel;
        }
        return *this;
    }

    void Menu::display() const
    {
        if (m_text != nullptr)
        {
            cout << m_text << endl << "0- Exit" << endl;
        }
    }

    int& Menu::operator>>(int& Selection)
    {
        display();
        return Selection = getInt(0, m_noOfSel, "> ", "Invalid option ", true);
    }

    Menu::~Menu()
    {
        delete[] m_text;
        m_text = nullptr;
    }
}
