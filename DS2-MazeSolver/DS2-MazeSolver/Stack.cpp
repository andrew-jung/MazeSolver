#include "Stack.h"

// Implement Stack/methods -- pop push top destruct


void Stack::push(int row, int col) { // Push
	struct Node *ptr; 
	ptr = new Node;
	ptr->row = row; // dereference pointers
	ptr->col = col;
	ptr->next = NULL;

	if (Top != NULL) { // top of stack exists
		ptr->next = Top; // set new top on top of stack
	}
	Top = ptr; // re-assign
}

void Stack::pop() {
	struct Node *temp;
	if (Top == NULL) { // No top
		return;
	}
	temp = Top;
	Top = Top->next;
	delete temp; // deallocate memory block (if not null which it won't be because of the conditional)
}

Node* Stack::top() { // Getter for top
	if (Top == NULL) {
		return nullptr;
	}
	return Top;
}

Stack::~Stack() { // Destructor
	struct Node *temp;
	if (Top == NULL) {
		return;
	}
	while (Top != NULL) { // loop pop off stack
		temp = Top;
		Top = Top->next;
		delete temp;
	}
}