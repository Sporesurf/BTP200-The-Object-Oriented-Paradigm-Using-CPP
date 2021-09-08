#include <iostream>
#include "Mark.h"
using namespace std;
namespace sdds
{
	Mark::Mark()
	{
		m_mark = 0;
	}

	Mark::Mark(int mark)
	{
		if (*this)
		{
			m_mark = mark;
		}
		else {
			m_mark = -1;
		}
	}

	Mark::operator bool()const
	{
		if (m_mark >= 0 && m_mark <= 100)
		{
			return true;
		}
		return false;
	}

	Mark::operator int()const
	{
		if (*this)
		{
			return m_mark;
		}
		return 0;
	}

	Mark::operator double()const
	{
		 if (m_mark >= 50 && m_mark < 60)
		 {
			return 1.0;
		 }
		else if (m_mark >= 60 && m_mark < 70)
		{
			return 2.0;
		}
		else if (m_mark >= 70 && m_mark < 80)
		{
			return 3.0;
		}
		else if (m_mark >= 80 && m_mark <= 100)
		{
			return 4.0;
		}
		else {
			return 0.0;
		}
	}

	Mark& Mark::operator+=(int added)
	{
		if (*this)
		{
			m_mark += added;
		}
		return *this;
	}

	Mark& Mark::operator=(int newMark)
	{
		m_mark = newMark;
		return *this;
	}

	Mark::operator char()const
	{
		if (m_mark >= 0 && m_mark < 50)
		{
			return 'F';
		}
		else if (m_mark >= 50 && m_mark < 60)
		{
			return 'D';
		}
		else if (m_mark >= 60 && m_mark < 70)
		{
			return 'C';
		}
		else if (m_mark >= 70 && m_mark < 80)
		{
			return 'B';
		}
		else if (m_mark >= 80 && m_mark <= 100)
		{
			return 'A';
		}
		else {
			return 'X';
		}
	}

	int operator+=(int& m_mark, const Mark& rhs)
	{
		if (rhs)
		{
			m_mark += rhs.operator int();
		}
		return m_mark;
	}
}