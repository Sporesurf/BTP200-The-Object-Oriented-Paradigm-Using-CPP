/* Citation and Sources...
Final Project Milestone ?
Module: Time
Filename: Time.h
Version 1.0
Author	Vlado Tomovic
Revision History
-----------------------------------------------------------
Date      Reason
2021/06/27  Preliminary release
2021/07/10 Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#include <iostream>
#include "IOAble.h"

namespace sdds
{
	std::ostream& operator<<(std::ostream& ostr, const IOAble& s)
	{
		s.write(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, IOAble& s)
	{
		s.read(istr);
		return istr;
	}
}
