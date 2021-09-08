#include <iostream>
#include <cstring>
#include <string>
#include "LblShape.h"

using namespace std;
namespace sdds
{
	const char* LblShape::label() const
	{
		return m_label;
	}

	LblShape::LblShape()
	{
		m_label = nullptr;
	}

	LblShape::LblShape(const char* label)
	{
		if (label != nullptr)
		{
			delete[] m_label;
			int size = strlen(label) + 1;
			m_label = new char[size];
			strcpy(m_label, label);
		}
	}

	LblShape::~LblShape()
	{
		delete[] m_label;
	}

	void LblShape::getSpecs(std::istream& istr)
	{
		
		string str;
		getline(istr, str, ',');

		delete[] m_label;
		int size = strlen(str.c_str()) + 1;
		m_label = new char[size];
		strcpy(m_label, str.c_str());
	}
}