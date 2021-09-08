#include <iostream>
#include <iomanip>
#include "Food.h"
#include "cstring.h"

using namespace std;
namespace sdds
{
	void Food::setName(const char* name)
	{
		strnCpy(m_name, name, 30);
		m_name[30] = '\0';
	}

	void Food::setEmpty()
	{
		m_name[0] = '\0';
		m_cals = 0;
		m_consumption[0] = '\0';
	}

	void Food::set(const char* name, int cals, int consumption) 
	{
		setName(name);
		m_cals = cals;
		if (consumption == 1)
		{
			strCpy(m_consumption, "Breakfast"); 
		}
		else if (consumption == 2)
		{
			strCpy(m_consumption, "Lunch");
		}
		else if (consumption == 3)
		{
			strCpy(m_consumption, "Dinner");
		} 
		else if (consumption == 4)
		{
			strCpy(m_consumption, "Snack");
		}
		 else if ((cals <= 0 && cals > 3000) && (name == nullptr) && (consumption <= 0 && consumption > 4))
		{
			setEmpty();
		}
	}

	int Food::calories()const
	{
		return m_cals;
	}

	bool Food::isValid()const 
	{
		if ((m_cals > 0 && m_cals <= 3000) && (m_name[0] != '\0'))
		{
			return true;
		}
		return false;
	}

	void Food::display()const
	{
		if (isValid())
		{
			cout << "| " << setw(30) << setfill('.') << left << m_name << " | ";
			cout << setw(4) << right << setfill(' ') << fixed << m_cals << " | ";
			cout << setw(10) << left << setfill(' ') << m_consumption << " |" << endl;
		}
		else
		{
			cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
		}
	}
}