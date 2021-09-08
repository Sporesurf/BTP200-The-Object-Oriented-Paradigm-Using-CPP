#ifndef SDDS_MARK_H
#define SDDS_MARK_H
namespace sdds
{
	class Mark
	{
		int m_mark = 0;
	public:
		Mark();
		Mark(int mark);

		operator int()const;
		operator bool()const;
		operator double()const;
		operator char()const;

		Mark& operator+=(int m_added);
		Mark& operator=(int m_newMark);
	};
	int operator +=(int& m_mark, const Mark& rhs);
}
#endif