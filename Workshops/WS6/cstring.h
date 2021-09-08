#ifndef SDDS_CSTRING_H
#define SDDS_CSTRING_H

namespace sdds
{
    // Copies the srouce character string into the destinations
    void strCpy(char* des, const char* src);
    // Copies the source character string into the destination upto "len"
    // characters. The destination will be null terminated only if the number
    // of the characters copied is less than "len"
    void strnCpy(char* des, const char* src, int len);
    // Compares two C-strings 
    // returns 0 if they're the same
    // return > 1 if s1 > s2
    // return < -1 if s1 < s2
    int strCmp(const char* s1, const char* s2);
    // returns 0 if they're the same
    // return > 1 if s1 > s2
    // return < -1 if s1 < s2
    int strnCmp(const char* s1, const char* s2, int len);
    // returns the length of the C-string in characters
    int strLen(const char* s);
    // returns the address of first occurance of "str2" in "str1"
    // returns nullptr if no match is found
    const char* strStr(const char* str1, const char* str2);
    // Concantinates "src" C-string to the end of "des"
    void strCat(char* des, const char* src);
}
#endif // !SDDS_CSTRING_H