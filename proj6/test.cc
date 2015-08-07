//***************************************************
//
//	Project: Project 6 -- Sorting
//	Author: Lisa Roach
//	Email: lisaroach14@yahoo.com
//	Date: 4/28/2014
//	Purpose: Demonstrate a heap, quick and merge sort on various data types.
//		This particular file generates all of the lists of data and calls
//		the sorts.
//
//	Time Complexity: O(n^9logn^2) --with n as RAND_MAX (the largest number a random
//	value can be for this computer.
//	Space Complexity: O(n^2)
//***************************************************

#include <vector>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>

#include "qsort.h"
#include "hsort.h"
#include "msort.h"


using namespace std;

//Here is a random class to use sort class objects later
//*************************
// operator<, operator>
// Purpose: The operators are overloaded for comparisons of the class object, helloWorld
// Time: O(1)
// Space: O(1)
//*************************
//************************
// helloWorld
// Purpose: Constructor for hellowWorld, sets hello to a random integer
// Time: O(1)
// Space: O(1)
//************************
class helloWorld{
	public:
		int hello;
		helloWorld();	//constructor initializes hello to a random value
		bool operator<(const helloWorld& classA) const;
		bool operator>(const helloWorld& classA) const;
	
};

//***************************
// All of the following functions
// are used to generate random lists 
// of the objects specified in their
// vector declarations.
//****************************

vector<int> randomInt(int& size);
vector<double> randomDouble(int& size);
vector<string> randomString(int& size);
vector<helloWorld> randomClass(int& size);

int main(){
	vector<int> intVec;		//Vector of random integers
	vector<double> doubleVec;	//Vector of random doubles
	vector<string> stringVec;	//Vector of strings
	vector<helloWorld> classVec;	//Vector of class objects
	int sizeInt = 0, sizeDouble = 0, sizeString =0, sizeClass = 0; //Size of the random object list
	int sumHeap = 0, sumQuick = 0, sumMerge = 0; //Placeholders for the sum of the times
	double avgHeap = 0, avgQuick = 0, avgMerge = 0; //Holds the average time for each sort
/*	
	string value;
	while(cin>>value){
		stringVec.push_back(value);
	}

	cout<<"Heap"<<endl;
	hsort(stringVec);
	
	cout<<"Quick Sort"<<endl;
	qsort(stringVec);

	msort(stringVec);
*/



	srand(time(NULL));	//initialize random seed
	//The #s are used so that gnuplot reads text as comments
	cout<<"#List Size"<<setw(20)<<right<<"Heap Sort"<<setw(20)<<"Quick Sort"<<setw(20)<<"Merge Sort"<<endl;
	
	for(int i=0; i<10; i++){
		//Generate random ints
		intVec = randomInt(sizeInt);

		//Generate random doubles
		doubleVec = randomDouble(sizeDouble);

		//Generate random strings
		stringVec = randomString(sizeString);

		//Generate random class objects
		classVec = randomClass(sizeClass);

		
		//STRINGS
		//*******************************************
		cout<<sizeString;
		clock_t start, stop;
		start = clock();	
		hsort(stringVec);
		stop = clock();
		sumHeap += (stop-start);
		cout<<setw(20)<<right<<(double)(stop-start);

		clock_t startQ, stopQ;
		startQ = clock();
		qsort(stringVec);
		stopQ = clock();
		sumQuick += (stopQ-startQ);
		cout<<setw(20)<<right<<(double)(stopQ-startQ);

		clock_t startM, stopM;
		startM = clock();
		msort(stringVec);
		stopM = clock();
		sumMerge += (stopM-startM);
		cout<<setw(20)<<right<<(double)(stopM - startM)<<endl;

		//*******************************************

		//INTS SORT
		//*******************************************	
		cout<<sizeInt;

		start = clock();	
		hsort(intVec);
		stop = clock();
		sumHeap += (stop-start);
		cout<<setw(20)<<right<<(double)(stop-start);

		startQ = clock();	
		qsort(intVec);
		stopQ = clock();
		sumQuick += (stopQ-startQ);
		cout<<setw(20)<<right<<(double)(stopQ-startQ);

		startM = clock();	
		msort(intVec);
		stopM = clock();
		sumMerge += (stopM-startM);
		cout<<setw(20)<<right<<(double)(stopM-startM)<<endl;


		//********************************************


		//DOUBLES SORT
		//********************************************
		cout<<sizeDouble;	

		start = clock();	
		hsort(doubleVec);
		stop = clock();
		sumHeap += (stop-start);
		cout<<setw(20)<<right<<(double)(stop-start);


		startQ = clock();	
		qsort(doubleVec);
		stopQ = clock();
		sumQuick += (stopQ-startQ);
		cout<<setw(20)<<right<<(double)(stopQ-startQ);


		startM = clock();	
		msort(doubleVec);
		stopM = clock();
		sumMerge += (stopM-startM);
		cout<<setw(20)<<right<<(double)(stopM-startM)<<endl;
	
		//*********************************************
		
		//CLASS SORT
		//*********************************************
		cout<<sizeClass;

		start = clock();
		hsort(classVec);
		stop = clock();
		sumHeap += (stop-start);
		cout<<setw(20)<<right<<(double)(stop-start);

		startQ = clock();
		qsort(classVec);
		stopQ = clock();
		sumQuick += (stopQ-startQ);
		cout<<setw(20)<<right<<(double)(stopQ-startQ);

		startM = clock();
		msort(classVec);
		stopM = clock();
		sumMerge += (stopM-startM);
		cout<<setw(20)<<right<<(double)(stopM-startM)<<endl;
	
		//**********************************************


	}//for loop
	
	cout<<"#Average Times: "<<endl;
	avgHeap = sumHeap/40;		//each variable type runs 10 times (4 variable types)
	avgQuick = sumQuick/40;
	avgMerge = sumMerge/40;

	cout<<"#Heap Sort: "<<avgHeap<<endl;
	cout<<"#Quick Sort: "<<avgQuick<<endl;
	cout<<"#Merge Sort: "<<avgMerge<<endl;
	
}

//*************************************
// Function:randomInt
// Purpose:Generates a random list of integers
// 
// Parameters:int size
// Calls:rand()
// Time Complexity: O(size)
// Space Complexity:O(size) --gets resized for the vector
//
//*************************************

//Generates random ints
//For a vector of a randomized length
vector<int> randomInt(int& size){
	vector<int> vec;
	int value;

	size = rand() % 100000 + 1;	//the list will be between 1 and 100,000 numbers long
	
	for(int i = 0; i < size; i++){
		value = rand();
		vec.push_back(value);
	}
		
	return(vec);
}
//*************************************
// Function:randomDouble
// Purpose: Generates a random list of doubles
// 
// Parameters:int size
// Calls: rand()
// Time Complexity: O(size)
// Space Complexity: O(size)
//
//*************************************

vector<double> randomDouble(int& size){
	vector<double> vec;
	double value;

	size = rand() % 100000 + 1;
	
	for(int i=0; i < size; i++){
		value = rand();
		vec.push_back(value);
	}

	return(vec);

}
//*************************************
// Function: randomString
// Purpose: Generates a list of random strings. Randomizes string lengths as well.
// 
// Parameters:int size
// Calls: rand(), resize()
// Time Complexity: O(size * length)
// Space Complexity: O(size* length)
//
//*************************************

vector<string> randomString(int& size){
	static const char alphanum[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	vector<string> vec;
	string value;

	size = rand() % 100000 +1;
	
	for(int k = 0; k < size; k++){	
		int length = rand() % 20 +1;	//random string length
		value.resize(length);
		for(int i = 0; i < length; ++i){
			value[i] = alphanum[rand() % (sizeof(alphanum) -1)];
		}
		vec.push_back(value);
	}
	
	return(vec);
}

//*************************************
// Function:helloWorld
// Purpose:Sets hello to a random integer value
//Constructor for helloWorld class
// Parameters:none
// Calls:None
// Time Complexity: O(1)
// Space Complexity: O(1)
//
//*************************************

helloWorld::helloWorld(){
	hello = rand();	//initializes hello to a random number
}


//*************************************
// Function: operator <
// Purpose:Overloaded < operator for comparison of helloWolrd objects
// 
// Parameters:helloWolrd classA
// Calls:None
// Time Complexity: O(1)
// Space Complexity: O(1)
//
//*************************************

bool helloWorld::operator<(const helloWorld& classA) const{
	return(classA.hello < hello);

}

//*************************************
// Function: operator >
// Purpose: Overloaded > operator for comparision of helloWorld objects
// 
// Parameters:helloWorld classA
// Calls: none
// Time Complexity: O(1)
// Space Complexity:O(1)
//
//*************************************

bool helloWorld::operator>(const helloWorld& classA) const{
	return(classA.hello > hello);
}


//*************************************
// Function: randomClass
// Purpose: Creates a random list of helloWolrd class objects
// Parameters: int size
// Calls:rand()
// Time Complexity: O(size)
// Space Complexity: O(size)
//
//*************************************

vector<helloWorld> randomClass(int& size){
	vector <helloWorld> vec;
	
	size = rand() % 100000 +1;
	
	for(int i = 0; i < size; i++){
		helloWorld value;
		vec.push_back(value);
	}
	return vec;

}

