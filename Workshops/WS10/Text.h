#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__
namespace sdds 
{
   class Text 
   {
      char* m_filename = nullptr; // Hold the name of the file dynamically
      char* m_content = nullptr; // Holds the content of the text file dynamically.
      int getFileLength()const;
   protected:
      const char& operator[](int index)const;
   public:
       void setEmpty();
       Text(const char* filename = nullptr);
       Text& operator=(const Text& obj);
       Text(const Text& obj);
       virtual ~Text();

      char* memAllocation(const char* name);
      void read();
      virtual void write(std::ostream& os)const;
   };
   std::ostream& operator<<(ostream& os, Text& rhs);
}
#endif // !SDDS_PERSON_H__

