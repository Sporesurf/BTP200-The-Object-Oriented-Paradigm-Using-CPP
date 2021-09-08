#ifndef SDDS_MOTORVEHICLE_H
#define SDDS_MOTORVEHICLE_H
#include <iostream>

namespace sdds
{
	class MotorVehicle
	{
		char m_licenseplate[9]{};
		char m_address[64]{};
		int m_yearbuilt = 0;
	public:
		MotorVehicle(const char* licenseplate, int yearbuilt);
		void moveTo(const char* address);
		std::ostream& write(std::ostream& os)const; 
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& os, const MotorVehicle& rhs);
	std::istream& operator>>(std::istream & in, MotorVehicle& rhs);
}
#endif // !SDDS_MOTORVEHICLE_H

