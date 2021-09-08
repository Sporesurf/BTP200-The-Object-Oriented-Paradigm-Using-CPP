/* Citation and Sources...
Final Project Milestone ?
Module: utils
Filename: utils.h
Version 1.0
Author	Vlado Tomovic
Revision History
-----------------------------------------------------------
Date      Reason
2021/06/27  Preliminary release
2021/07/20  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#ifndef SDDS_PATIENT_H
#define SDDS_PATIENT_H
#include "IOAble.h"
#include "Ticket.h"

namespace sdds
{
	class Patient : public IOAble
	{
		char* m_patientname = nullptr;
		int m_ohip = 0;
		Ticket m_ticket;
		bool m_patientflag = false;
	public:
		Patient(int ticketnum, bool fileIO = false);
		~Patient();

		virtual char type()const = 0;

		bool fileIO()const;
		bool fileIO(bool patientFlag);
		
		bool operator==(char incChar)const;
		bool operator==(const Patient& rhs)const;

		void setArrivalTime();
		operator Time()const;
		int number()const;

		std::ostream& csvWrite(std::ostream& ostr)const;
		std::istream& csvRead(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
	};
}
#endif // !SDDS_PATIENT_H


