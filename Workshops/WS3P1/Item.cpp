#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "Item.h"

using namespace std;
namespace sdds 
{
	void Item::setName(const char* name)
	{
		strnCpy(m_itemName, name, 20);
		m_itemName[20] = '\0';
	}

	void Item::setEmpty()
	{
		m_price = 0.0;
		m_itemName[0] = '\0';
	}

	void Item::set(const char* name, double price, bool taxed)
	{
		setName(name);
		m_price = price;
		m_taxed = taxed;
		if ((price < 0) || (name == nullptr))
		{
			setEmpty();
		}
	}

	double Item::price()const
	{
		return m_price;
	}

	double Item::tax()const
	{
		return m_taxed ? m_price * 0.13 : 0.0;
	}

	bool Item::isValid()const
	{
		if ((m_price > 0.0) && (m_itemName[0] != '\0'))
		{
			return true;
		}
		return false;
	}

	void Item::display()const
	{
		if (isValid())
		{
			cout << "| " << setw(20) << setfill('.') << left << m_itemName << " | ";
			cout << setw(7) << right << setfill(' ') << fixed << setprecision(2) << m_price << " | " << left;
			m_taxed ? cout << "Yes |" : cout << "No  |";
			cout << endl;
		}
		else
		{
			cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
		}
	}
}