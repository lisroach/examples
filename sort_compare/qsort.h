//***********************************************
//
//	File: qsort.h Header file for quicksort
//	Project: Project 6- Sorting
//	Author: Lisa Roach
//	Email: lisaroach14@yahoo.com 
//	Purpose: Contains the function calls for the quick sort
//***********************************************
//***********************************************
// Function: qsort
// Purpose: Calls all the functions for quick sort
// Parameters: vector<myType> input_list
//***********************************************
//***********************************************
// Function: partitiion
// Purpose: Partition the list into two lists
// Parameters: int firts, int last, vector<myType> input_list
//**********************************************	
//**********************************************
// Function: swap
// Purpose: Swap two values in the list
// Parameters: int first, int second, vector<myType> input_list
//**********************************************
//**********************************************
// Function: recQuickSort
// Puspose: Recursive call to itself, partitions and swaps values
// Parameters: int first, int last, vector<myType. input_list
//**********************************************
//**********************************************
// Function: print_quick
// Purpose: Testing function, prints teh sorted list
// Parameters: vector<myType> input_list
//**********************************************
#ifndef QSORT
#define QSORT

#include <vector>

template <typename myType>
void qsort(std::vector<myType> &input_list);

template <typename myType>
int partition(int firts, int last, std::vector<myType> &input_list);
		
template <typename myType>
void swap(int first, int second, std::vector<myType> &input_list);

template <typename myType>
void recQuickSort(int first, int last, std::vector<myType> &input_list);

template <typename myType>
void print_quick(std::vector<myType> &input_list);



#include "qsort.template"

#endif
