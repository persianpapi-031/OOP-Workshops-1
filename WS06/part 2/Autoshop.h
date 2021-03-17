//=================================================
// Name:           Kian Dadkhah Shokrollahi
// Student Number: 119369205
// Email:          kdadkhah-shokrollahi@myseneca.ca
// Course:         OOP345
// Section:        NCC
// Workshop:       6 (part 2)
//=================================================
 /*I have done all the coding by myself and only copied the code
  that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include <vector>
#include <list>

#include "Vehicle.h"

namespace sdds
{
	class Autoshop
	{
		std::vector<Vehicle*> m_vehicles;

	public:
		Autoshop& operator +=(Vehicle*);
		void display(std::ostream& out);
		~Autoshop();

		/* Template Function */
		template <typename T>
		void select(T test, std::list<const Vehicle*>& vehicles)
		{
			std::vector<Vehicle*>::iterator i;
			for (i = m_vehicles.begin(); i != m_vehicles.end(); i++)
			{
				if (test(*i))
				{
					vehicles.push_back(*i);
				}
			}
		}
	};
}

#endif
