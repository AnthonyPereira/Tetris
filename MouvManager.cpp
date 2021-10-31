#include "MouvManager.h"


using namespace std;


MouvManager::MouvManager(int mid, int line, int col, int mod){
	allPiece = { 1,2,3,4,5,6,7 };
	mt19937 g(rd());
	shuffle(allPiece.begin(), allPiece.end(), g);
	currentPiece = new Piece(mid);
	nextPiece = new Piece(mid);
	this->mod = mod;
	currentPiece->replacePiece(allPiece[0], allPiece[3]);
	nextPiece->replacePiece(allPiece[6], allPiece[2]);
	plateau = new Plateau(line, col);
	speed = 1.25;
	delta = 0.8;
	points = 0;
	
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

vector<int> MouvManager::goDown(){

	if (down(plateau, currentPiece)) {
		currentPiece->goDown();
	}
	else {
		plateau->addPiece(currentPiece);
		*currentPiece = *nextPiece;
		mt19937 g(rd());
		shuffle(allPiece.begin(), allPiece.end(), g);
		nextPiece->replacePiece(allPiece[0], allPiece[5]);
		if (delta > 0.3) {
			delta *= 0.94;
			speed = 1 / delta;

		}
	}
	vector<int> listLineDel = plateau->DelLinePlateau(mod);
	points += (listLineDel.size()*plateau->nbCol);
	return listLineDel;

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



