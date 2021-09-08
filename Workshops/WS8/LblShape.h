#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include "Shape.h"

namespace sdds
{
	class LblShape : public Shape
	{
		char* m_label = nullptr;
	protected:
		const char* label()const;
		LblShape();
		LblShape(const char* label);
		LblShape(const LblShape& src) = delete;
		LblShape& operator=(const LblShape& src) = delete;
		~LblShape();
		void getSpecs(std::istream& istr);
	};

}
#endif // !SDDS_LBLSHAPE_H




