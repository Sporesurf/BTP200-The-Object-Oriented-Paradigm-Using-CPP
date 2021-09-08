#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Line.h"

using namespace std;
namespace sdds
{
	Line::Line() : LblShape()
	{
		m_length = 0;
	}

	Line::Line(const char* label, int length) : LblShape(label)
	{
		m_length = length;
	}

	void Line::getSpecs(std::istream& istr)
	{
		LblShape::getSpecs(istr);
		istr >> m_length;
		istr.ignore(1000, '\n');
	}

	void Line::draw(std::ostream& ostr)const
	{

		if (m_length > 0 && label() != nullptr)
		{
			ostr << label() << '\n';
			for (int i = 0; i < m_length; i++)
				ostr << "=";
		}
	}
}
