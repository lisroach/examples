//****************************************
//
//	Project File: linkedList.h
//	Author: Lisa Roach
//	Purpose: Declare linkedList class and listNode struct
//	Date: April 01, 2014
//	Email: lisaroach14@yahoo.com
//****************************************

//*************************************
// Function: linkedList()
// Purpose: constructor for linkedlist class
//
// Parameters: None
// 
//************************************
//*************************************
// Function:operator()
// Purpose: Overload the () operator so the priority queue sorts 
// listNodes based on weight or alphabetically
// Parameters: listNode<T>* node1, listNode<T>* node2
// Calls: None
// 
//************************************
//*************************************
// Function:isEmptyList()
// Purpose: Checks if the list is empty
//
// Parameters: None
// Calls: None
//
//************************************
//*************************************
// Function:length()
// Purpose: returns the number of nodes in the 
//	    linked list
// Parameters:None
// Calls:None
//
//************************************
//*************************************
// Function: front()
// Purpose: Returns the node at the front of the list
//
// Parameters: None
// Calls:None
//
//************************************
//*************************************
// Function:back()
// Purpose:Returns the node at the back of the list
//
// Parameters:None
// Calls:None
//
//************************************
//*************************************
// Function: setWeight
// Purpose:Set the weight of the node
//
// Parameters:string item, listNode<T>* current
// Calls:None
//
//************************************
//*************************************
// Function:insertLast
// Purpose:Insert a node at the end of the list
//
// Parameters:T& item
// Calls:None
//
//************************************

#ifndef LinkedList
#define LinkedList

#include <string>

template <class T>
struct listNode{
	T name;		//to store the identifier of the vertex 
	double weight;	//to store the weight of the edge
	listNode* next;	//link to the next node
	bool visited;
	T parent;

};

template <class T>
class linkedList{
	public:
		linkedList();	
		bool operator()(const listNode<T>* node1, const listNode<T>* node2);
		bool isEmptyList();
		int length() const;
		listNode<T>* front() const;
		listNode<T>* back() const;
		bool setWeight(const std::string item, listNode<T>* current);
		void insertLast(const T& item);
		//void printList(const linkedList currentList);
		
		protected:
			int count;	//stores the number of elements in a list
			listNode<T>* first; 	//pointer to first node of the list
			listNode<T>* last;	//pointer to last node of the list

};

#endif
