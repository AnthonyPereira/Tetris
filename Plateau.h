#pragma once
#include "Piece.h"
#include <stdio.h>
#include <algorithm>

class Plateau {
public:
	int nbLine;
	int nbCol;
	int **plateau;


	Plateau(int nbLine, int nbCol);
	void addPiece(Piece* newPiece);
	bool lineEmpty(int line);
	void DelLinePlateau();
	void clear();
	
};