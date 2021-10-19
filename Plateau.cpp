#include "Plateau.h"

Plateau::Plateau(int nbLine, int nbCol){
	this->nbLine = nbLine;
	this->nbCol = nbCol;
	plateau = new int*[nbLine];
	for (int i = 0; i < nbLine; ++i) {
		plateau[i] = new int[nbCol];
		for (int w = 0; w < nbCol; ++w) {
			plateau[i][w] = 0;
		}
	}
}

void Plateau::addPiece(Piece* newPiece){
	plateau[newPiece->compoPiece[0][1]][newPiece->compoPiece[0][0]] = newPiece->color;
	plateau[newPiece->compoPiece[1][1]][newPiece->compoPiece[1][0]] = newPiece->color;
	plateau[newPiece->compoPiece[2][1]][newPiece->compoPiece[2][0]] = newPiece->color;
	plateau[newPiece->compoPiece[3][1]][newPiece->compoPiece[3][0]] = newPiece->color;
}

void Plateau::DelLinePlateau(){
	int typeColor = 0;
	
	for (int i = 0; i < nbLine; ++i) {
		bool same = 0;
		typeColor = plateau[i][0];
		for (int j = 0; j < nbCol; ++j) {
			if (plateau[i][j] == 0) {
				break;
			}
			same = typeColor == plateau[i][j];
			if (!same) {
				break;
			}
		}
		if (same) {
			for (int j = 0; j < nbCol; ++j) {
				plateau[i][j] = 0;
			}
		}
	}
}

void Plateau::clear() {
	for (int i = 0; i < nbLine; ++i) {
		for (int j = 0; j < nbCol; ++j) {
			plateau[i][j] = 0;
		}
	}
}

