//Dijkstra's Algorithm
//Referred to the code on https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/

/*
	The issues with what's here right now are that it only works for 9x9 2D arrays 
	and we still have to figure out how to output them properly. Hopefully what's here right now is a good start
*/

#include "pch.h"
#include <iostream>
#include <limits.h>
#include <stdio.h>
#define V 9
using namespace std; 

//Function to print out our stuff
void printSolution(int distance[], int n)
{
	printf("Distance Array:\n");
	for (int i = 0; i < V; i++)
	{
		printf("%6c%d", 'v', i, "\n" );


	}

	printf("\n");					//This code could probably be written better 

	for (int i = 0; i < V; i++)
	{
		printf("%7d", distance[i]);

	}

	printf("\n\n");

	printf("Path Array:\n");
	/*
		TO DO
	*/

	// Printing out the shortest paths and the path arrays are still missing. It might need more code than what we have right now. 

	
}

//Helper function that finds the vertex with the minimum distance from the vertices not yet included in the sptSet
int minDistance(int distance[], bool SPFound[])
{
	//Initializes our min value
	int minValue = INT_MAX;
	int minIndex = 0;

	for (int i = 0; i < V; i++)
	{
		//If the vertex at sptSet[i] is false and the value found at distance[i] is less than our minValue at hand,
		if (SPFound[i] == false && distance[i] <= minValue)
		{
			//Our min value is changed to the value found at that distance[i]
			minValue = distance[i];
			//We set our minIndex at that value to return out
			minIndex = i; 
		}
	}

	return minIndex;

}

//The method will ask for the graph and the vertex you want to start on.
void dijkstra(int graph[V][V], int sourceVertex)
{
	int distance[V]; // Output array that holds the shortest distance from our source to i
	bool SPFound[V]; // Will be set true at any point in the array if the vertex at i is included or finalized. 
	// Might be where we'd put Path[v]

	for (int i = 0; i < V; i++) //Fills the arrays for use. 
	{
		distance[i] = INT_MAX; //Sets every element in the Array to "infinity" as its default state
		SPFound[i] = false; //Same reason as the distance array above (set to false)
	}
		distance[sourceVertex] = 0; //Our starting vertex always starts at 0

		//Loop to find the shortest paths for all vertices
		for (int count = 0; count < V - 1; count++)
		{
			//Calls minDistance to calculate which vertex has the smallest distance from the vertices that haven't been looked at yet
			int u = minDistance(distance, SPFound);

			//To show that the vertex that came out of it was processed. 
			SPFound[u] = true;

			//Updates the distance value of the vertices next to the picked vertex. 
			for (int i = 0; i < V; i++)
			{
				//Some crazy condition from the code online i'm still trying to wrap my head around
				if (!SPFound[i] && graph[u][i] && distance[u] != INT_MAX && distance[u] + graph[u][i] < distance[i])
				{
					distance[i] = distance[u] + graph[u][i];
				}
			}
		}

		printSolution(distance, V);
}

int main()
{
	//Test Graphs Found online.
	//Link: https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
	int graph1[9][9] = 
	{
		{ 0, 4, 0, 0, 0, 0, 0, 8, 0 },
		{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
		{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
		{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
		{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
		{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
		{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
		{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
		{ 0, 0, 2, 0, 0, 0, 6, 7, 0 }
	};

	dijkstra(graph1, 0);

	printf("\n");

	//Link: https://brilliant.org/wiki/dijkstras-short-path-finder/
	// They only provided the graph so I just went ahead and made it into the matrix thing
	int graph2[V][V] =
	{
		{0,7,0,3,1,0,0,0,0},
		{7,0,1,0,2,2,0,0,0},
		{0,1,0,0,0,3,0,0,5},
		{3,0,0,0,7,0,5,0,0},
		{1,2,0,7,0,1,3,3,0},
		{0,2,3,0,1,0,0,3,2},
		{0,0,0,0,3,3,2,0,4},
		{0,0,5,0,0,2,0,4,0},

	};

	dijkstra(graph2, 3);

	// Test Cases for the Homework

	//I think he's referring to Page 96 and 98 in our Lesson 7 Slides for the test cases. 

}

