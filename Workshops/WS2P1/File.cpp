#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds 
{
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }

   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }

   void closeFile() {
      if (fptr) fclose(fptr);
   }

   // Reads employee nname from file, stores it in param.
   bool read(char* e_name) 
   {
       bool valid = false;
           if (fscanf(fptr, "%[^\n]\n", e_name) == 1) // fscanf returns 1 if succesful.
           {
               valid = true;
           }
       return valid;
   }

   // Reads employee number from file, stores it in param.
   bool read(int &e_num) 
   {
       bool valid = false;
           if (fscanf(fptr, "%d,", &e_num) == 1)
           {
               valid = true;
           }
       return valid;
   }

   // Reads employee salary from file, stores it in param.
   bool read (double &e_salary)
   {
       bool valid = false;
       if (fscanf(fptr, "%lf,", &e_salary) == 1)
           {
               valid = true;
           }
       return valid;
   }
}