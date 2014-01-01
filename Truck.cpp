#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "Truck.h"

using namespace std;
// : Vehicle()

Truck::Truck() {
	cout << "Truck Created" << endl;
}

Truck::Truck(ifstream& file)
	: Vehicle(file){
	
	string moreD;
	int i = 0;
	while(getline(file, moreD)){
		
		if (i == 0)
		{
			transmission = moreD;
		}
		//cout << moreD << endl;
		if (i == 1)
		{	
			hpEng = atoi(moreD.c_str());
			cout << endl;
			break;
		}
		i++;
	}
}

/**
* The copy constructor
**/



Truck::~Truck(){
	//deconstruct costList array
	
}

/**
*	Get vehicle the cost of the video
*	no params
*	return cost;
**/
double Truck::getCost() const{
	double truckCost = Vehicle::getCost();
	if (hpEng > 350)
	{
		truckCost = ((hpEng-350)*50) + truckCost;
	}
	return truckCost;
}

void Truck::print() const{
	Vehicle::print();
	cout << "Grand total - $" << getCost() << endl;
	cout << "--" << endl <<endl;
}

int Truck::getHP(){
	return this->hpEng;
}
string Truck::getTransmission(){
	return this->transmission;
}