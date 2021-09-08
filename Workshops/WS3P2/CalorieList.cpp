#include <iostream>
#include <iomanip>
#include "CalorieList.h"
#include "cstring.h"

using namespace std;
namespace sdds
{
	int CalorieList::totalcals()const
	{
		int t_cals = 0;
		for (auto i = 0; i < m_totalFood; i++)
		{
			t_cals += m_food[i].calories();
		}
		return t_cals;
	}

	void CalorieList::Title()const
	{
		cout << "+----------------------------------------------------+" << endl;
		if (m_actuallyAdded == m_totalFood)  
		{
			cout << "|  Daily Calorie Consumption                         |" << endl;
		}
		else
		{
			cout << "| Invalid Calorie Consumption list                   |" << endl;
		}
		cout << "+--------------------------------+------+------------+" << endl;
		cout << "| Food name                      | Cals | When       |" << endl;
		cout << "+--------------------------------+------+------------+" << endl;
	}

	void CalorieList::footer() const
	{
		cout << "+--------------------------------+------+------------+" << endl;
		if (m_actuallyAdded == m_totalFood) 
		{
			cout << "|    Total Calories for today: " << setfill(' ') << right << setw(8) << totalcals() << " |            |" << endl;
		}
		else
		{
			cout << "|    Invalid Calorie Consumption list                |" << endl;
		}
		cout << "+----------------------------------------------------+" << endl;
	}

	void CalorieList::setEmpty()
	{
		m_food = nullptr;
	}

	void CalorieList::init(int noOfItems)
	{
		if (noOfItems > 0)
		{
			m_totalFood = noOfItems;
			m_foodAdded = 0;
			m_actuallyAdded = 0;
			m_food = new Food[m_totalFood];
		}
		else
		{
			setEmpty();
		}
	}

	bool CalorieList::add(const char* name, int cals, int consumption)
	{
		bool isValid = false;
		if ((m_foodAdded < m_totalFood) && (name != nullptr) && (consumption > 0 && consumption < 5)
			&& (cals > 0 && cals <= 3000))
		{
			m_food[m_foodAdded].set(name, cals, consumption);
			isValid = true;
			m_actuallyAdded++;
		}
		m_foodAdded++;
		return isValid;
	}

	void CalorieList::display() const
	{
		Title();
		for (auto i = 0; i < m_totalFood; i++)
		{
			m_food[i].display();
		}
		footer();
	}

	void CalorieList::deallocate()
	{
		delete[] m_food;
		m_food = nullptr;
	}
}