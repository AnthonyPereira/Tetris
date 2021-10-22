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

