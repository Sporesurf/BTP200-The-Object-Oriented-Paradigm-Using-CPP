#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  
#include "Canister.h"

const double PI = 3.14159265;
using namespace std;
namespace sdds 
{
	void Canister::setToDefault()
	{
		m_contentName = nullptr;
		m_height = 13.0;
		m_diameter = 10.0;
		m_contentVolume = 0.0;
		m_usable = true;
	}

	void Canister::setName(const char* Cstr)
	{
		if ((Cstr != nullptr) && (isEmpty() == true))
		{
			int size = strLen(Cstr) + 1;
			delete[] m_contentName;
			m_contentName = new char[size];
			strCpy(m_contentName, Cstr);
		}
	}

	bool Canister::isEmpty()const
	{
		if (m_contentVolume < 0.00001)
		{
			return true;
		}
		return false;
	}

	bool Canister::hasSameContent(const Canister& C)const
	{	
		if ((strCmp(m_contentName, C.m_contentName) == 0) && m_contentName != nullptr)
		{
			return true;
		}
		return false;
	}

	Canister::Canister()
	{
		setToDefault();
	}

	Canister::Canister(const char* contentName)
	{
		setToDefault();
		setName(contentName);
	}

	Canister::Canister(double height, double diameter, const char* contentName)
	{
		setToDefault();
		if ((height >= 10.0 && diameter >= 10.0) && (height <= 40.0 && diameter <= 30.0))
		{
			m_height = height;
			m_diameter = diameter;
			setName(contentName);
		}
		else
		{
			m_usable = false;
		}
	}

	Canister::~Canister()
	{
		delete[] m_contentName;
		m_contentName = nullptr;
	}

	Canister& Canister::setContent(const char* contentName)
	{
		if (contentName == nullptr)
		{
			m_usable = false;
		}
		else if (isEmpty() == true)
		{
			setName(contentName);
		} 
		else if (strCmp(m_contentName, contentName) != 0)
		{
			m_usable = false;
		}
		return *this;
	}

	Canister& Canister::pour(double quantity)
	{
		if ((m_usable == true) && (quantity > 0) && (quantity + volume() <= capacity()))
		{
			m_contentVolume += quantity;
		}
		else
		{
			m_usable = false;
		}
		return *this;
	}

	Canister& Canister::pour(Canister& C)
	{
		setContent(C.m_contentName);
		if (C.volume() > (capacity() - volume()))
		{
			C.m_contentVolume -= (capacity() - volume());
			m_contentVolume = capacity();
		}
		else
		{
			pour(C.m_contentVolume);
			C.m_contentVolume = 0.0;
		}
		return *this;
	}

	double Canister::volume()const
	{
		return m_contentVolume;
	}

	std::ostream& Canister::display() const
	{
		if (m_usable == false)
		{
			return cout << setprecision(1) << setw(7) << fixed << capacity() << "cc (" << m_height
				<< "x" << m_diameter << ") Canister of Unusable content, discard!";
		}
		else if (m_contentName != nullptr)
		{
			return cout << setprecision(1) << setw(7) << fixed << capacity() << "cc (" << m_height
				<< "x" << m_diameter << ") Canister of " << setw(7) << m_contentVolume << "cc   " << m_contentName;
		}
		else
		{
			return cout << setprecision(1) << setw(7) << fixed << capacity() << "cc (" << m_height << "x" << m_diameter << ") Canister";
		}
	}

	double Canister::capacity()const
	{
		return (PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2));
	}

	void Canister::clear()
	{
		delete[] m_contentName;
		m_contentName = nullptr;
		m_contentVolume = 0.0;
		m_usable = true;
	}
}