#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "LabelMaker.h"

using namespace std;
namespace sdds
{
	int t_labels = 0;
	LabelMaker::LabelMaker(int noOfLabels)
	{
		m_Label = new Label[noOfLabels];
		t_labels = noOfLabels;
	}
	
	void LabelMaker::readLabels()
	{	
		cout << "Enter " << t_labels << " labels:" << endl;
		for (auto i = 0; i < t_labels; i++)
		{
			cout << "Enter label number " << i + 1 << endl << "> ";
			m_Label[i].readLabel();
		}
	}

	void LabelMaker::printLabels()
	{
		for (auto i = 0; i < t_labels; i++)
		{
			m_Label[i].printLabel() << endl;
		}
	}

	LabelMaker::~LabelMaker()
	{
		delete[] m_Label;
		m_Label = nullptr;
	}
}
