#ifndef SDDS_TEXTFILE_H
#define SDDS_TEXTFILE_H
#include <iostream>
namespace sdds {
   class Text;
   class Line {
      char* m_value{ nullptr };
      operator const char* ()const;
      Line() {}
      Line& operator=(const char*);
      ~Line();
      friend class TextFile;
      // copy and copy assignment prevention goes here
   };

   class TextFile {
      Line* m_textLines; // Holds a dynamic array of lines, init to nullptr
      char* m_filename; // Pointer holds dynamic String name of file. init to nullptr
      unsigned m_noOfLines; // Set number of Lines in the file.
      unsigned m_pageSize; // # of lines that should be displayed before display is paused. Must hint
                           // enter to prompt next set of lines.
      void setFilename(const char* fname, bool isCopy = false);
      void setNoOfLines();
      void loadText();
      void saveAs(const char *fileName)const;
      void setEmpty();
   public:
      TextFile(unsigned pageSize = 15);
      TextFile(const char* filename, unsigned pageSize = 15);
      TextFile(const TextFile&);
      TextFile& operator=(const TextFile&);
      ~TextFile();
      std::ostream& view(std::ostream& ostr)const;
      std::istream& getFile(std::istream& istr);
      operator bool()const;
      unsigned lines()const;
      const char* name()const;
      const char* operator[](unsigned index)const;
   };
   std::ostream& operator<<(std::ostream& ostr, const TextFile& text);
   std::istream& operator>>(std::istream& istr, TextFile& text);
}
#endif // !SDDS_TEXTFILE_H
