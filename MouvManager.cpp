#include "MouvManager.h"
#include "integrityPlateau.h"
#include <time.h>
#include <iostream>
#define NBPIECE 7

using namespace std;


MouvManager::MouvManager(int mid, int line, int col){
	srand(time(0));
	currentPiece = new Piece(mid);
	nextPiece = new Piece(mid);
	
	currentPiece->replacePiece((rand() % NBPIECE)+1, (rand() % NBPIECE) + 1);
	nextPiece->replacePiece((rand() % NBPIECE) + 1, (rand() % NBPIECE)+1);
	plateau = new Plateau(line, col);
	speed = 1.25;
	delta = 0.8;
	points = 0;
}


void MouvManager::resetGame(int mid, int line, int col) {
	speed = 1.25;
	delta = 0.8;
	points = 0;
	plateau->clear();
}

void MouvManager::goLeft(){
	if (left(plateau, currentPiece)) {
		currentPiece->goLeft();
	}
}

void MouvManager::goRight(){
	if (right(plateau, currentPiece)) {
		currentPiece->goRight();
	}
}

void MouvManager::goDown(){

	if (down(plateau, currentPiece)) {
		currentPiece->goDown();
	}
	else {
		srand(time(0));
		plateau->addPiece(currentPiece);
		*currentPiece = *nextPiece;
		nextPiece->replacePiece((rand() % NBPIECE)+1, (rand() % NBPIECE)+1);
		if (delta > 0.3) {
			delta *= 0.94;
			speed = 1 / delta;
		}
	}
	points += (plateau->DelLinePlateau()*plateau->nbCol);

}

void MouvManager::turnLeft(){
	int tmp[4][2];
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 2; ++j) {
			tmp[i][j] = currentPiece->compoPiece[i][j];
		}
	}
	if (verifTurnLeft(plateau, currentPiece)) {
		currentPiece->turnLeft();
		if (!verifIntegrity(plateau, currentPiece)) {
			for (int i = 0; i < 4; ++i) {
				for (int j = 0; j < 2; ++j) {
					currentPiece->compoPiece[i][j] = tmp[i][j];
				}
			}
		}
	}
}

bool MouvManager::verifLose(){
	return !verifIntegrity(plateau, currentPiece);
}

MouvManager::~MouvManager(){
	delete currentPiece;
	delete nextPiece;
	delete plateau;
	
}



