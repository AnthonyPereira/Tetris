#include "MouvManager.h"
#include <time.h>
#include <iostream>
#define NBCOLOR 6
#define NBPIECE 7

using namespace std;


MouvManager::MouvManager(int mid, int line, int col){
	srand(time(0));
	currentPiece = new Piece(mid);
	nextPiece = new Piece(mid);
	currentPiece->replacePiece((rand() % NBCOLOR)+1, (rand() % NBPIECE) + 1);
	nextPiece->replacePiece((rand() % NBCOLOR) + 1, (rand() % NBPIECE)+1);
	plateau = new Plateau(line, col);
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
		nextPiece->replacePiece((rand() % NBCOLOR)+1, (rand() % NBPIECE)+1);
		cout << currentPiece->piece << endl;
	}
	plateau->DelLinePlateau();

}

void MouvManager::turnLeft(){
	if (verifTurnLeft(plateau, currentPiece)) {
		currentPiece->turnLeft();
	}
}

