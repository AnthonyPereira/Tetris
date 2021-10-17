#pragma once
#include "Piece.h"
#include <stdio.h>


class Plateau {
public:
	int nbLine;
	int nbCol;
	int **plateau;


	Plateau(int nbLine, int nbCol);
	void addPiece(Piece* newPiece);
	void DelLinePlateau();
	void clear();
	
};