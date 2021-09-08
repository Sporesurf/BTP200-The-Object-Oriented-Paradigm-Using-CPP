/* Citation and Sources...
Final Project Milestone ?
Module: utils
Filename: utils.h
Version 1.0
Author	Vlado Tomovic
Revision History
-----------------------------------------------------------
Date      Reason
2021/06/27  Preliminary release
2021/07/15  Completed basic implementation, now have to debug errors.
2021/07/20  strlen(str.c_str() + 1) instead of strlen(str.cstr()) + 1 in size on read had me debugging for 3 days.
2021/07/20  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include "Patient.h"
#include "utils.h"

using namespace std;
namespace sdds
{
	Patient::Patient(int ticketnum, bool fileIO) : m_ticket(ticketnum)
	{
		m_patientname = nullptr;
		m_ohip = 0;
		m_patientflag = fileIO;
	}

	Patient::~Patient()
	{
		delete[] m_patientname;
		m_patientname = nullptr;
	}

	char Patient::type() const
	{
		return 'W';
	}

	bool Patient::fileIO() const
	{
		return m_patientflag;
	}

	bool Patient::fileIO(bool patientFlag)
	{
		m_patientflag = patientFlag;
		return m_patientflag;
	}

	bool Patient::operator==(char incChar)const
	{
		if (type() == incChar)
			return true;
		else
		return false;
	}

	bool Patient::operator==(const Patient& rhs)const
	{
		if (type() == rhs.type())
			return true;
		else
		return false;
	}

	void Patient::setArrivalTime()
	{
		m_ticket.resetTime();
	}

	Patient::operator Time()const 
	{
		return m_ticket.operator Time();
	}

	int Patient::number()const
	{
		return m_ticket.number();
	}

	std::ostream& Patient::csvWrite(std::ostream& ostr) const
	{
		ostr << type() << ',' << m_patientname << ',' << m_ohip << ',';
		m_ticket.csvWrite(ostr);
		return ostr;
	}

	std::istream& Patient::csvRead(std::istream& istr)
	{
		string str;
		getline(istr, str, ',');
		int size = str.length() + 1;

		delete[] m_patientname;
		m_patientname = new char[size];
		strcpy(m_patientname, str.c_str());
		istr.clear();

		getline(istr, str, ',');
		stringstream ss(str);

		if ((strlen(str.c_str()) <= 10 && isValid(str)))
		{
			ss >> m_ohip;
		}
		
		m_ticket.csvRead(istr);
		return istr;
	}

	std::ostream& Patient::write(std::ostream& ostr)const
	{
		if (m_patientflag)
			csvWrite(ostr);
		else
		{
			m_ticket.write(ostr) << '\n'; 
			for (unsigned int i = 0; i < 25; i++)
			{
				if (m_patientname[i] == '\0')break;
				else if (m_patientname[i] != '\n') ostr << m_patientname[i];
			}
			ostr << ", OHIP: " << m_ohip;
		}
		return ostr;
	}

	std::istream& Patient::read(std::istream& istr)
	{
		if (m_patientflag)
			csvRead(istr);
		else
		{
			string str;
			cout << "Name: ";
			getline(istr, str);
			int size = str.length() + 1;

			delete[] m_patientname;
			m_patientname = new char[size];
			strcpy(m_patientname, str.c_str());
			istr.clear();

			cout << "OHIP:";
			m_ohip = getInt(100000000, 999999999, nullptr, "Invalid OHIP Number, ", true);
		}
		return istr;
	}
}
