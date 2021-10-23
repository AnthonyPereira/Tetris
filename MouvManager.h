#pragma once

#include "Piece.h"
#include "integrityPlateau.h"
#include "Plateau.h"

class MouvManager {
	public:
		Piece* currentPiece;
		Piece* nextPiece;
		Plateau* plateau;
		int points;

		MouvManager(int mid, int line, int col);

		void goLeft();
		void goRight();
		void goDown();
		void turnLeft();
		bool verifLose();

};
