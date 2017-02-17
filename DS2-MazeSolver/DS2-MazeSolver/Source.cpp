#include<iostream>
#include"maze.h"
#include "time.h"
using namespace std;

int main() {
	clock_t begin = clock(); // Timer start

	Maze maze("mazes/maze.txt"); // Initialize Maze, enter maze filename here, TODO: change from hard-code to prompt + method
	if (maze.initSolution()) // Attempt to solve maze
		maze.save();// Save output to "output.txt" file

	clock_t end = clock(); // Timer end
	cout << "It took " << double(end - begin) / CLOCKS_PER_SEC << " seconds to solve map " << endl; // Timer

	cin.get(); // Hang
	return 0;
}

// TODO: 
// Read mazes through cin rather than hard-coded in code.
// Better validation/output for impossible mazes.
// Create better output solutions (solution.txt keeps being overwritten |vs| solution_filename -> solution_maze1)
