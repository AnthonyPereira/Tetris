#include "integrityPlateau.h"

bool left (Plateau* plateau, Piece* piece){
	bool ret = 0;
	for (int i = 0; i < 4; ++i) {
		ret = piece->compoPiece[i][0] + 1 >= 0 && plateau->plateau[piece->compoPiece[i][1]][piece->compoPiece[i][0]-1] == 0;
		if (!ret) {
			return ret;
		}
	}
	return ret;
}

bool right(Plateau* plateau, Piece* piece) {
	bool ret = 0;
	for (int i = 0; i < 4; ++i) {
		ret = piece->compoPiece[i][0] + 1 < plateau->nbCol && plateau->plateau[piece->compoPiece[i][1]][piece->compoPiece[i][0] + 1] == 0;
		if (!ret) {
			return ret;
		}
	}
	return ret;
}

bool down(Plateau* plateau, Piece* piece){
	bool ret = 0;
	for (int i = 0; i < 4; ++i) {
		ret = piece->compoPiece[i][1] < plateau->nbLine-1 && plateau->plateau[piece->compoPiece[i][1]+1][piece->compoPiece[i][0]] == 0 ;
		if (!ret) {
			return ret;
		}
	}
	return ret;
}

bool verifTurnLeft(Plateau* plateau, Piece* piece){
	if (piece->compoPiece[0][0] == 0) {
		if (right(plateau, piece)) {
			for (int i = 0; i < 4; ++i) {
				piece->compoPiece[i][0]++;
			}
			return true;
		}
		else {
			return false;
		}
	}
	if (piece->compoPiece[0][0] >= plateau->nbCol-1) {
		if (left(plateau, piece)) {
			for (int i = 0; i < 4; ++i) {
				piece->compoPiece[i][0]--;
			}
			return true;
		}
		else {
			return false;
		}
	}
	if (piece->compoPiece[0][1] >= plateau->nbLine-1) {
		for (int i = 0; i < 4; ++i) {
			piece->compoPiece[i][1]--;
		}
		return true;
	}
	return true;
}

