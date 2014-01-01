#ifndef TRUCK_H
#define TRUCK_H

#include <string>
#include <fstream>
#include <stdlib.h>

#include "Vehicle.h"

using std::string;


class Truck : public Vehicle
{
	public:

		Truck();
		Truck(ifstream&);
		~Truck();									   
		
		int getHP(); //Gets the city EPA
		string getTransmission();

		void print() const;
		double getCost() const;
	private:
		string transmission;
		int hpEng;

};

#endif