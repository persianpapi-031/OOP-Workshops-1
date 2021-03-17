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

#include <ostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <chrono>

#include "TimedEvents.h"
#include "StringSet.h"

using namespace std;

namespace sdds
{
	void TimedEvents::startClock()
	{
		startTime = std::chrono::steady_clock::now();
	}

	void TimedEvents::stopClock()
	{
		endTime = std::chrono::steady_clock::now();
	}

	void TimedEvents::addEvent(const char* eventStr)
	{
		if (eventStr != nullptr)
		{
			if (numEvents < MAXEVENTS)
			{
				events[numEvents].eventName = eventStr;
				events[numEvents].timeUnits = "nanoseconds";
				events[numEvents].duration = chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);

				++numEvents;
			}
		}
	}

	ostream& operator<<(ostream& ostr, const TimedEvents& object)
	{
		ostr << "--------------------------" << endl;
		ostr << "Execution Times:" << endl;
		ostr << "--------------------------" << endl;

		for (int i = 0; i < object.numEvents; i++)
		{
			ostr << setw(20) << left << object.events[i].eventName
				<< setw(12) << right << object.events[i].duration.count() 
				<< " " << object.events[i].timeUnits << endl;
		}
		ostr << "--------------------------" << endl;

		return ostr;
	}
}