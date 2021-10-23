#include "MouvManager.h"

#define NBCOLOR 6
#define NBPIECE 5

using namespace std;


MouvManager::MouvManager(int mid, int line, int col){
	currentPiece = new Piece(mid);
	nextPiece = new Piece(mid);
	currentPiece->replacePiece((rand() % NBCOLOR)+1, 3);
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
		plateau->addPiece(currentPiece);
		*currentPiece = *nextPiece;
		nextPiece->replacePiece((rand() % NBCOLOR)+1, (rand() % NBPIECE)+1);
	}
	plateau->DelLinePlateau();

}

void MouvManager::turnLeft(){
	if (verifTurnLeft(plateau, currentPiece)) {
		currentPiece->turnLeft();
	}
}

