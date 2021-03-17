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

#include "Utilities.h"

using namespace std;
namespace sdds
{
	Vehicle* createInstance(istream& in)
	{
		Vehicle* v_ptr = nullptr;
		string tempStr;

		getline(in, tempStr);
		tempStr.erase(0, tempStr.find_first_not_of(' '));
		stringstream line(tempStr);

		if (tempStr.empty())
		{
			v_ptr = nullptr;
		}
		else
		{
			switch (toupper(tempStr[0]))
			{
			case 'C':
				v_ptr = new Car(line);
				break;
			case 'R':
				v_ptr = new Racecar(line);
				break;
			default:
				string tag{};
				getline(line, tag, ',');
				throw "Unrecognized record type: [" + tag + "]";
				break;
			}
		}

		return v_ptr;
	}
}