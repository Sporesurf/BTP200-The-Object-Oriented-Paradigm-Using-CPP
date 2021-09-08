/* Citation and Sources...
Final Project Milestone ?
Module: utils
Filename: utils.cpp
Version 1.0
Author	Vlado Tomovic
Revision History
-----------------------------------------------------------
Date      Reason
2020/06/27  Preliminary release
2020/07/06  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
#include <sstream>

using namespace std;
namespace sdds 
{
    bool debug = false;  // made global in utils.h
    int getTime() 
    {
        int mins = -1;
        if (debug) 
        {
            Time t(0);
            cout << "Enter current time: ";
            do 
            {
                cin.clear();
                cin >> t;   // needs extraction operator overloaded for Time
                if (!cin) 
                {
                    cout << "Invlid time, try agian (HH:MM): ";
                    cin.clear();
                }
                else
                {
                    mins = int(t);
                }
                cin.ignore(1000, '\n');
            } while (mins < 0);
        }
        else 
        {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            mins = lt.tm_hour * 60 + lt.tm_min;
        }
        return mins;
    }

    bool isValid(string& str)
    {
        int size = str.length();
        for (auto i = 0; i < size; i++)
        {
            if (isdigit(str[i]) == false)
            {
                return false;
            }
        }
        return true;
    }

    int getInt(const char* prompt)
    {   
        string str;
        int validint = 0;

        if (prompt != nullptr)
        {
            cout << prompt;
        }

        while (getline(cin, str))
        {
            stringstream ss(str);
            if (!isValid(str))
            {
                if (!isdigit(str[0]))
                {
                    cout << "Bad integer value, try again: ";
                }
                else if (!ss.eof())
                {
                    cout << "Enter only an integer, try again: ";
                }
            }
            else
            {
                ss >> validint;
                return validint;
            }
        }
        return 0;
    }

    int getInt(int min, int max, const char* prompt, 
        const char* errorMessage, bool showRangeAtError)
    {
        string str;
        int validint = 0;
        if (prompt != nullptr)
        {
            cout << prompt;
        }
        while (getline(cin, str))
        {
            stringstream ss(str);
            if (isValid(str))
            {
                ss >> validint;
                if (validint >= min && validint <= max)
                {
                    return validint;
                } 
                else 
                {
                    if (errorMessage != nullptr)
                        cout << errorMessage;
                    if (showRangeAtError)
                        cout << "[" << min << " <= value <= " << max <<"]: ";
                }
            }
            else
            {
                if (!isValid(str))
                {
                    if (!isdigit(str[0]))
                    {
                        cout << "Bad integer value, try again: ";
                    }
                    else if (!ss.eof())
                    {
                        cout << "Enter only an integer, try again: ";
                    }
                }
            }
        }
        return 0;
    }


    char* getcstr(const char* prompt, std::istream& istr, char delimiter)
    {
        string str;
        char* n_str = nullptr;
        if (prompt != nullptr)
        {

            cout << prompt;
            getline(istr, str, delimiter);
            n_str = new char[str.length() + 1];
            strcpy(n_str, str.c_str());
        }
        return n_str;
    }
}