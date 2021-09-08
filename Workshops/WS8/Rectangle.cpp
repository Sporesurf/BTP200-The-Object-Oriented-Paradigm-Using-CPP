#include <iostream>
#include <sstream>
#include <cstring>
#include <iomanip>
#include "Rectangle.h"

using namespace std;
namespace sdds
{
	Rectangle::Rectangle()
	{
		m_width = 0;
		m_height = 0;
	}

	Rectangle::Rectangle(const char* label, int width, int height) : LblShape(label)
	{
		m_width = width;
		m_height = height;
		int size = strlen(LblShape::label()) + 2;

		if (m_height < 3 || m_width < size)
		{
			m_width = 0;
			m_height = 0;
		}
	}

	void Rectangle::getSpecs(std::istream& istr)
	{
		string str;
		stringstream ss(str);
		LblShape::getSpecs(istr);

		getline(istr, str, ',');
		ss << str;
		ss >> m_width;
		istr.clear();
		ss.clear();

		getline(istr, str);
		ss << str;
		ss >> m_height;
		istr.clear();
		ss.clear();
	}

	void Rectangle::draw(std::ostream& ostr) const
	{
		int width = m_width - 2;
		if (m_width > 0 && m_height > 0)
		{
			//---------------------Line 1---------------------
			ostr << '+';
			for (int i = 0; i < width; i++)
			{
				ostr << '-';
			}
			ostr << '+' << endl;
			//---------------------Line 2---------------------
			ostr << "|" << setfill(' ') << left << setw(width) << label() << "|" << endl;
			
			//---------------------Line 3+---------------------
			for (int i = 0; i < m_height - 3; i++)
			{
				ostr << '|';
				for (int j = 0; j < width; j++)
				{
					ostr << " ";
				}
				ostr << '|' << endl;
			}
			
			//---------------------LINE 4---------------------
			ostr << '+';
			for (int i = 0; i < width; i++)
			{
				ostr << '-';
			}
			ostr << '+';
		}
	}
}