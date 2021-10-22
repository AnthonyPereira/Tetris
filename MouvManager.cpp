#include "MouvManager.h"

using namespace std;

MouvManager::MouvManager(int mid, int line, int col){
	currentPiece = new Piece(mid);
	nextPiece = new Piece(mid);
	currentPiece->replacePiece(rand() % 6, 1);
	nextPiece->replacePiece(rand() % 6, rand() % 5);
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
}

void MouvManager::turnLeft(){
	if (!left(plateau, currentPiece)) {
		currentPiece->compoPiece[0][0]++;
		currentPiece->compoPiece[1][0]++;
		currentPiece->compoPiece[2][0]++;
		currentPiece->compoPiece[3][0]++;
	}
	else if (!right(plateau, currentPiece)) {
		printf("piece : \n %d %d %d %d \n", currentPiece->compoPiece[0][0], currentPiece->compoPiece[1][0], currentPiece->compoPiece[2][0], currentPiece->compoPiece[3][0]);
		currentPiece->compoPiece[0][0]--;
		currentPiece->compoPiece[1][0]--;
		currentPiece->compoPiece[2][0]--;
		currentPiece->compoPiece[3][0]--;
	}
	else if (!down(plateau, currentPiece)) {
		currentPiece->compoPiece[0][1]--;
		currentPiece->compoPiece[1][1]--;
		currentPiece->compoPiece[2][1]--;
		currentPiece->compoPiece[3][1]--;
	}
	currentPiece->turnLeft();
}

