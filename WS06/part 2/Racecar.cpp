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

#define _CRT_SECURE_NO_WARNINGS

#include "Racecar.h"

using namespace std;
namespace sdds
{
	Racecar::Racecar(istream& in) : Car(in)
	{
		string t_boost;
		getline(in, t_boost, '\n');
		m_booster = stod(t_boost);
	}

	void Racecar::display(ostream& out) const
	{
		Car::display(out);
		out << "*";
	}

	double Racecar::topSpeed() const
	{
		return (Car::topSpeed() * (1 + m_booster));
	}
}
