#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include "LblShape.h"

namespace sdds
{
	class Rectangle : public LblShape
	{
		int m_width = 0;
		int m_height = 0;
	public:
		Rectangle();
		Rectangle(const char* label, int width, int height);
		void getSpecs(std::istream& istr);
		void draw(std::ostream& ostr)const;
	};
}
#endif // !SDDS_RECTANGLE_H