#ifndef SDDS_FILE_H
#define SDDS_FILE_H

namespace sdds 
{
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   
   // Reads population from csv file.
   bool read(int& h_pop);
   // Reads postal code from csv file. 
   bool read(char* p_code);
}
#endif // !SDDS_FILE_H
