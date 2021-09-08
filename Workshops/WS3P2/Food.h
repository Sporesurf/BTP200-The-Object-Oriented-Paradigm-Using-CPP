#ifndef SDDS_FOOD_H
#define SDDS_FOOD_H

namespace sdds
{
	class Food
	{
		char m_name[31]; 
		char m_consumption[10]; 
		int m_cals = 0; 
		// Set name of the food.
		void setName(const char* name); 
	public:
		// Set attributes to valid empty state.
		void setEmpty(); 
		// Sets attribute values.
		void set(const char* name, int cals, int consumption); 
		// Returns calories.
		int calories()const; 
		// Checks if Food object is valid.
		bool isValid()const; 
		// Displays a single row.
		void display()const; 
	};
}
#endif // !FOOD_H

