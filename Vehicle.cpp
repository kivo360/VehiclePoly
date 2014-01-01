#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "Vehicle.h"

using namespace std;

Vehicle::Vehicle(){
	vID = 999; // Vehicle identification numbers
	manufact = ""; // 
	color = "";
	cost = 0.0;
	accNum = 0; //Number of accesories 
	model = "";

}

Vehicle::Vehicle(ifstream& file){
	string node;
	int i = 0;
	int j = 0;
	// while(getline(file, node)){
	while(getline(file, node)){

	
		
//---------------------------------------------------------------
	//Get the basic information
		//Vehicle id
		if (i == 0){
			vID = atoi(node.c_str());
			// cout << node << " vID is Assigned : " << vID << endl;
		}

		//Car manufacturer
		if (i == 1){
			manufact = node;
			// cout << node  << " manufact is Assigned : " << manufact << endl;
		}

		//Model
		if (i == 2)
		{	

			model = node;
			// cout << node  << " model is Assigned : " << model << endl;
		}

		//Car color
		if (i == 3){
			color = node;
			// cout << node << " color is Assigned : " << color << endl;
			
		}
		//Car's cost
		if (i == 4){
			cost = atof(node.c_str());

		}


//---------------------------------------------------------------

		//Check for number of accessories
		if(i == 5){
			accNum = atoi(node.c_str());
			//Change the size of accessories array
			accesories = new (nothrow) string[accNum];
			costList = new (nothrow) double[accNum];
		}
		

		//if i > 0;
		if(accNum > 0 && i >= 6){
			// cout << "accesories : " << node << endl;
			
			accesories[j] = node;
			getline(file, node);
			
			costList[j] = atof(node.c_str());
			// j++;
			if (i == (accNum + 5)){
				break;	
			}
			
			
		}

		i++;
	}
	
}

/**
* The copy constructor
**/

Vehicle::Vehicle(const Vehicle& vec){

}

Vehicle::~Vehicle(){
	//Nothing happens here... for now :-)
	//deconstruct costList array
	// delete costList;
	// delete accesories;
}


//----------------	------Overload-Operators-----------------------------------

/**
*	Copies the vehicle to another vehicle
*	no params
*	return nothing;
**/
void Vehicle::operator=(const Vehicle& veh){
	vID = veh.vID; // Vehicle identification numbers
	manufact = veh.manufact; // 
	color = veh.color;
	cost = veh.cost;
	accNum = veh.accNum; //Number of accesories 
}

/**
*	Compares two different Vehicle Classes
*	no params
*	return match;
**/
bool Vehicle::operator==(const Vehicle& veh){
	if (vID == veh.vID && manufact == veh.manufact && color == veh.color && cost == veh.cost && accNum == veh.accNum){
		return true;
	} 
	return false;
}

/**
*	Get Vehicle identification number
*	no params
*	return vID;
**/
int Vehicle::getVID(){
	return vID;
}

/**
*	Get Vehicle manufacturer
*	no params
*	return maufact;
**/
string Vehicle::getManufact(){
	return manufact;
}

/**
*	Get Vehicle color
* 	Meant to retreive the car's color
*	no params
*	return color;
**/
string Vehicle::getColor(){
	return color;
}

/**
*	Get vehicle the cost of the video
*	no params
*	return cost;
**/
double Vehicle::getCost() const{
	double totalCost = cost;
	for (int i = 0; i < accNum; ++i)
	{
		totalCost = costList[i] + totalCost; 
	}
	return totalCost;
}

void Vehicle::print() const{
	cout << "Description" << endl;
	cout << "vID - " << this->vID << endl;
	cout << "manufacturer - " << this->manufact << endl;

}
/**
*	Get vehicle accessory number
*	no params
*	return accNum;
**/
int Vehicle::getAccnum(){
	return accNum;
}

void Vehicle::startAcc(){
	IteratorCounter = 0;
	
}

string Vehicle::nextAcc(){
	
	string access = accesories[IteratorCounter];
	IteratorCounter++;
	return access;
}

bool Vehicle::hasNextAcc(){
	//cout << "The IteratorCounter is " << IteratorCounter << endl;
	if (accesories[IteratorCounter] ==  ""){
		return false;
	}
	return true;
}