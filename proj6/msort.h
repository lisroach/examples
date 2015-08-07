//***************************************
// File: msort.h
// Purpose: Header file containing the merge sort function declarations
// Author: Lisa Roach
// Date: 4/28/2014
//
//*****************************************
//********************************
// Function: mSort
// Purpose: Partitions the lists and merges them back together
// Parameters: vector<myType> input_list
//********************************
//*******************************
// Function: merge
// Pupose: Merges two lists
// Parameters: vector<myType> input_list
//*******************************
//*******************************
// Function: printMerge
// Purpose: Testing function, prints the sorted list
// Parameters: vector<myType> input_list
//*******************************

//******************************
// I attempted to implement a natural mergesort, but it is buggy so I did not use it.
// The function declarations remain here commented out.
//******************************

#ifndef MERGESORT
#define MERGESORT

#include <vector>
using std::vector;

template <typename myType>
void msort(vector<myType>& input_list);

template <typename myType>
vector<myType> mergeSort(vector<myType>& input_list);

//void mergeSort(vector<myType> input_list, vector<myType> output_list, vector<myType> temp_list1, 
//vector<myType> temp_list2);

template <typename myType>
vector<myType> merge(const vector<myType>& left, const vector<myType>& right);

//template <typename myType>
//void naturalMerge(const vector<myType>& left, const vector<myType>& right, vector<myType>& 
//output_list);

template<typename myType>
void printMerge(vector<myType>& input_list);

#include "msort.template"

#endif
