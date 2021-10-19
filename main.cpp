#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "Piece.h"
#include "Plateau.h"
#include "integrityPlateau.h"

using namespace std;

void affichePiece(Piece* piece) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 2; ++j) {
			printf("%d ", piece->compoPiece[i][j]);
		}
		printf("\n");
	}
}

void affichePlateau(Plateau* plateau) {
	for (int i = 0; i < plateau->nbLine; ++i) {
		for (int j = 0; j < plateau->nbCol; ++j) {
			printf("%d ", plateau->plateau[i][j]);
		}
		printf("\n");
	}
}

int main(){
	Piece* piece = new Piece(4);
	piece->replacePiece(2, 1);
	affichePiece(piece);
	Plateau* plateau = new Plateau(20, 10);
	plateau->addPiece(piece);
	printf("\n");
	affichePlateau(plateau);
	for (int i = 0; i < 25; ++i) {
		plateau->clear();
		if (down(plateau, piece)) {
			piece->goDown();
			plateau->addPiece(piece);
			printf("\n");
			affichePlateau(plateau);
		}
		else {
			printf("impossible \n");
		}
		
	}
	
	
}
