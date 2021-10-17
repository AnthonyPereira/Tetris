#include "Piece.h"

Piece::Piece(int mid) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 3; ++j) {
			compoPiece[i][j] = 0;
		}
	}
	this->mid = mid;
	piece = 1;
}


void Piece::replacePiece(int color, int piece){
	this->piece = piece;
	compoPiece[0][0] = mid;
	compoPiece[0][1] = 1;
	compoPiece[0][2] = color;
		if (piece == 1) {
			/*
				| |
			  | | | |
			     ^
			compoPiece[0]
			*/
			compoPiece[1][0] = mid - 1;
			compoPiece[1][1] = 1;
			compoPiece[1][2] = color;
			compoPiece[2][0] = mid + 1;
			compoPiece[2][1] = 1;
			compoPiece[2][2] = color;
			compoPiece[3][0] = mid;
			compoPiece[3][1] = 1;
			compoPiece[3][2] = color;
		}
		
		else if (piece == 2) {
			/*
						| | |
		   compoPiece[0]->| | |
			*/
			compoPiece[1][0] = mid - 1;
			compoPiece[1][1] = 0;
			compoPiece[1][2] = color;
			compoPiece[2][0] = mid + 1;
			compoPiece[2][1] = 1;
			compoPiece[2][2] = color;
			compoPiece[3][0] = mid;
			compoPiece[3][1] = 0;
			compoPiece[3][2] = color;
		}
		else if (piece == 3) {
			/*
							| |
			compoPiece[0]->	| |
							| |
							| |
			*/
			compoPiece[1][0] = mid;
			compoPiece[1][1] = 0;
			compoPiece[1][2] = color;
			compoPiece[2][0] = mid;
			compoPiece[2][1] = 2;
			compoPiece[2][2] = color;
			compoPiece[3][0] = mid;
			compoPiece[3][1] = 3;
			compoPiece[3][2] = color;
		}
		else if (piece == 4) {
			/*
							| | |
			compoPiece[0]->	| | |
							
			*/
			compoPiece[1][0] = mid;
			compoPiece[1][1] = 0;
			compoPiece[1][2] = color;
			compoPiece[2][0] = mid + 1;
			compoPiece[2][1] = 1;
			compoPiece[2][2] = color;
			compoPiece[3][0] = mid + 1;
			compoPiece[3][1] = 0;
			compoPiece[3][2] = color;
		}
		else if (piece == 5) {
			/*
								| |
							| | | |
							   ^
						compoPiece[0]

			*/
			compoPiece[1][0] = mid - 1;
			compoPiece[1][1] = 1;
			compoPiece[1][2] = color;
			compoPiece[2][0] = mid + 1;
			compoPiece[2][1] = 1;
			compoPiece[2][2] = color;
			compoPiece[3][0] = mid+1;
			compoPiece[3][1] = 0;
			compoPiece[3][2] = color;
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