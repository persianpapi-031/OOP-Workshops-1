#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <fstream>

#include "event.h"

using namespace std;

size_t g_sysClock;

namespace sdds
{
	static int count = 0;

	/* private */

	void Event::displayTime()
	{
		size_t temp = time;
		unsigned int h, m, s;

		h = temp / 3600;
		temp %= 3600;

		m = temp / 60;
		temp %= 60;

		s = temp;

		cout << setw(3) << count << ". " 
			<< setw(2) << setfill('0') << h << ":" << setw(2) << m << ":" << setw(2) << s 
			<< " -> " << descEvent << endl;
	}

	bool Event::isDescEmpty(const char* desc)
	{
		return (desc == NULL && strlen(desc) == 0);
	}

	void Event::setTime()
	{
		time = ::g_sysClock;
	}

	/*public*/

	Event::Event()
	{
		descEvent[0] = '\0';
	}

	void Event::display()
	{
		count++;

		if (isDescEmpty(descEvent))
			cout << setw(3) << count << ". [ No Event ]" << endl;
		else
			displayTime();
	}

	void Event::set(const char* desc)
	{
		if (!isDescEmpty(desc))
			strncpy(descEvent, desc, MAXCHARS);
		else
			descEvent[0] = '\0';

		setTime();
	}
}
