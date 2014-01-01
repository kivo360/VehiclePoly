#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "Car.h"

using namespace std;

Car::Car() : Vehicle( ){
	this->epaHighway = 0;
	this->epaCity = 0;
	cout << "Car Created" << endl;
}

Car::Car(ifstream& file)
:Vehicle(file){
	string moreD;

	int i = 0;

	while(getline(file, moreD)){
		//cout << moreD << endl;
		if (i == 0)
		{
			epaCity = atoi(moreD.c_str());
		}
		if (i == 1)
		{
			epaHighway = atoi(moreD.c_str());
			cout << endl;
			break;
		}
		i++;
	}
}



Car::~Car(){
	
}

/**
*	Get vehicle the cost of the video
*	no params
*	return cost;
**/
double Car::getCost() const{
	double carCost = Vehicle::getCost();
	double mileage = ((.6 * epaHighway) + (.4 * epaCity));
	if (mileage < 22)
	{
		carCost = 1000.00 + carCost;
	}
	return carCost;
}

void Car::print() const{
	// cout << "Description: " << this->description << '\n';
	Vehicle::print();
	cout << "Grand total - " << getCost() << endl;
	cout << "--" << endl << endl;
}

int Car::getCity(){
	return this->epaCity;
}

int Car::getMile(){
	return this->epaHighway;
}
