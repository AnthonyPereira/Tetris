#pragma once

#include <vector>

class Piece {

public:
	int mid;
	int compoPiece[4][2];
	int piece;
	int color;

	Piece(int mid);
	void replacePiece (int color,int piece);
	void turnLeft();
	/*void turnRight(); */
	void goDown();
	void goLeft();
	void goRight();
	Piece& operator =(const Piece& p2);
};
