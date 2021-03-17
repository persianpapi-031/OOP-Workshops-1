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

#include "Autoshop.h"
#include "Car.h"

using namespace std;
namespace sdds
{
	Autoshop& Autoshop::operator+=(Vehicle* vehicle)
	{
		m_vehicles.push_back(vehicle);
		return *this;
	}

	void Autoshop::display(ostream& out)
	{
		out << "--------------------------------\n";
		out << "| Cars in the autoshop!        |\n";
		out << "--------------------------------\n";

		vector<Vehicle*>::iterator v;
		for (v = m_vehicles.begin(); v != m_vehicles.end(); v++)
		{
			(*v)->display(out);
			out << endl;
		}

		out << "--------------------------------\n";
	}

	Autoshop::~Autoshop()
	{
		vector<Vehicle*>::iterator v;
		for (v = m_vehicles.begin(); v != m_vehicles.end(); v++)
		{
			delete* v;
		}
	}
}