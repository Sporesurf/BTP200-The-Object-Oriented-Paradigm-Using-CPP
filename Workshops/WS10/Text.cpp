#include <fstream>
#include <iostream>
#include "Text.h"

using namespace std;
namespace sdds 
{
   int Text::getFileLength() const 
   {
      int len = 0;
      ifstream fin(m_filename);
      while (fin) {
         fin.get();
         len += !!fin;
      }
      return len;
   }

   const char& Text::operator[](int index) const
   {
       return m_content[index];
   }

   void Text::setEmpty()
   {
       m_filename = nullptr;
       m_content = nullptr;
   }

   Text& Text::operator=(const Text& obj)
   {
       if (this != &obj)
       {
           delete[] m_filename;
           m_filename = memAllocation(obj.m_filename);

           delete[] m_content;
           m_content = memAllocation(obj.m_content);
       }
       else
       {
           setEmpty();
       }
   }

   Text::Text(const Text& obj) { *this = obj; }

   Text::Text(const char* filename)
   {
       if (filename != nullptr)
       {
           delete[] m_filename;
           m_filename = memAllocation(filename);
           read();
       }
   }

   char* Text::memAllocation(const char* name)
   {
       int size = strlen(name) + 1;
       char* m_var = new char[size];
       strcpy(m_var, name);
       return m_var;
   }

   void Text::read()
   {
       delete[] m_content;
       int size = getFileLength() + 1;
       m_content = new char[size];

       ifstream file;
       file.open(m_filename);
       if (file)
       {
           int i = 0;
           do
           {
               m_content[i] = file.get();
               i++;
           } while (!file.eof() && i < size);
           m_content[i - 1] = '\0';
       }
       
   }

   void Text::write(std::ostream& os) const
   {
       if (m_content != nullptr) os << m_content;
   }

   
   Text::~Text()
   {
       delete[] m_filename;
       delete[] m_content;
   }

   ostream& operator<<(ostream& os, Text& rhs)
   {
       rhs.write(os);
       return os;
   }
}