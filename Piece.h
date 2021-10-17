#pragma once

#include <vector>

class Piece {

public:
	int mid;
	int compoPiece[4][3];
	int piece;

	Piece(int mid);
	void replacePiece (int color,int piece);
	/*void turnLeft();
	void turnRight();
	void goDown();
	void goLeft();
	void goRight();*/
};
