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

#ifndef SDDS_STRING_SET_H
#define SDDS_STRING_SET_H

#include <iostream>
#include <fstream>
#include <string>

namespace sdds
{
	class StringSet
	{
		std::string* strArr = nullptr;
		size_t arrSize = 0;

	public:
		StringSet() = default;
		StringSet(const char*);
		StringSet(const StringSet&);
		StringSet(StringSet&&);
		~StringSet();
		
		size_t size();
		std::string operator[](size_t);
		StringSet& operator=(const StringSet&);
		StringSet& operator=(StringSet&&);
	};
}

#endif
