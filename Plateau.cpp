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

bool Plateau::lineEmpty(int line){
	for (int i = 0; i < nbCol; ++i) {
		if (plateau[line][i] != 0) {
			return false;
		}
	}
	return true;
}

int Plateau::DelLinePlateau(){
	int typeColor = 0;
	int nbLinedestroy = 0;
	for (int i = 0; i < nbLine; ++i) {
		bool same = 0;
		typeColor = plateau[i][0];
		for (int j = 0; j < nbCol; ++j) {
			if (plateau[i][j] == 0) {
				same = 0;
				break;
				
			}
			same = 1;
		}
		if (same) {
			for (int j = 0; j < nbCol; ++j) {
				plateau[i][j] = 0;
			}
			nbLinedestroy++;
		}
	}
	downPlateau();
	return nbLinedestroy;
}

void Plateau::downPlateau(){
	bool precEmpty = lineEmpty(nbLine - 1);
	bool currentEmpty;
	for (int i = nbLine - 2; i >= 0; --i) {
		currentEmpty = lineEmpty(i);
		if (precEmpty && !currentEmpty) {
			std::swap(plateau[i + 1], plateau[i]);
		}
		else {
			precEmpty = currentEmpty;
		}
	}
}

bool Plateau::verifLose(){
	for (int i = 0; i < nbCol; ++i) {
		if (plateau[0][i]) {
			return true;
		}
	}
	return false;
}

void Plateau::clear() {
	for (int i = 0; i < nbLine; ++i) {
		for (int j = 0; j < nbCol; ++j) {
			plateau[i][j] = 0;
		}
	}
}

Plateau::~Plateau(){
	for (int i = 0; i < nbLine; ++i) {
		delete[] plateau[i];
	}
	delete[] plateau;
}

