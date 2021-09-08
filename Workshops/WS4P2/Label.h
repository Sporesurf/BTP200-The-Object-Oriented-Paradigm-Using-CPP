#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
#include <iostream>

namespace sdds
{
	class Label
	{
		char* m_content = nullptr; 
		char m_frame[21] = {};
	public:
		Label();
		Label(const char* frameArg);
		Label(const char* frameArg, const char* content);

		void readLabel();
		std::ostream& printLabel()const;

		~Label();
	
		void setEmpty();
		void setFrame(const char*);
		void setContent(const char*);
	};
}
#endif // !SDDS_LABEL_H
