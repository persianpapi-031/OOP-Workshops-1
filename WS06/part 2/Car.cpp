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

#include <iostream>
#include <iomanip>
#include <cctype>

#include "Car.h"

using namespace std;
namespace sdds
{
	Car::Car(istream& fin)
	{
		string tag;
		string speed;
		string condition;

		getline(fin, tag, ',');
		getline(fin, make, ',');
		getline(fin, condition, ',');
		getline(fin, speed, ',');
		make.erase(0, make.find_first_not_of(' '));
		make.erase(make.find_last_not_of(' ') + 1);
		condition.erase(0, condition.find_first_not_of(' '));
		condition.erase(condition.find_last_not_of(' ') + 1);
		speed.erase(0, speed.find_first_not_of(' '));
		speed.erase(speed.find_last_not_of(' ') + 1);

		if (condition.empty() || condition[0] == ' ')
		{
			m_condition = 'n';
		}
		else if (condition[0] == 'n' || condition[0] == 'u' || condition[0] == 'b')
		{
			m_condition = condition[0];
		}
		else
		{
			string err = "Invalid record!";
			throw err;
		}

		bool speedValid = true;
		for (int s : speed)
		{
			if (s < 48 || s > 57)
			{
				speedValid = false;
			}

			switch (speedValid)
			{
			case true:
				tSpeed = stod(speed);
				break;
			case false:
				string err = "Invalid record!";
				throw err;
				break;
			}
		}
	}

	string Car::condition() const
	{
		string condition;

		switch (m_condition)
		{
		case 'n':
			condition.assign("new");
			break;
		case 'u':
			condition.assign("used");
			break;
		case 'b':
			condition.assign("broken");
			break;
		}

		return condition;
	}

	double Car::topSpeed() const
	{
		return tSpeed;
	}

	void Car::display(ostream& out) const
	{
		out << "| " << right << setw(10) << make;
		out << " | " << left << setw(6) << condition();
		out << " | " << setw(6) << fixed << setprecision(2) << topSpeed();
		out << " |";
	}
}