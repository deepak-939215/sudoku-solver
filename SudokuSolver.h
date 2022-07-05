#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <limits>
#include <iomanip>
#include <string>
#include "dancingLinks.h"

class solver{
public:
	solver();
	int size;
	bool bmk;
	int n;
	double time;
	int **sudoku;
	dancingLinks dlx;

	void welcome();
	void instructions();
	void reset();
	void ask();
	int intIp();
	int intIpSudoku();
	bool checkSize(int);
	bool takeInput();
	bool validate();
	void solve();
	void buildMatrix();
	void buildCover();
	void transformationToCurrentGrid();
	void print();
}