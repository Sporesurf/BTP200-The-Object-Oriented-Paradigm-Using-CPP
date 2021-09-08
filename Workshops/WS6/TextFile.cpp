#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"

using namespace std;
namespace sdds {
   Line::operator const char* () const {
      return (const char*)m_value;
   }
   Line& Line::operator=(const char* lineValue) {
      delete[] m_value;
      m_value = new char[strLen(lineValue) + 1];
      strCpy(m_value, lineValue);
      return *this;
   }
   Line::~Line() {
      delete[] m_value;
   }

   void TextFile::setEmpty()
   {
       delete[] m_textLines;
       delete[] m_filename;
       m_textLines = nullptr;
       m_filename = nullptr;
       m_noOfLines = 0;
   }

   void TextFile::setFilename(const char* fname, bool isCopy)
   {
       delete[] m_filename;
       int size = strLen(fname) + 1;
       if (isCopy == false)
       {
           m_filename = new char[size];
           strCpy(m_filename, fname);
       }
       else if (isCopy == true)
       {
           m_filename = new char[size + 2];
           strCpy(m_filename, "C_");
           strCat(m_filename, fname);
       }
   }

   void TextFile::setNoOfLines()
   {
       ifstream ifs;
       string m_line;
       int lineCounter = 0;
       ifs.open(m_filename);
       if (ifs.is_open())
       {
           while (getline(ifs, m_line))
           {
               lineCounter++;
           }
           m_noOfLines = lineCounter;
           ifs.close();
       }
       if (lineCounter == 0)
       {
           delete[] m_filename;
           m_filename = nullptr;
           m_noOfLines = 0;
       }
   }

   void TextFile::loadText()
   {
       if (m_filename != nullptr)
       {
           delete[] m_textLines;
           m_textLines = new Line[m_noOfLines];
            
           ifstream ifs;
           string str;
           ifs.open(m_filename);
           if (ifs.is_open())
           {
               for (unsigned i = 0; i < m_noOfLines; i++)
               {
                   getline(ifs, str);
                   m_textLines[i] = str.c_str();
               }
               ifs.close();
           }
       }
       return;
   }
   
   void TextFile::saveAs(const char* fileName) const
   {
       ofstream ostrm;
       ostrm.open(fileName);
       if (ostrm.is_open())
       {
           for (unsigned i = 0; i < m_noOfLines; i++)
           {
               ostrm << m_textLines[i] << endl;
           }
           ostrm.close();
       }
       return;
   }

   TextFile::TextFile(unsigned pageSize)
   {
       m_textLines = nullptr;
       m_pageSize = pageSize;
       m_filename = nullptr;
       m_noOfLines = 0;
   }

   TextFile::TextFile(const char* filename, unsigned pageSize)
   {
       m_textLines = nullptr;
       m_pageSize = pageSize;
       m_filename = nullptr;
       m_noOfLines = 0;

       if (filename != nullptr)
       {
           setFilename(filename, false);
           setNoOfLines();
           loadText();
       }
   }

   TextFile::TextFile(const TextFile& incFile)
   {
       m_textLines = nullptr;
       m_pageSize = incFile.m_pageSize;
       m_filename = nullptr;
       m_noOfLines = 0;
       if (incFile.m_filename != nullptr)
       {
           setFilename(incFile.m_filename, true);
           incFile.saveAs(m_filename);
           setNoOfLines();
           loadText();
       }
   }

   TextFile& TextFile::operator=(const TextFile& incFile)
   {
       if (m_filename != nullptr && incFile.m_filename != nullptr)
       {
           delete[] m_textLines;
           m_textLines = nullptr;
           incFile.saveAs(m_filename);
           setNoOfLines();
           loadText();
       }
       return *this;
   }
   
   TextFile::~TextFile()
   {
       delete[] m_textLines;
       delete[] m_filename;
       m_textLines = nullptr;
       m_filename = nullptr;
   }

   unsigned TextFile::lines() const
   {
       return m_noOfLines;
   }

   std::ostream& TextFile::view(std::ostream& ostr) const
   {
       if (m_filename != nullptr)
       {
           string u_line;
           ostr << m_filename << endl;
           ostr.width(strLen(m_filename));
           ostr.fill('=');
           ostr << u_line << endl;

           unsigned int j = 0;
           for (unsigned i = 0; i < m_noOfLines; i++)
           {
               if (j == m_pageSize)
               {
                   j = 0;
                   ostr << "Hit ENTER to continue...";
                   cin.get();
               }
               ostr << m_textLines[i].m_value << endl;
               j++;
           }
       }
       return ostr;
   }

   std::istream& TextFile::getFile(std::istream& istr)
   {
       string fname;
       istr >> fname;
       setFilename(fname.c_str());
       setNoOfLines();
       loadText();
       while (getchar() != '\0')
       {
           return istr;
       }
       return istr;
   }

   const char* TextFile::operator[](unsigned index) const
   {
       if (m_filename != nullptr)
       {
           return m_textLines[index % m_noOfLines];
       }
       return nullptr;
   }

   TextFile::operator bool() const
   {
       if (m_filename != nullptr && m_textLines != nullptr && m_noOfLines)
       {
           return true;
       }
       return false;
   }

   const char* TextFile::name() const
   {
       return m_filename;
   }

   std::ostream& operator<<(std::ostream& ostr, const TextFile& text)
   {
       text.view(ostr);
       return ostr;
   }

   std::istream& operator>>(std::istream& istr, TextFile& text)
   {
       text.getFile(istr);
       return istr;
   }
}