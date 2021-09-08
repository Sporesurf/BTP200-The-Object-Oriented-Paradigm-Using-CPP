#ifndef SDDS_FILE_H
#define SDDS_FILE_H

namespace sdds
{
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();

   // TODO: Declare read prototypes
   bool read(char* e_name);
   bool read(int& e_num);
   bool read(double& e_salary);
}
#endif // SDDS_FILE_H
