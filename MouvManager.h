#pragma once

#include "Piece.h"
#include "integrityPlateau.h"
#include "Plateau.h"

class MouvManager {
	public:
		Piece* currentPiece;
		Piece* nextPiece;
		Plateau* plateau;

		MouvManager(int mid, int line, int col);

		void Init();

		void goLeft();
		void goRight();
		void goDown();
};
