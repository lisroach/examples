//************************************
//	Project: 6, Sorting
//	File: hsort.h Header file for heap sort
//	Author: Lisa Roach
//	Email: lisaroach14@yahoo.com
//	Date: April 28, 2008
//
//	Purpose: contains the function calls for heap sort
//************************************

//*************************************
// Function: hsort
// Purpose: Start the heap sort (calls other functions)
// Parameters: vector<myType> input_list
//*************************************
//*************************************
// Function: buildHeap
// Purpose: Builds the list into a heap that will be sorted
// Parameters: vector<myType> input_list
//*************************************
//*************************************
// Function: heapify
// Purpose: Sort the heap
// Parameters: int low, int high, vector<myType> input_list
//**************************************
//**************************************
// Function: printHeap
// Purpose: For testing, prints the sorted list
// Parameters: vector<,yType> input_list
//************************************

#ifndef HSORT
#define HSORT

#include <vector>
#include <cstddef>

//heap sort function call
template<typename myType>
void hsort(std::vector<myType> &input_list);

//build the list into a heap
template<typename myType>
void buildHeap(std::vector<myType> &input_list);
		
template<typename myType>
void heapify(int low, int high, std::vector<myType> &input_list);

template<typename myType>
void printHeap(std::vector<myType> &input_list);

#include "hsort.template"

#endif
