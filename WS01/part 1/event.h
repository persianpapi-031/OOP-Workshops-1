#ifndef SDDS_EVENT_H
#define SDDS_EVENT_H

#include <iostream>
#include <cstring>
#include <iomanip>

extern size_t g_sysClock;

namespace sdds
{
	const int MAXCHARS = 127;

	class Event
	{
		char descEvent[MAXCHARS + 1];
		size_t time;

		void setTime();
		void displayTime();
		bool isDescEmpty(const char*);

	public:
		Event();
		void display();
		void set(const char*);
	};

}
#endif
