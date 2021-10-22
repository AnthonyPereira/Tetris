#include "Piece.h"

Piece::Piece(int mid) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 2; ++j) {
			compoPiece[i][j] = 0;
		}
	}
	this->mid = mid;
	piece = -1;
	color = 0;
	rota = 0;
}


void Piece::replacePiece(int color, int piece){
	this->piece = piece;
	this->color = color;
	this->rota = 0;
	compoPiece[0][0] = mid;
	compoPiece[0][1] = 1;
		if (piece == 1) {
			/*
				| |
			  | | | |
			     ^
			compoPiece[0]
			*/
			compoPiece[1][0] = mid - 1;
			compoPiece[1][1] = 1;
			compoPiece[2][0] = mid + 1;
			compoPiece[2][1] = 1;
			compoPiece[3][0] = mid;
			compoPiece[3][1] = 0;
		}
		
		else if (piece == 2) {
			/*
						| | |
		   compoPiece[0]->| | |
			*/
			compoPiece[1][0] = mid - 1;
			compoPiece[1][1] = 0;
			compoPiece[2][0] = mid + 1;
			compoPiece[2][1] = 1;
			compoPiece[3][0] = mid;
			compoPiece[3][1] = 0;
		}
		else if (piece == 3) {
			/*
							| |
			compoPiece[0]->	| |
							| |
							| |
			*/
			compoPiece[0][1] = 0;
			compoPiece[1][0] = mid+2;
			compoPiece[1][1] = 0;
			compoPiece[2][0] = mid+1;
			compoPiece[2][1] = 0;
			compoPiece[3][0] = mid-1;
			compoPiece[3][1] = 0;
		}
		else if (piece == 4) {
			/*
							| | |
			compoPiece[0]->	| | |
							
			*/
			compoPiece[1][0] = mid;
			compoPiece[1][1] = 0;
			compoPiece[2][0] = mid + 1;
			compoPiece[2][1] = 1;
			compoPiece[3][0] = mid + 1;
			compoPiece[3][1] = 0;
		}
		else if (piece == 5) {
			/*
								| |
							| | | |
							   ^
						compoPiece[0]

			*/
			compoPiece[1][0] = mid + 1;
			compoPiece[1][1] = 0;
			compoPiece[2][0] = mid + 1;
			compoPiece[2][1] = 1;
			compoPiece[3][0] = mid - 1;
			compoPiece[3][1] = 1;
		}
}

void Piece::turnLeft(){
	if (piece == 4) {
		return;
	}
	for (int i = 1; i < 4; ++i) {
		if (compoPiece[i][0] == compoPiece[0][0] + 1 && compoPiece[i][1] == compoPiece[0][1]) {
			compoPiece[i][0]--;
			compoPiece[i][1]--;
		}
		else if (compoPiece[i][0] == compoPiece[0][0] && compoPiece[i][1] == compoPiece[0][1] - 1) {
			compoPiece[i][0]--;
			compoPiece[i][1]++;
		}
		else if (compoPiece[i][0] == compoPiece[0][0] -1 && compoPiece[i][1] == compoPiece[0][1]) {
			compoPiece[i][0]++;
			compoPiece[i][1]++;
		}
		else if (compoPiece[i][0] == compoPiece[0][0] && compoPiece[i][1] == compoPiece[0][1] + 1) {
			compoPiece[i][0]++;
			compoPiece[i][1]--;
		}
	}
	if (piece == 2 || piece == 5) {
		if (compoPiece[1][0] == compoPiece[0][0] - 1) {
			if (compoPiece[1][1] == compoPiece[0][1] - 1) {
				compoPiece[1][1] += 2;
			}
			else {
				compoPiece[1][0] += 2;
			}
		}
		else {
			if (compoPiece[1][1] == compoPiece[0][1] - 1) {
				compoPiece[1][0] -= 2;
			}
			else{
				compoPiece[1][1] -= 2;
			}
		}
	}

	if (piece == 3) {
		if (compoPiece[1][0] == compoPiece[0][0]) {
			compoPiece[1][1] = compoPiece[0][1];
			if (compoPiece[1][1] == compoPiece[0][1] + 2) {
				compoPiece[1][0] += 2;
			}
			else{
				compoPiece[1][0] -= 2;
			}
		}
		else {
			compoPiece[1][0] = compoPiece[0][0];
			if (compoPiece[1][0] == compoPiece[0][0] + 2) {
				compoPiece[1][1] += 2;
			}
			else {
				compoPiece[1][1] -= 2;
			}
		}
	}

	
	
}

void Piece::goDown(){
	compoPiece[0][1]++;
	compoPiece[1][1]++;
	compoPiece[2][1]++;
	compoPiece[3][1]++;
}

void Piece::goLeft(){
	compoPiece[0][0]--;
	compoPiece[1][0]--;
	compoPiece[2][0]--;
	compoPiece[3][0]--;
}

void Piece::goRight(){
	compoPiece[0][0]++;
	compoPiece[1][0]++;
	compoPiece[2][0]++;
	compoPiece[3][0]++;
}


/*
void Piece::replacePiece(int* color, int* piece){
	for (int i = 0; i < 4; ++i) {
		compoPiece[i]
	}
}
*/