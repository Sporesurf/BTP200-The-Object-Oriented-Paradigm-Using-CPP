#include <iostream>
#include "Truck.h"

using namespace std;
namespace sdds
{
	Truck::Truck(const char* licenseplate, int yearbuilt, double cargocapacity,
		const char* address) : MotorVehicle(licenseplate, yearbuilt)
	{
		m_currentcargo = 0;
		m_cargocapacity = cargocapacity;
		MotorVehicle::moveTo(address);
	}

	bool Truck::addCargo(double cargo)
	{
		bool isValid = false;
		if (m_currentcargo < m_cargocapacity && m_currentcargo != m_cargocapacity)
		{
			if (m_currentcargo + cargo <= m_cargocapacity)
			{	
				m_currentcargo += cargo;
				isValid = true;
			}
			if (m_currentcargo + cargo > m_cargocapacity)
			{
				m_currentcargo = m_cargocapacity;
				isValid = true;
			}
		}
		return isValid;
	}

	bool Truck::unloadCargo()
	{
		if (m_currentcargo != 0)
		{
			m_currentcargo = 0;
			return true;
		}
		return false;
	}

	std::ostream& Truck::write(std::ostream& os)const
	{
		MotorVehicle::write(os);
		os << " | " << m_currentcargo << "/" << m_cargocapacity;
		return os;
	}

	std::istream& Truck::read(std::istream& in)
	{
		MotorVehicle::read(in);
		cout << "Capacity: ";
		in >> m_cargocapacity;
		cout << "Cargo: ";
		in >> m_currentcargo;
		return in;
	}

	std::ostream& operator<<(std::ostream& os, const Truck& rhs)
	{
		rhs.write(os);
		return os;
	}

	std::istream& operator>>(std::istream& in, Truck& rhs)
	{
		rhs.read(in);
		return in;
	}
}
