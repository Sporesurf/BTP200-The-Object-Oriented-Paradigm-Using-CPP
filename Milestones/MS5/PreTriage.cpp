/* Citation and Sources...
Final Project Milestone 5
Module: PreTiage
Filename: PreTiage.cpp
Version 1.0
Author	Vlado Tomovic
Revision History
-----------------------------------------------------------
Date      Reason
2021/06/27  Preliminary release
2021/08/01  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#include <iostream>
#include <cstring>
#include <fstream>
#include "PreTriage.h"
#include "utils.h"
#include "Menu.h"
#include "CovidPatient.h"
#include "TriagePatient.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
namespace sdds
{
	PreTriage::PreTriage(const char* dataFilename) :
		m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2),
		m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2)
	{
		m_averCovidWait = 15;
		m_averTriageWait = 5;

		delete[] m_dataFilename;
		int size = strlen(dataFilename) + 1;
		m_dataFilename = new char[size];
		strcpy(m_dataFilename, dataFilename);
		load();
	}

	const Time PreTriage::getWaitTime(const Patient& p)const
	{
		unsigned int matchingPatients = 0;
		Time t_waittime = 0;

		if (p.type() == 'C')
		{
			t_waittime = m_averCovidWait;
		}
		else if (p.type() == 'T')
		{
			t_waittime = m_averTriageWait;
		}

		for (auto i = 0; i <= m_lineupSize; i++)
		{
			if (p.type() == m_lineup[i]->type())
				matchingPatients++;
		}

		if (matchingPatients == 1)
			return 0; //No wait time with single patient
		
		t_waittime *= matchingPatients;
		return  t_waittime;
	}

	void PreTriage::setAverageWaitTime(const Patient& p)
	{
		unsigned int CT = getTime();
		unsigned int PTT = Time(p);
		unsigned int PTN = p.number();  

		if (p.type() == 'C')
			m_averCovidWait = ((CT - PTT) + (int (m_averCovidWait) * (PTN - 1 ))) / PTN;
		else if (p.type() == 'T') 
			m_averTriageWait = ((CT - PTT) + (int (m_averTriageWait) * (PTN - 1))) / PTN;
	}

	void PreTriage::removePatientFromLineup(int index)
	{
		removeDynamicElement<Patient>(m_lineup, index, m_lineupSize);
	}

	int PreTriage::indexOfFirstInLine(char type) const
	{
		for (auto i = 0; i < m_lineupSize; i++)
		{
			if (type == m_lineup[i]->type())
				return i;
		}
		return -1;
	}

	void PreTriage::load()
	{
		Patient* n_patient = nullptr; 
		char ptype = '\0';
		ifstream file;
		int patientsRecorded = 0;

		cout << "Loading data..." << endl;
		file.open(m_dataFilename);

		if (file.is_open())
		{
			file >> m_averCovidWait;
			file.ignore(1000, ',');
			file >> m_averTriageWait;
			file.ignore(1000, '\n');

			for (int i = 0; i < maxNoOfPatients; i++)
			{
				file >> ptype;
				file.ignore(1000, ',');
				if (file)
				{
					if (ptype == 'C')
						n_patient = new CovidPatient();
					if (ptype == 'T')
						n_patient = new TriagePatient();

					if (n_patient != nullptr)
					{
						n_patient->fileIO(true);
						n_patient->read(file);
						n_patient->fileIO(false);
						m_lineup[i] = n_patient;
						m_lineupSize++;
					}
					patientsRecorded++;
				}
			}

			if (n_patient == nullptr)
				cout << "No data or bad data file!" << endl << endl;
			else if (!file.eof())
			{
				cout << "Warning: number of records exceeded 100" << endl;
				cout << m_lineupSize << " Records imported..." << endl << endl;
			}
			else if (patientsRecorded < maxNoOfPatients)
				cout << m_lineupSize << " Records imported..." << endl << endl;
		}
		file.close();
	}	

	void PreTriage::reg()
	{
		int selection = -1; 

		if (m_lineupSize >= maxNoOfPatients)
		{
			cout << "Line up full!" << endl;
			return; 
		}

		m_pMenu >> selection; //calls display and gets selection.

		if (selection == 1)
			m_lineup[m_lineupSize] = new CovidPatient();
		else if (selection == 2)
			m_lineup[m_lineupSize] = new TriagePatient();
		else if (selection == 0) 
			return;

		if (selection == 1 || selection == 2)
		{
			m_lineup[m_lineupSize]->setArrivalTime();
			cout << "Please enter patient information: " << endl;
			m_lineup[m_lineupSize]->read(cin); // IO FLAG SHOULD BE OKAY
			cout << endl;
			cout << "******************************************" << endl;
			m_lineup[m_lineupSize]->write(cout); 
			cout << "Estimated Wait Time: ";
			cout << getWaitTime(*m_lineup[m_lineupSize]) << endl; 
			cout << "******************************************" << endl << endl;
			m_lineupSize++;
		}
	}

	void PreTriage::admit()
	{
		int patientLinePosition;
		char p_type ='\0';
		int selection = -1;
		m_pMenu >> selection;

		if (selection == 1)
			p_type = 'C';
		else if (selection == 2)
			p_type = 'T';
		else if (selection == 0)
			return;
		patientLinePosition = indexOfFirstInLine(p_type);

		if (patientLinePosition != -1) // index returns -1 if nobody is in line.
		{
			cout << endl;
			cout << "******************************************" << endl; 
			m_lineup[patientLinePosition]->fileIO(false); // set patient not to do file IO
			cout << "Calling for ";
			m_lineup[patientLinePosition]->write(cout);
			cout << "******************************************" << endl << endl;
			setAverageWaitTime(*m_lineup[patientLinePosition]);
			removePatientFromLineup(patientLinePosition);
		}
	}

	void PreTriage::run(void)
	{
		int selection = -1;
		do {
			m_appMenu >> selection;
			if (selection == 0)
				return;
			else if (selection == 1)
				reg();
			else if (selection == 2)
				admit();
		} while (selection != 0);
	}

	PreTriage::~PreTriage()
	{
		int p_counter = 1;
		ofstream file; 

		file.open(m_dataFilename);
		if (file.is_open())
		{
			file << m_averCovidWait << "," << m_averTriageWait << endl;
			cout << "Saving Average Wait Times," << endl;
			cout << "   COVID Test: " << m_averCovidWait << endl;
			cout << "   Triage: " << m_averTriageWait << endl;
			cout << "Saving m_lineup..." << endl;

			for (int i = 0; i < m_lineupSize; i++)
			{
				cout << p_counter << "- ";
				m_lineup[i]->csvWrite(file) << endl;
				m_lineup[i]->fileIO(true); //set true so patients bypess condition in Patient::write
				m_lineup[i]->write(cout) << endl;
				p_counter++;
			}
		}
		file.close();

		for (int i = 0; i < m_lineupSize; i++)
			delete m_lineup[i];

		delete[] m_dataFilename;
		cout << "done!" << endl;
	}
}