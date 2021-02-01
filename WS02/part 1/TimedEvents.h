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

#ifndef SDDS_TIMED_EVENTS_H
#define SDDS_TIMED_EVENTS_H

#include <chrono>
#include <ostream>

namespace sdds
{
	const int MAXEVENTS = 10;

	class TimedEvents
	{
		int numEvents = 0;
		std::chrono::steady_clock::time_point startTime;
		std::chrono::steady_clock::time_point endTime;

		struct
		{
			std::string eventName;
			std::string timeUnits;
			std::chrono::steady_clock::duration duration;
		} events[MAXEVENTS];

	public:
		TimedEvents() = default;

		void startClock();
		void stopClock();
		void addEvent(const char*);

		friend std::ostream& operator<<(std::ostream&, const TimedEvents&);
	};
}

#endif
