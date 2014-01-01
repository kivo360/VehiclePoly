#ifndef VEHICLE_H
#define VEHICLE_H

#include  <iostream>
#include  <string>
#include  <fstream>
using std::string;
using std::ifstream;



class Vehicle
{


public:
	
	Vehicle();
	virtual ~Vehicle();
	Vehicle(ifstream &);
	Vehicle(const Vehicle&);			// This is the copy constructor
	void operator=(const Vehicle&);		//assignment overload operator
	bool operator==(const Vehicle&);	//Checks for the quality of the two objects

	//Getters
	int getVID();
	string getManufact();
	string getColor();
	int getAccnum();
	
	//Get stuff from array
	void startAcc();
	string nextAcc();
	bool hasNextAcc();

	virtual void print() const;
	virtual double getCost() const;

	string getModel();
	
	string * accesories;
	double *costList;
	

private:
	int vID; 			// Vehicle identification numbers
	string manufact; 	//The manufacturer
	string color;
	double cost;
	int accNum; 		//Number of accesories 
	
	string model;
	int IteratorCounter;
	

};

#endif