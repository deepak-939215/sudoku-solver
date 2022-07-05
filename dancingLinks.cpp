#include "dancingLinks.h"

dancingLinks::dancingLinks(){
	isSolved=false;
	headNode=&Head;
}

void dancingLinks::coverCol(Node* col){
	col->l->r=col->r;
	col->r->l=col->l;   // hide the column

	for(Node* nv=col->d;nv!=col;nv=nv->d){		//Vertical Traversal
		for(Node* nh=nv->r;nh!=nv;nh=nh->r){
			nh->d->u=nh->u;
			nh->u->d=nh->d;

			nh->head->size--;
		}
	}
}

void dancingLinks::uncoverCol(Node* col){
	col->l->r=col;
	col->r->l=col;

	for(Node *nv=col->u;nv!=col;nv=nv->u){
		for(Node *nh=nv->l;nh!=nv;nh=nh->L){
			nh->d->u=nh;
			nh->u->d=nh;

			nh->head->size++;
		}
	}
}

bool dancingLinks::search(int sc,int **sudoku){
	
	if(headNode->r==headNode){
		return isSolved=true;
	}

	Node* col=headNode->r;
	for(Node* nh=col->r;nh!=headNode;nh=nh->r)
		if(nh->size<col->size)
			col=nh;

	coverCol(col);

	for(Node* nv=col->d;nv!=col;nv=nv->d){
		for(Node* nh=nv->r;nh!=nv;nh->r){
			coverCol(nh->head);
		}
		if(search(sc+1,sudoku)){
			sudoku[nv->rowEl[1]-1][nv->rowEl[2]-1]=nv->rowEl[0];
			return true;
		}
		for(Node* nh=nv->l;nh!=nv;nh->l){
			uncoverCol(nh->head);
		}
	}

	uncoverCol(col);

	return false;

}