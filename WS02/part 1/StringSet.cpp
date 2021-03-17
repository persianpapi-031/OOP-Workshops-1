//=================================================
// Name:           Kian Dadkhah Shokrollahi
// Student Number: 119369205
// Email:          kdadkhah-shokrollahi@myseneca.ca
// Course:         OOP345
// Section:        NCC
// Workshop:       2 (part 2)
//=================================================

 /*I have done all the coding by myself and only copied the code
  that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

#include "StringSet.h"
#include "TimedEvents.h"

using namespace std;

namespace sdds
{
	StringSet::StringSet(const char* filename)
	{
		strArr = nullptr; 
		arrSize = 0;
		string tempStr;
		char delim = ' ';

		ifstream ifstr(filename);
		while (!ifstr.eof())
		{
			if (ifstr)
			{
				while (getline(ifstr, tempStr, delim))
				{
					++arrSize;
				}
			}
			ifstr.clear();
			ifstr.seekg(0, ios_base::beg);

			delete[] strArr;
			strArr = nullptr;
			strArr = new string[arrSize];

			for (size_t i = 0; i < arrSize; i++)
			{
				if (getline(ifstr, tempStr, delim))
				{
					strArr[i] = tempStr;
				}
			}
		}
		
		if (ifstr.eof())
			ifstr.close();
	}

	StringSet::~StringSet()
	{
		if (strArr)
		{
			delete[] strArr;
			strArr = nullptr;
		}
	}

	StringSet::StringSet(const StringSet& src)
	{
		*this = src;
	}

	StringSet::StringSet(StringSet&& src)
	{
		*this = std::move(src);
	}

	size_t StringSet::size()
	{
		return arrSize;
	}

	std::string StringSet::operator[](size_t idx)
	{
		string tempStr;

		if (idx >= 0 && idx < arrSize)
		{
			if (strArr[idx] != "")
			{
				tempStr = strArr[idx];
			}
			else
			{
				tempStr = "";
			}
		}

		return tempStr;
	}

	StringSet& StringSet::operator=(const StringSet& src)
	{
		if (this != &src)
		{
			arrSize = src.arrSize;
			delete[] strArr;
			strArr = nullptr;
			strArr = new string[arrSize];

			for (size_t i = 0; i < arrSize; ++i)
			{
				strArr[i] = src.strArr[i];
			}
		}

		return *this;
	}

	StringSet& StringSet::operator=(StringSet&& src)
	{
		if (this != &src)
		{
			arrSize = src.arrSize;
			delete[] strArr;
			
			strArr = src.strArr;
			src.strArr = nullptr;

			src.arrSize = 0;
		}

		return *this;
	}
}