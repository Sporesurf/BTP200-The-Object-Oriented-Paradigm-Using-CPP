/* Citation and Sources...
Final Project Milestone 4
Module: TriagePatient
Filename: TriagePatient.cpp
Version 1.0
Author	Vlado Tomovic
Revision History
-----------------------------------------------------------
Date      Reason
2021/06/27  Preliminary release
2021/07/23  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <sstream>
#include "TriagePatient.h"

using namespace std;
namespace sdds
{
   int nextTriageTicket = 1;

   TriagePatient::TriagePatient() : Patient(nextTriageTicket)
   {
	   m_symptoms = nullptr;
	   nextTriageTicket++;
   }

   const char TriagePatient::type() const
   {
	   return 'T';
   }

   std::ostream& TriagePatient::csvWrite(std::ostream& ostr) const
   {
	   Patient::csvWrite(ostr);
	   ostr << ',' << m_symptoms; 
	   return ostr;
   }

   std::istream& TriagePatient::csvRead(std::istream& istr)
   {
	   string str;

	   delete[] m_symptoms;
	   Patient::csvRead(istr);
	   istr.ignore(1000, ',');

	   getline(istr, str);
	   int size = str.length() + 1;
	   m_symptoms = new char[size];
	   strcpy(m_symptoms, str.c_str());

	   nextTriageTicket = number() + 1;
	   return istr;
   }

   std::ostream& TriagePatient::write(std::ostream& ostr) const
   {
	   if (fileIO())
		   csvWrite(ostr);
	   else
	   {
		   ostr << "TRIAGE" << endl;
		   Patient::write(ostr) << endl;
		   ostr << "Symptoms: " << m_symptoms << endl;
	   }
	   return ostr;
   }

   std::istream& TriagePatient::read(std::istream& istr)
   {
	   if (fileIO())
		   csvRead(istr);
	   else
	   {
		   delete[] m_symptoms;
		   Patient::read(istr);
		   cout << "Symptoms: ";

		   string str;
		   getline(istr, str);
		   int size = str.length() + 1;
		   m_symptoms = new char[size];
		   strcpy(m_symptoms, str.c_str());
	   }
	   return istr;
   }

   TriagePatient::~TriagePatient()
   {
	   delete[] m_symptoms;
   }

}