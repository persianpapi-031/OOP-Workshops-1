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
