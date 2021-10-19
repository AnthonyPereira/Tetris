#include "MouvManager.h"

using namespace std;

MouvManager::MouvManager(int mid, int line, int col){
	currentPiece = new Piece(mid);
	nextPiece = new Piece(mid);
	plateau = new Plateau(line, col);
}

void MouvManager::Init(){
	currentPiece->replacePiece(rand() % 6, rand() % 5);
	nextPiece->replacePiece(rand() % 6, rand() % 5);
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
