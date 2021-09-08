#ifndef SDDS_SEARCHNLIST_H
#define SDDS_SEARCHNLIST_H
#include <iostream>
#include "Collection.h"

using namespace std;
namespace sdds
{
	template <typename T, typename K>
	bool search(Collection <T>& obj , T* array, int sizeOfArray, K& key)
	{
		int j = 0;;
		for (int i = 0; i < sizeOfArray; i++)
		{
			if (array[i] == key)
			{
				obj.add(array[i]);
				j++;
			}
		}
		if (j > 0)
			return true;
		else
			return false;
	}

	template <typename T>
	void listArrayElements(const char* Title, const T array[], int sizeOfArray)
	{
		int row = 1;
		cout << Title << endl;
		for (int i = 0; i < sizeOfArray; i++)
		{
			cout << row << ": " << array[i] << endl;
			row++;
		}
	}
}
#endif //!SDDS_SEARCHNLIST_H