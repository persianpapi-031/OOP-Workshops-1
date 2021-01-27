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

#ifndef SDDS_EVENT_H
#define SDDS_EVENT_H

extern unsigned long g_sysClock;

namespace sdds
{
	class Event
	{
		char* descEvent;
		unsigned long time;

	public:

		Event();
		Event(const Event&);
		~Event();

		void display() const;
		void set();
		void set(char*);

		Event& operator=(const Event&);
	};

}
#endif
