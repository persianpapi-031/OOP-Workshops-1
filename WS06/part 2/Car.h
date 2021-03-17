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

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <string>
#include "Vehicle.h"

namespace sdds
{
	class Car : public Vehicle
	{
		std::string make{}; // string > char array
		char m_condition{}; // denoted by a single letter, so char not string
		double tSpeed{}; // speed needs to allow decimal

	public:
		Car() = default;
		Car(std::istream& in);
		~Car() = default;

		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
	};
}

#endif
