#include "Maze.h"

// Implement Maze/methods -- maze load save initSol solveMaze
Maze::Maze(string s) { // Construct
	row = col = 0;
	x = y = 0;
	load(s);
}

bool Maze::initSolution() { // Initializing solution; at the end of the program, stack will have all coordinates of the possible path to the end.
	int i = 1, j = 0; // Starting position (1,0)
	bool flag = flag = solveMaze(i, j);// Flag(T/F) to know if any possible path exist or not

	cout << "\n\nSolution:\n";// Printing solution
	if (!flag) { cout << "Unsolveable.\n";} // If flag doesn't reach the end-path, could put this before and have a if/else block or in solveMaze

	for (int i = 0; i < row; i++) { // Solution path
		cout << grid[i].data() << endl;
	}
	return flag;
}

void Maze::load(string txtMaze) { // Load maze through filename
	string line;
	ifstream myfile(txtMaze); // ifstream: read from file
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			row++;
		}
		myfile.close();
		col = line.length();
	}
	else {
		cout << "Unable to open file"; 
		return;
	}
	grid = new string[row]; // Maze 
	int i = 0;
	ifstream myfile1(txtMaze);
	if (myfile1.is_open())
	{
		while (getline(myfile1, line))
		{
			string* temp = new string;
			*temp = line;
			grid[i++] = *temp;
		}
		myfile1.close();
	}
	cout << "Maze:\n";
	for (int i = 0; i < row; i++)
	{
		cout << grid[i].data() << endl;
	}

}
void Maze::save() { // Save to output file
	ofstream out("solution.txt"); // ofstream: write on file
	for (int i = 0; i < row - 1; i++)
		out << grid[i] << endl;
	out << grid[row - 1];
	out.close();
}
bool Maze::solveMaze(int i, int j) { // Traversing all possible paths
	grid[i][j] = '#'; // Marking visited location
	if (i == (row - 2) && j == (col - 1))
		return true;
	s.push(i, j); // Pushing cordinates in stack


	bool flag1 = false, flag2 = false, flag3 = false, flag4 = false, check = false; // This was an awful idea.
	
	if (i > 0) { // For moving up
		if (grid[i - 1][j] == ' ') { // Check blank space
			flag1 = solveMaze(i - 1, j);
			if (!flag1) { // If it is wrong path, clear mark i.e. => ' ' and pop from stack all wrong co-ordinates
				grid[i - 1][j] = ' ';
				s.pop();
			}
			check = true;
		}
	}

	if (j > 0) { // For moving left
		if (grid[i][j - 1] == ' ') { // Check blank space
 			flag2 = solveMaze(i, j - 1);
			if (!flag2) { // If it is wrong path, clear mark i.e. => ' ' and pop from stack all wrong co-ordinates  
				grid[i][j - 1] = ' ';
				s.pop();
			}
			check = true;
		}
	}
	if (i < (row - 1)) { //For moving down
		if (grid[i + 1][j] == ' ') { // Check blank space
			flag3 = solveMaze(i + 1, j);
			if (!flag3) {// If it is wrong path, clear mark i.e. => ' ' and pop from stack all wrong co-ordinates  
				grid[i + 1][j] = ' ';
				s.pop();
			}
			check = true;
		}
	}
	if (j < (col - 1)) { // For moving right
		if (grid[i][j + 1] == ' ') { // Check blank space
			flag4 = solveMaze(i, j + 1);
			if (!flag4) { // If it is wrong path, clear mark i.e. => ' ' and pop from stack all wrong co-ordinates   
				grid[i][j + 1] = ' ';
				s.pop();
			}
			check = true;
		}
	}
	if (!check) { // If cannot moving in to any new location i.e. dead end, return false
		return false;
	}

	return flag1 || flag2 || flag3 || flag4; // If any of the paths can reach to the destination it will return true, else return false
}

