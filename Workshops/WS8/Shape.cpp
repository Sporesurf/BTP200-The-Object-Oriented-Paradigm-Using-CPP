#include "Shape.h"

using namespace std;
namespace sdds
{
	void Shape::draw(std::ostream& ostr) const
	{
		return;
	}
	void Shape::getSpecs(std::istream& istr)
	{
		return;
	}
	std::ostream& operator<<(std::ostream& ostr, Shape& rhs)
	{
		rhs.draw(ostr);
		return ostr;
	}
	std::istream& operator>>(std::istream& istr, Shape& rhs)
	{
		rhs.getSpecs(istr);
		return istr;
	}
}