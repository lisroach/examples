//****************************************************
//	Project File: list.cc
//	Author: Lisa Roach
//	Purpose: Implementation file for linkedList class
//
//	Email: lisaroach14@yahoo.com
//	date: April 01, 2014
//****************************************************


#include "linkedList.h"
#include <cstddef> 	//for NULL
#include <stdlib.h>
//#include <iostream>

//NOT IN USE- Prints the list
/*
template<class T>
void linkedList<T>::printList(const linkedList<T> currentList){
	
	listNode<T>* current;
	current = currentList.first;
	while(current != NULL){
		std::cout<<current->name<<" "<<current->weight<<std::endl;
		if(current->next != NULL){
			current->next;
			std::cout<<current->next->name<<" "<<current->next->weight<<std::endl;
			break;
		}
		else{
			break;
		}
	}	
}*/

//***********************************************
//
// Function: operator()
//
// Purpose: Overloads the () operator for the priority queue. Sorts the queued items
//	    by weight, unless weight is the same, then sorts alphabetically by name.
// Parameters: listNode<T>* node1, listNode<T>* node2
//
//
// Member/Global Variables: listNode's weight and  name. Used for bfsQueue variable.
//
// Pre Conditions:.push() has been called on a priority queue
//
// Post Conditions: true is returned if note1's weight is greater than node2's, or if node1's
//		    name comes first alphabetically
//
// Calls: None
//
// Asymptotic Time Complexity: O(1) - constant time.
//
// Asymptotic Space Complexity: O(1)- constant space
//
//************************************************


template <class T>
bool linkedList<T>::operator()(const listNode<T>* node1, const listNode<T>* node2){
	if(node1->weight != node2->weight)
	{
		 return(node1->weight > node2->weight);
	}
	else{
		 return(node1->name > node2->name);
	}

}

//***********************************************
//
// Function: isEmptyList()
//
// Purpose: Retursn true if the list if empty
//
// Parameters: none
//
//
// Member/Global Variables: first
//
// Pre Conditions: A list has been initialized
//
// Post Conditions: True if list is null, false if there is something in the list
//
//
// Calls: None
//
// Asymptotic Time Complexity: O(1) - constant time
//
// Asymptotic Space Complexity: O(1) - constant space
//
//************************************************


template <class T>
bool linkedList<T>::isEmptyList(){
	return (first == NULL);
}

//***********************************************
//
// Function: setWeight
//
// Purpose: Set the weight of the list node
//
// Parameters: string itme, listNode<T>* current
//
//
// Member/Global Variables: weight
//
// Pre Conditions: The listNode has been created
//
// Post Conditions: The listNode's weight has been set
//
//
// Calls: atof - for conversion from string to double
//
// Asymptotic Time Complexity: O(1)
//
// Asymptotic Space Complexity: O(1)
//
//************************************************


template <class T>
bool linkedList<T>::setWeight(const std::string item, listNode<T>* current){
	if(item == ""){
		current->weight = 1;
	}
	else{
		current->weight = atof(item.c_str());
		if(item != "0" && current->weight == 0){
			return (true);
		}
	}
	return (false);
}
//***********************************************
//
// Function: linkedList()
//
// Purpose: Initialize a linkedList
//
// Parameters: None
//
//
// Member/Global Variables: first, count, last
//
// Pre Conditions: None
//
// Post Conditions: first, last set to NULL, count set to 0
//
//
// Calls: None
//
// Asymptotic Time Complexity: O(1)
//
// Asymptotic Space Complexity: O(1)
//
//************************************************


template <class T>
linkedList<T>::linkedList(){
	first = NULL;
	last = NULL;
	count = 0;
}
//***********************************************
//
// Function: length()
//
// Purpose: None
//
// Parameters: None
//
//
// Member/Global Variables:count
//
// Pre Conditions:A list has been initialized
//
// Post Conditions: Count is returned
//
//
// Calls:None
//
// Asymptotic Time Complexity: O(1)
//
// Asymptotic Space Complexity:O(1)
//
//************************************************


template <class T>
int linkedList<T>::length() const{
	return count;
}
//***********************************************
//
// Function: front()
//
// Purpose: Return the value of first in a list
//
// Parameters: None
//
//
// Member/Global Variables: None
//
// Pre Conditions:A list has been initialized
//
// Post Conditions: First is returned
//
// Calls:None
//
// Asymptotic Time Complexity: O(1)
//
// Asymptotic Space Complexity:O(1)
//
//************************************************


template <class T>
listNode<T>* linkedList<T>::front () const{
	return (first);
}

//***********************************************
//
// Function:back()
//
// Purpose: Returns the value of the last node in the list
//
// Parameters:None
//
//
// Member/Global Variables:None
//
// Pre Conditions:A list has been initialized
//
// Post Conditions: Returns the value of last
//
// Calls:None
//
// Asymptotic Time Complexity:O(1)
//
// Asymptotic Space Complexity:O(1)
//
//************************************************


template <class T>
listNode<T>* linkedList<T>::back() const{
	return (last);
}
//***********************************************
//
// Function:insertLast
//
// Purpose: Insert a node into the last location of the linked list
//
// Parameters:T item
//
//
// Member/Global Variables: name, next, visited, weight, last, count
//
// Pre Conditions: A list has been initialized
//
// Post Conditions: A new node is added to the end of the linked list
//
//
// Calls: None
//
// Asymptotic Time Complexity: O(1) - constant time
//
// Asymptotic Space Complexity:O(1) - constant time
//
//************************************************


template <class T>
void linkedList<T>::insertLast(const T& item){
	listNode<T>* newNode;
	newNode = new listNode<T>;
	newNode->name = item;
	newNode->next = NULL;
	newNode->visited = false;
	newNode->weight = -1;

	if(first == NULL){
		first = newNode;
		last = newNode;
		count++;
	}
	else{		//list is not empty
		last->next = newNode;	//make last point to the actual last node
		last = newNode;		
		count++;
	}
}

