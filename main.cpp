#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "Piece.h"
#include "Plateau.h"
#include "integrityPlateau.h"

using namespace std;

void affichePiece(Piece* piece) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 3; ++j) {
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
	Piece* piece = new Piece(1);
	piece->replacePiece(2, 3);
	affichePiece(piece);
	Plateau* plateau = new Plateau(5, 5);
	plateau->addPiece(piece);
	printf("\n");
	affichePlateau(plateau);
	for (int i = 0; i < 5; ++i) {
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
