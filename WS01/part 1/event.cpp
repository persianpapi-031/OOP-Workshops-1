//=================================================
// Name:           Kian Dadkhah Shokrollahi
// Student Number: 119369205
// Email:          kdadkhah-shokrollahi@myseneca.ca
// Course:         OOP345
// Section:        NCC
// Workshop:       1 (part 2)
//=================================================

 /*I have done all the coding by myself and only copied the code
  that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cstring>

#include "event.h"

using namespace std;

unsigned long g_sysClock = 0;

namespace sdds
{
	Event::Event()
	{
		descEvent = nullptr;
		time = 0;
	}

	Event::Event(const Event& src)
	{
		*this = src;
	}

	Event::~Event()
	{
		delete[] descEvent;
		descEvent = nullptr;
	}

	void Event::display() const
	{
		static int count = 1;

		unsigned long h = time / 3600;
		unsigned long m = time / 60 % 60;
		unsigned long s = time % 60;

		if (descEvent == nullptr)
		{
			cout << setw(2) << setfill(' ') << count << ". " << "| No Event |" << endl;
		}
		else
		{
			cout << setw(2) << setfill(' ') << count << ". " << setw(2) << setfill('0') << h << ":"
				<< setw(2) << setfill('0') << m << ":" << setw(2) << setfill('0') << s << " => " << descEvent << endl;
		}

		count++;
	}

	void Event::set()
	{
		delete[] descEvent;
		descEvent = nullptr;
		time = 0;
	}

	void Event::set(char* src)
	{
		if (src != nullptr && src[0] != '\0')
		{
			delete[] descEvent;
			descEvent = nullptr;

			descEvent = new char[strlen(src) + 1];
			strcpy(descEvent, src);
			time = g_sysClock;
		}
		else
		{
			set();
		}
	}

	Event& Event::operator=(const Event& src)
	{
		if (this != &src)
		{
			if (src.descEvent != nullptr && src.descEvent[0] != '\0')
			{
				delete[] descEvent;
				descEvent = nullptr;

				descEvent = new char[strlen(src.descEvent) + 1];
				strcpy(descEvent, src.descEvent);
				time = src.time;
			}
			else
			{
				set();
			}
		}

		return *this;
	}
}
