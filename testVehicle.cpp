/**
*	Author: Kevin Hill
*	Assignment: Project4
*	Description: VehicleDB
**/

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "Vehicle.h"
#include "Truck.h"
#include "Car.h"

using namespace std;


int main(int argc, char const *argv[])
{

	string fileName; //This is the file name
	 //Vehicle array
	ifstream file; //Instantiate file
	string sLine;
	Vehicle **vehArr;

	//Tell user to enter data
	cout << "Enter the file name: ";
	cin >> fileName;
	file.open(fileName.c_str());
	if(!file.is_open()){
		cerr << "The file is not there" << endl;
		return 1;
	}

	
	//Get first line of file to determine size of vehArr	
	for (int i = 0; !file.eof(); ++i)
	{
		if (i == 0){
			getline(file, sLine); 
			break;
		}
	}

	int arrSize = atoi(sLine.c_str());
	vehArr =  new (nothrow) Vehicle*[arrSize];

	for (int i = 0; i < arrSize; ++i)
	{
		vehArr[i] = 0;
	}

	string truck = "truck";
	string car = "car";
	string data;
	int i = 0;

	while(!(file >> data >> ws).eof()){
		if (data == car)
		{
			
			vehArr[i] = new Car(file);

		}
		if (data == truck)
		{
			vehArr[i] = new Truck(file);
		}
		i++;
	}

	double totalCost = 0.0;
	for (int i = 0; i < arrSize; ++i)
	{
		vehArr[i] -> print();
		totalCost = (vehArr[i] -> getCost()) + totalCost;
	}
	cout << totalCost << endl;
 	int deletedNum;;
	string deleted;
	while(true){
		
		cin.ignore();
		cout << "Pick a vehicle " << "0 - " << (arrSize -1) << " : ";
		cin >> deleted;
		deletedNum = atoi(deleted.c_str());
		if (deletedNum >= 0 && deletedNum <= (arrSize -1)){

		delete vehArr[deletedNum];
		vehArr[deletedNum] = NULL;

			//Swap stuff;
			for (int i = deletedNum; i <= (arrSize -1); ++i)
			{
				if (vehArr[i+1]!=NULL)
				{
					vehArr[i] = vehArr[i+1];
				}
				
			}

			
			arrSize--;
		// 	break;
		}
		break;
	}
	
	//Print new setup
	cout << "---------------------" << endl << endl;

	for (int i = 0; i < arrSize; ++i)
	{
		vehArr[i] -> print();
	}
	return 0;
}
