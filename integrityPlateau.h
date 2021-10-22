#pragma once

#include "Plateau.h"
#include "Piece.h"

bool left (Plateau* plateau, Piece* piece);
bool right (Plateau* plateau, Piece* piece);
bool down(Plateau* plateau, Piece* piece);
bool verifTurnLeft(Plateau* plateau, Piece* piece);