#include <iostream>
#include <string.h>
#include "Population.h"
#include "File.h"

using namespace std;
namespace sdds 
{
	int noOfpcodes = 0;
	Report* stats;
	
	void sort()
	{
		int i, j;
		Report temp;
		for (i = noOfpcodes - 1; i > 0; i--) 
		{
			for (j = 0; j < i; j++) 
			{
				if (stats[j].population > stats[j + 1].population)
				{
					temp = stats[j];
					stats[j] = stats[j + 1];
					stats[j + 1] = temp;
				}
			}
		}
	}

	bool load(Report& stats)
	{
		bool valid = false;
		char pcode[10];
		if ((read(pcode) == true) && (read(stats.population) == true))
		{
			int size = strlen(pcode) + 1;
			stats.postal_code = new char[size];
			strcpy(stats.postal_code, pcode);
			valid = true;
		}
		return valid;
	}

	bool load(const char* fname)
	{
		bool valid = false;
		if (openFile(fname))
		{
			noOfpcodes = noOfRecords();
			stats = new Report[noOfpcodes];

			for (int i = 0; i < noOfpcodes; i++)
			{
				load(stats[i]);
				valid = true;
			}
		}
		else if (!openFile(fname))
		{
			cout << "Error, file not read.";
		}
		closeFile();
		return valid;
	}
	
	void getpop()
	{
		int totalpop = 0;
		for (int i = 0; i < noOfpcodes; i++)
		{
			totalpop += stats[i].population;
		}
		cout << totalpop;
	}

	void display(const Report& stats)
	{
		cout << stats.postal_code << ":  " << stats.population << endl;
	}

	void display()
	{	
		cout << "Postal Code: population" << endl;
		cout << "-------------------------" << endl;
		sort();
		for (int i = 0; i < noOfpcodes; i++)
		{
			cout << i + 1 << "- ";
			display(stats[i]);
		}
		cout << "-------------------------" << endl;
		cout << "Population of Canada: "; getpop();
		cout << endl;
	}

	void deallocateMemory()
	{
		for (int i = 0; i < noOfpcodes; ++i)
		{
			delete[] stats[i].postal_code;	
			stats[i].postal_code = nullptr;
		}
		delete[] stats;
		stats = nullptr;
	}
}