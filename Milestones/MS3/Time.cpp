/* Citation and Sources...
Final Project Milestone ?
Module: Time
Filename: Time.cpp
Version 1.1
Author	Vlado Tomovic
Revision History
-----------------------------------------------------------
Date      Reason
2021/06/27  Preliminary release
2021/07/06  Debugged DMA
2021/07/20 was being read into cin and istr, fixed everything TOOK 3 DAYS TO FIND X_X
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#include <iomanip>
#include "Time.h"
#include "utils.h"

using namespace std;
namespace sdds 
{
	bool DEBUG = false;
	Time& Time::setToNow()
	{
		m_min = getTime();
		return *this;
	}

	Time::Time(unsigned int min)
	{
		m_min = min;
	}

	std::ostream& Time::write(std::ostream& ostr) const
	{
		int t_hrs = m_min / 60; 
		int t_mins = m_min % 60; 
		ostr << setfill('0') << setw(2) << t_hrs << ":" <<setw(2) << t_mins;
		return ostr;
	}

	std::istream& Time::read(std::istream& istr)
	{
		int mins = 0, hrs = 0;
		char delim = '\0'; 
		istr >> hrs >> delim >> mins;
		if (hrs < 0 || mins < 0 || delim != ':')
		{
			istr.setstate(ios::failbit); 
			if (DEBUG == true)
			cout << "DEBUG::FAILBIT(TIME:read)";
		}
		else
		{
			m_min = hrs * 60 + mins;
			istr.setstate(ios::goodbit);
		}
		return istr;
	}

	Time& Time::operator-=(const Time& D)
	{
		if (m_min < D.m_min)
		{
			do
			{
				m_min += 1440;
			} while (m_min < D.m_min);
			m_min -= D.m_min;
		}
		else
		{
			m_min -= D.m_min;
		}
		return *this;
	}

	Time Time::operator-(const Time& D) const
	{
		Time temp;
		temp.m_min = m_min;
		if (temp.m_min < D.m_min)
		{
			do
			{
				temp.m_min += 1440;
			} while (temp.m_min < D.m_min);
			temp.m_min -= D.m_min;
		}
		else
		{
			temp.m_min -= D.m_min;
		}
		return temp;
	}

	Time& Time::operator+=(const Time& D)
	{
		m_min += D.m_min;
		return *this;
	}

	Time Time::operator+(const Time& D) const
	{
		Time sum;
		sum.m_min = m_min + D.m_min;
		return sum;
	}

	Time& Time::operator=(unsigned int val)
	{
		m_min = val;
		return *this;
	}

	Time& Time::operator*=(unsigned int val)
	{
		m_min *= val;
		return *this;
	}

	Time& Time::operator/=(unsigned int val)
	{
		m_min /= val;
		return *this;
	}

	Time Time::operator*(unsigned int val) const
	{
		Time product;
		product.m_min = m_min * val;
		return product;
	}

	Time Time::operator/(unsigned int val) const
	{
		Time sum;
		sum.m_min = m_min / val;
		return sum;
	}

	Time::operator unsigned int() const
	{
		int castedmin = m_min;
		return castedmin;
	}

	Time::operator int() const
	{
		return m_min;
	}

	std::ostream& operator<<(std::ostream& ostr, const Time& D)
	{
		D.write(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Time& D)
	{
		D.read(istr);
		return istr;
	}
}