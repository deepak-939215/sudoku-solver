#include "sudokuSolver.h"

using namespace std;

solver::solver(){
	bmk=false;
}

void solver::ask(){
	char a;
	cout<<"Are you Benchmarking??(Y?N): ";
	reask:
	cin>>a;
	if(a=='Y'){
		cout<<"How many Sudoku??";
		n=intIP();
		bmk=true;
		time=0.0;
	}else if(a=='N'){
		n=1;
	}else
}