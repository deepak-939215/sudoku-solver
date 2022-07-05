#include "Node.h"

class DancingLinks{
public:
	DancingLinks();
	Node head;
	Node* headNode;
	bool isSolved;
	bool **cover;
	
	void coverCol(Node*);
	void uncoverCol(Node *);
	bool search(int,int**);
}