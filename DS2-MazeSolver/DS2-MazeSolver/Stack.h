#pragma once
#include <cstdlib>
#include <istream>
#include <string>
// Stack header file -- LIFO

struct Node {
	int row, col;
	struct Node *next;
};

class Stack {
	struct Node *Top; // Top of stack
public:
	Stack(){ Top = NULL; } // Constructor

	void push(int row, int col); // Push from stack
	Node* top();
	void pop(); // Pop from stack
	~Stack(); // Destructor
};