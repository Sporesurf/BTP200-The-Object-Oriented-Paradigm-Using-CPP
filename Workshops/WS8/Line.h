#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include "LblShape.h"

namespace sdds
{
	class Line : public LblShape
	{
		int m_length = 0;
	public:
		Line();
		Line(const char* label, int length);
		void getSpecs(std::istream& istr); 
		void draw(std::ostream& ostr)const;
	};
}
#endif // !SDDS_LINE_H