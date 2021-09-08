#include <iostream>
#include "cstring.h"
#include "Employee.h"
#include "File.h"

using namespace std;
namespace sdds 
{
   int noOfEmployees;
   Employee* employees;

   // Sorts emps stored.
   void sort() 
   {
      int i, j;
      Employee temp;
      for (i = noOfEmployees - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (employees[j].m_empNo > employees[j + 1].m_empNo) {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }

   // Reads one employee record from the file and loads it into the employee reference arg.
   bool load(Employee& employees) 
   {
      bool ok = false;
      char name[128];
      if ((read(employees.m_empNo) == true) && (read(employees.m_salary) == true)
          && (read(name) == true))
      {
          int size = strLen(name) + 1;  
          employees.m_name = new char[size];
          strCpy(employees.m_name, name); 
          ok = true; 
      } 
      return ok;
   }
   // Stores # of emp records into global var, creates dynamic array, loach each record into array.
   bool load()
   {
      bool ok = false;
      int i = 0;
      if (openFile(DATAFILE)) {
          noOfEmployees = noOfRecords();
          employees = new Employee[noOfEmployees]; 
          
          for (i = 0; i < noOfEmployees; i++)
          {
              load(employees[i]); 
              ok = true;
          }
      }
      else if (!openFile(DATAFILE))
      {
          cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
      }
      else {
         cout << "Could not open data file: " << DATAFILE << endl;
      }
      return ok;
   }

   // Recieves const to emp object prints in format below.
   void display(const Employee& employees) 
   {
           cout << employees.m_empNo << ": " << employees.m_name << ", " << employees.m_salary << endl;
   }

   // Overload of display with 0 params, sorts and prints sorted array.
   void display()
   {
       cout << "Employee Salary report, sorted by employee number" << endl;
       cout << "no- Empno, Name, Salary" << endl;
       cout << "------------------------------------------------" << endl;
       sort();
       for (int i = 0; i < noOfEmployees; i++)
       {
           cout << i + 1 << "- ";
           display(employees[i]);
       }
   }

   // Deallocates names, then memory used by array of emps.
   void deallocateMemory()
   {
      for (auto i = 0; i < noOfEmployees; i++)
      {
           delete[] employees[i].m_name;
           employees[i].m_name = nullptr;
      }

      delete[] employees;
      employees = nullptr;
   }



}