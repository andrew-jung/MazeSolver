#pragma once
#include<iostream>
#include<fstream>
#include"stack.h"
using namespace std;

// Maze header file

class Maze {
	int row, col, x, y; 
	string* grid;
	Stack s;
	Maze() {}; // Constructor

public: 
	Maze(string); // takes in maze.txt

	bool initSolution();
	bool solveMaze(int i, int j);
	void save(); // save to file
	void load(string); // load file
};


