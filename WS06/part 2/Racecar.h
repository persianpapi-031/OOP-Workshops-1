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

#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H

#include "Car.h"

namespace sdds
{
	class Racecar : public Car
	{
		double m_booster{ 0 };

	public:
		explicit Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topSpeed() const;
	};
}

#endif
