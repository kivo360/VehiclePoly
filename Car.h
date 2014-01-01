#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

#include "Vehicle.h"

class Car : public Vehicle
{
	public:

		Car();
		Car(ifstream&);
		~Car();									   
		void print() const;
		double getCost() const;
		int getCity(); //Gets the city EPA
		int getMile();

	private:
		int epaHighway;
		int epaCity;



};

#endif