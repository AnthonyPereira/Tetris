#include "MouvManager.h"

using namespace std;


MouvManager::MouvManager(int mid, int line, int col, int mod){
	allPiece = { 1,2,3,4,5,6,7 };
	mt19937 g(rd());
	shuffle(allPiece.begin(), allPiece.end(), g);
	currentPiece = new Piece(mid);
	nextPiece = new Piece(mid);
	this->mod = mod;
	precPiece.push_back(allPiece[3]);
	precPiece.push_back(allPiece[2]);
	precColor.push_back(allPiece[0]);
	precColor.push_back(allPiece[6]);
	currentPiece->replacePiece(allPiece[0], allPiece[3]);
	nextPiece->replacePiece(allPiece[6], allPiece[2]);
	plateau = new Plateau(line, col);
	speed = 1.25;
	delta = 0.8;
	points = 0;
	level = 0;
	
}


void MouvManager::resetGame(int mid, int line, int col) {
	speed = 1.25;
	delta = 0.8;
	points = 0;
	plateau->clear();
	level = 0;

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
		if (precPiece.size() == 3) {
			precPiece.erase(precPiece.begin());
			precColor.erase(precColor.begin());
		}
		int i = 0;
		int j = 0;
		while (find(precPiece.begin(), precPiece.end(), allPiece[i]) != precPiece.end()) {
			++i;
		}
		precPiece.push_back(allPiece[i]);
		while (find(precColor.begin(), precColor.end(), allPiece[j]) != precColor.end()) {
			++j;
		}
		precColor.push_back(allPiece[j]);
		nextPiece->replacePiece(allPiece[j], allPiece[i]);
		
	}
	vector<int> listLineDel = plateau->DelLinePlateau(mod);
	if (listLineDel.size() == 1) {
		points += (40 * (level+1));
	}
	else if (listLineDel.size() == 2) {
		points += (100 * (level+1));
	}
	else if (listLineDel.size() == 3) {
		points += (300 * (level+1));
	}
	else if (listLineDel.size() == 4) {
		points += (1200 * (level+1));
	}
	else if (listLineDel.size() == 20) {
		points += (3000 * (level+1));
	}
	if (points >= 1200 * (level+1)) {
		++level;
		if (delta > 0.3) {
			delta *= 0.93;
			speed = 1 / delta;
		}
	}
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



