#ifndef SDDS_CALORIELIST_H
#define SDDS_CALORIELIST_H
#include "Food.h"

namespace sdds
{
	class CalorieList
	{
		Food* m_food; 
		int test = 0;
		int m_totalFood = 0;
		int m_foodAdded = 0;
		//Increments only when add() condition satisfied.
		int m_actuallyAdded = 0; 
		// Returns total Calories.
		int totalcals()const; 
		void Title() const; 
		void footer()const; 
		// Sets attributes to safe empty state.
		void setEmpty();  
	public:
		// Initializes x number of items.
		void init(int noOfItems); 
		// Adds the next valid item.
		bool add(const char* name, int cals, int consumption); 
		// Display Calorie label.
		void display()const;
		// Deallocate used memory.
		void deallocate();  
	};
}
#endif // !CALORIE_LIST_H

