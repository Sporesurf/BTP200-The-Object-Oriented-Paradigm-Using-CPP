#ifndef SDDS_POPULATION_H
#define SDDS_POPULATION_H

namespace sdds 
{
	class Report
	{
	public:
		char* postal_code;
		int population;
	};
	
	// Stores population records as per postal code. Also takes file name as arg.
	bool load(const char*);
	// Reads population records by zip code.
	bool load(Report& stats);
	// Sorts Pop in ascending order from lowest to highest.
	void sort();
	// Outputs a single memory address of type Record.
	void display(const Report& stats);
	// Prints out to screen all postal codes and populations.
	void display();
	// Gets total population from all postal codes.
	void getpop();
	// Deallocates all dynamic memory.
	void deallocateMemory();
}
#endif // SDDS_POPULATION_H