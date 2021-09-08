#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "Bill.h"

using namespace std;
namespace sdds 
{
	void Bill::setEmpty()
	{
		m_title[0] = '\0';
		m_items = nullptr;
	}

	bool Bill::isValid()const
	{
		if ((m_title[0] != '\0') && (m_items != nullptr))
		{
			for (auto i = 0; i < m_noOfItems; i++)
			{
				m_items[i].isValid();
			}
		}
			return false;
	}

	double Bill::totalTax()const
	{
		double t_tax = 0.0;
		for (auto i = 0; i < m_noOfItems; i++)
		{
			t_tax += m_items[i].tax();
		}
		return t_tax;
	}

	double Bill::totalPrice()const
	{
		double t_price = 0.0;
		for (auto i = 0; i < m_noOfItems; i++)
		{
			t_price += m_items[i].price();
		}
		return t_price;
	}

	void Bill::Title()const
	{
		cout << "+--------------------------------------+" << endl;
		if (m_itemsAdded == m_noOfItems)
		{
			cout << "| " << setw(36) << left << m_title << " |" << endl;
		}
		else
		{
			cout << "| Invalid Bill                         |" << endl;
		}
		cout << "+----------------------+---------+-----+" << endl;
		cout << "| Item Name            | Price   + Tax |" << endl;
		cout << "+----------------------+---------+-----+" << endl;
	}

	void Bill::footer()const
	{
		cout << "+----------------------+---------+-----+" << endl;
		if (m_itemsAdded == m_noOfItems)
		{
			cout << "|                Total Tax: " << setfill(' ') << setw(10) << fixed << setprecision(2) << right << totalTax() << " |" << endl;
			cout << "|              Total Price: " << setfill(' ') << setw(10) << totalPrice() << " |" << endl;
			cout << "|          Total After Tax: " << setfill(' ') << setw(10) << (totalTax() + totalPrice()) << " |" << endl;
		}
		else
		{
			cout << "| Invalid Bill                         |" << endl;
		}
		cout << "+--------------------------------------+" << endl; 
	}

	void Bill::init(const char* title, int noOfItems)
	{
		if (title != nullptr && noOfItems > 0)
		{
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;
			strnCpy(m_title, title, 36);
			m_items = new Item[m_noOfItems];
		}
		else
		{
			setEmpty();
		}
	}

	bool Bill::add(const char* item_name, double price, bool taxed)
	{
		bool isValid = false;
		if ((m_itemsAdded < m_noOfItems) && (item_name != nullptr))
		{
			m_items[m_itemsAdded].set(item_name, price, taxed);
			isValid = true;
		}
		m_itemsAdded++;
		return isValid;
	}

	void Bill::display()const
	{
		Title();
		for (int i = 0; i < m_noOfItems; i++)
		{
			m_items[i].display();
		}
		footer();
	}

	void Bill::deallocate()
	{
		delete[] m_items;
		m_items = nullptr;
	}
}