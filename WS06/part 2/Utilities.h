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

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include <sstream>

#include "Vehicle.h"
#include "Car.h"
#include "Racecar.h"

namespace sdds
{
	Vehicle* createInstance(std::istream& in);
}

#endif
