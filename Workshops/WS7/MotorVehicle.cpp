#include <iostream>
#include <iomanip>
#include <string.h>
#include "MotorVehicle.h"
#include "cstring.h"

using namespace std;
namespace sdds
{
	MotorVehicle::MotorVehicle(const char* licenseplate, int yearbuilt)
	{
		string os = "Factory";
		if (yearbuilt > 1000 && yearbuilt < 9999)
			m_yearbuilt = yearbuilt;
		
		if (strLen(licenseplate) + 1 <= 9)
		{
			m_licenseplate[0] = '\0';
			strCpy(m_licenseplate, licenseplate);
		}

		m_address[0] = '\0';
		strCpy(m_address, os.c_str());
	}

	void MotorVehicle::moveTo(const char* address)
	{
		if (strCmp(m_address, address) != 0 && (strLen(address) <= 63))
		{
			cout << "|" << setw(8) << right << m_licenseplate << "| |" << setw(20) << 
				right << m_address << " ---> " << setw(20) << left <<address << "|" << endl;

			m_address[0] = '\0';
			strCpy(m_address, address); 
		}
	}

	std::ostream& MotorVehicle::write(std::ostream& os) const
	{
		os << "| " << m_yearbuilt << " | " << m_licenseplate << " | " << m_address;
		return os;
	}

	std::istream& MotorVehicle::read(std::istream& in)
	{
		cout << "Built year: ";
		in >> m_yearbuilt; 
		cout << "License plate: ";
		in >> m_licenseplate;
		cout << "Current location: ";
		in >> m_address;
		return in;
	}

	std::ostream& operator<<(std::ostream& os, const MotorVehicle& rhs)
	{
		rhs.write(os);
		return os;
	}

	std::istream& operator>>(std::istream& in, MotorVehicle& rhs)
	{
		rhs.read(in);
		return in;
	}
}