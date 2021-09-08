#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds 
{
   FILE* fptr;

   bool openFile(const char filename[]) 
   {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }

   int noOfRecords() 
   {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1)
      {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }

   void closeFile() 
   {
      if (fptr) fclose(fptr);
   }

   // Reads population from file, stores it in param.
   bool read(int& h_pop)
   {
       bool valid = false;
       if (fscanf(fptr, ",%d\n", &h_pop) == 1) //should be good
       {
           valid = true;
       }
       return valid;
   }

   // Reads postal code from file, stores it in param.
   bool read(char* p_code)
   {
       bool valid = false;
       if (fscanf(fptr, "%[^,]", p_code) == 1) // fscanf returns 1 if succesful.
       {    // Only need to scan 3 UPPERCASE CHARS. may need to do til newline.
           valid = true;
       }
       return valid;
   }
}