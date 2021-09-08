//Vlado Tomovic     vtomovic@myseneca.ca     SN : 107995151     Date : 2021 / 05 / 29
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments
#include "cstring.h"

namespace sdds
{
	void strCpy(char* des, const char* src)
	{
		int i = 0;
		while (src[i] != '\0')
		{
			des[i] = src[i];
			i++;
		}
		des[i] = '\0';
	}

	void strnCpy(char* des, const char* src, int len)
	{
		for (int i = 0; i < len; i++)
		{
			des[i] = src[i];
		}
	}

	int strCmp(const char* s1, const char* s2)
	{
		int i = 0;
		while (s1[i] != '\0' && s2[i] != '\0')
		{
			if (s1[i] == s2[i])
			{
				i++;
			}
			else if (s1[i] > s2[i])
			{
				return 1;
			}
			else if (s1[i] < s2[i])
			{
				return -1;
			}
		}
		return 0;
	}

	int strnCmp(const char* s1, const char* s2, int len)
	{
		for (int i = 0; i < len; i++)
		{
			if (s1[i] != '\0' && s2[i] != '\0')
			{
				if (s1[i] == s2[i])
				{
					i++;
				}
				else if (s1[i] > s2[i])
				{
					return 1;
				}
				else if (s1[i] < s2[i])
				{
					return -1;
				}
			}
		}
		return 0;
	}
	
	int strLen(const char* s)
	{
		int i = 0;
		while (s[i] != '\0')
		{
			i++;
		}
		return i;
	}

	const char* strStr(const char* str1, const char* str2)
	{
		while (*str1 != '\0')
		{
			if (*str1 == *str2)
			{
				bool found = true;
				char temp1[80];
				char temp2[80];
				strCpy(temp1, str1); 
				strCpy(temp2, str2);
				for (int i = 0; temp2[i] != '\0'; i++)
				{
					if (temp1[i] != temp2[i])
					{
						found = false;
					}
				}
				if (found)
				{
					return str1;
				}
			}
			str1++;
		}
		return nullptr;
	}

	void strCat(char* des, const char* src)
	{
		int i = 0;
		int j = 0;
		for (i = 0; des[i] != '\0'; i++);
		for (j = 0; src[j] != '\0'; j++)
		{
			des[i + j] = src[j];
		}
		des[i + j] = '\0';
	}
}