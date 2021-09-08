#ifndef SDDS_TRUCK_H
#define SDDS_TRUCK_H
#include <iostream>
#include "MotorVehicle.h"

namespace sdds
{
	class Truck : public MotorVehicle
	{
		double m_cargocapacity = 0.0;
		double m_currentcargo = 0.0;
	public:
		Truck(const char* licenseplate, int yearbuilt, double cargocapacity, const char* address);
		bool addCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& os, const Truck& rhs);
	std::istream& operator>>(std::istream& in, Truck& rhs);
}
#endif// !SDDS_TRUCK_H

