//**************************************
//	Project File: graph.h
//	Purpose: Defines a graph class
//	Author: Lisa Roach
//	Date: Apriil 01, 2014
//	Email: lisaroach14@yahoo.com	
//*************************************
//*************************************
// Function:graphType()
// Purpose:constructor for graphType class
//
// Parameters:None
// Calls: None
//
//************************************
//*************************************
// Function:isVisited
// Purpose:Determines is the node has been visited in the 
//	   breadth first traversal
// Parameters:listNode<std::string>* current
// Calls: None
//
//************************************
//*************************************
// Function:createBinarySearchtree
// Purpose:Creates the binary search tree where the vertices and their edges are stored
//
// Parameters:string item
// Calls:None
//
//************************************
//*************************************
// Function:createEdges
// Purpose:Sets teh edges of the graph in a linked list connected to the parent vertex
//
// Parameters:string item, int edgeCount, node* startNode, int count
// Calls:insertLast, back, setWeight
//
//************************************
//*************************************
// Function:breadthFirstTraversal
// Purpose:Fill the output queue with breadth frist found edges
//
// Parameters:string vertex
// Calls:push, top, markVisited, fillQueue, searchTree, pop
//
//************************************
//*************************************
// Function:markVisited
// Purpose:Mark all instances of a vertex as visited
//
// Parameters:listNode<std::string>* current
// Calls:searchTree
//
//************************************
//*************************************
// Function:setDirection
// Purpose:Sets teh global variable direction to true or false if directed or undirected
//
// Parameters:string item
// Calls:None
//
//************************************
//*************************************
// Function:setMax
// Purpose:Sets the number of vertices allowed
//
// Parameters:string item
// Calls:atof --for conversion
//
//************************************
//*************************************
// Function:fillQueue
// Purpose:Fill the priority queue with all adjacent vertices
//
// Parameters:string vertex
// Calls:isVisited, length, searchTree, findAdjVertices, push
//
//************************************
//*************************************
// Function:findAdjVertices
// Purpose:Add adjacent parameters listed under their partner vertexes for undirected lists
//
// Parameters:node* current, node* find
// Calls:front, push
//
//************************************
//*************************************
// Function:getSize
// Purpose:returns the number of vertices listed in the file
//
// Parameters:None
// Calls:None
//
//************************************
//*************************************
// Function:setEdges()
// Purpose:Sets the number of edges that is read in from the graph
//
// Parameters:string item
// Calls:None
//
//************************************
//*************************************
// Function:searchTree
// Purpose:Return the node that has the name searched for
//
// Parameters:string item
// Calls:None
//
//************************************
//*************************************
// Function:addNode
// Purpose:Add a new node to the binary search tree
//
// Parameters:string item
// Calls:None
//
//************************************

#ifndef GRAPH
#define GRAPH

#include <string>
#include "linkedList.h"
#include <queue>

struct node{
	std::string data;
	node* left;
	node* right;
	linkedList<std::string> list;
	bool visited;
};

class graphType: public linkedList<std::string>{
	public:
		graphType();

		bool isVisited(listNode<std::string>* current);

		bool createBinarySearchTree(const std::string& item);	

		bool createEdges(const std::string& item, int& edgeCount, node*& startNode, int& count);

		std::queue<std::string> breadthFirstTraversal(const std::string vertex);

		void markVisited(listNode<std::string>* node);

		//Sets the global variable direction
		//direction is true is it is directed, false is unidrected
		//returns a true if there was an error
		bool setDirection(const std::string& item);
	
		//Sets the global variable maxSize
		//Returns true if there was an error with the conversion
		bool setMax(const std::string& item);

		//Queue stuff
		void fillQueue(const std::string& vertex);

		void findAdjVertices(node* vertex, node* find);

		int getSize();

		bool setEdges(const std::string& item);

		int getEdgeNum();

		node* searchTree(const std::string& item);
		
		node* addNode(const std::string& item);
	
	protected:
		int maxSize; 			//maximum number of vertices in the graph
		bool direction;			//false is undirected true is directed
		node* root;			//Root of the binary search tree		
		int edgeNum; 			//Number of edges
		std::queue<std::string> outputQueue; 	//Queue that holds the spanning tree
		std::priority_queue<listNode<std::string>*, std::vector<listNode<std::string>*>, linkedList<std::string> > bfsQueue;//queue of vertices
		
};


#endif
