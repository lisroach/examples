//**********************************
//
//	Project 4: Breadth First Search Graph
//	File: main.cc
//	Author: Lisa Roach
//	Purpose: Conduct a breadth first search of a graph and output its spanning tree
//
//	date: April 01, 2013
//	Email: lisaroach14@yahoo.com
//
//	Time Complexity: O(number of vertices^4*number of edges^2) is the overall time of the whole project. The main,
//	without function calls would be O(number of items in file * number of vertices-1), because it has to 
//	load in everything from the file and then outputs a spanning tree of number of vertices -1.
//
//	Space Complexity: O(number of vertices) due to all of the function calls
//************************************


#include <iostream>
#include <stdlib.h>	//for exit
#include "graph.h"

using namespace std;
 
int main(){
	graphType graph;			//graph object
	string line; 			//line to be read in from the file
	int count = 0; 			//counts the number of lines read from file
	bool error = false;		//if error = true then output the error message
	int numVertices = 0;		//the number of vertices
	int numEdges = 0;			//Total number of edges
	int edgeCount = 0; 			//Currently filled number of edges
	int tempCount = 0;			//Count for the createEdges functions
	int secondFileCount = 0;		//Make sure there is only one line in the second file
	node* tempNode = NULL;			//A tremporary node
	queue<string> outputQueue;		//Queue that will hold the spanning tree
	string start; 				//starting vertex

	while(getline(cin, line)){
		if(line[0] == '#'){	//skips over comments in the code
			continue;
		}
		if(count == 0){
			error = graph.setDirection(line);
			if(error){
				cout<<"Error in graph file!"<<endl;
				exit(1);
			}
			count++;
		}
		else if(count ==1){
			error = graph.setMax(line);	//Set the maximum # of vertices to the second line
			if(error){
				cout<<"Error in graph file!"<<endl;
				exit(1);
			}
			count++;
			numVertices = graph.getSize();
		}
		else if(count-1 <= numVertices)
		{
			error = graph.createBinarySearchTree(line);
			count++;
			if(error){
				cout<<"Error in graph file!"<<endl;
				exit(1);
			}
		}
		else if(count == numVertices +2){
			error = graph.setEdges(line);
			count++;
			if(error){
				cout<<"Error in graph file!"<<endl;
				exit(1);
			}
			numEdges = graph.getEdgeNum();

		}
		else if((count > numVertices +2) && (edgeCount < numEdges)){
			error = graph.createEdges(line, edgeCount, tempNode, tempCount);
			if(error){
				cout<<"Error in graph file!"<<endl; 
				exit(1);
			}
		}
		else{
			if(secondFileCount == 0){
				start = line;		
				secondFileCount++;
			}	
			else{				//ignore everything after the first line of 2nd file
				break;
			}
		}	
		 
	}
	outputQueue = graph.breadthFirstTraversal(start);	
	
	int size = outputQueue.size();	
	string value;
	for(int i = 0; i < size; i++){
		value = outputQueue.front();
		cout<<value<<endl;
		outputQueue.pop();
	}
	if(size != (numVertices-1)*3 && value != "Error in graph file!" || numEdges == 0){
		if(numVertices >1 || size != 3 && numVertices == 1){
			cout<<"No spanning tree."<<endl;
		}
	}
	return(1);
}
