#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "Label.h"

using namespace std;
namespace sdds
{
	Label::Label()
	{
		setEmpty();
		strCpy(m_frame, "+-+|+-+|");
	}

	Label::Label(const char* frameArg)
	{
		setEmpty();
		setFrame(frameArg);
	}

	Label::Label(const char* frameArg, const char* content)
	{
		int frameSize = (strLen(frameArg) + 1);
		int contentSize = (strLen(content) + 1);
		if (frameSize <= 21 && contentSize <= 71)
		{
			setFrame(frameArg);
			setContent(content);
		}
	}

	void Label::readLabel()
	{
		char label_len[71];
		setEmpty();
		setFrame("+-+|+-+|");
		cin.getline(label_len , 71);
		setContent(label_len);
	}

	std::ostream& Label::printLabel() const
	{
		if (m_content != nullptr)
		{
			int size = strLen(m_content) + 3;
			//First Row
			cout << m_frame[0] << setw(size) << setfill(m_frame[1]) << m_frame[2] << endl;
			//Second Row
			cout << m_frame[7] << setw(size) << setfill(' ') << m_frame[3] << endl;
			//Third Row 
			cout << m_frame[7] << " " << m_content << " " << m_frame[3] << endl;
			//Fourth Row
			cout << m_frame[7] << setw(size) << setfill(' ') << m_frame[3] << endl;
			//5th Row 
			cout << m_frame[6] << setw(size) << setfill(m_frame[5]) << m_frame[4];
		}
		return cout;
	}

	void Label::setEmpty()
	{
		m_content = nullptr;
		m_frame[0] = '\0';
	}

	void Label::setFrame(const char* frame)
	{
		if (frame != nullptr)
		{
			strCpy(m_frame, frame);
		}
	}

	void Label::setContent(const char* contentArg)
	{
		if (contentArg != nullptr)
		{
			delete[] m_content;
			int size = strLen(contentArg) + 1;
			m_content = new char[size];
			strCpy(m_content, contentArg);
		}
	}

	Label::~Label()
	{
		delete[] m_content;
		m_content = nullptr;
	}
}