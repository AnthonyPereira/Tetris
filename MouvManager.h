#pragma once

#include "Piece.h"
#include "integrityPlateau.h"
#include "Plateau.h"

class MouvManager {
	public:
		Piece* currentPiece; /* la piece qui se balade sur le plateau */
		Piece* nextPiece;	/* la piece qui sera sur le plateau ensuite */
		Plateau* plateau;
		int points;
		double speed;
		double delta;
		MouvManager(int mid, int line, int col);
		/* creer un mouvManager avec les parametres (mid) de la fabrication des pieces et (line, col) qui sont pour la fabrication d'un plateau */

		void resetGame(int mid, int line, int col);

		void goLeft();
		/* appelle la (currentPiece) pour lui dire d'aller sur gauche de 1*/
		void goRight();
		/* appelle la (currentPiece) pour lui dire d'aller sur droite de 1*/
		void goDown();
		/* appelle la (currentPiece) pour lui dire d'aller en bas de 1*/
		void turnLeft();
		/* appelle la (currentPiece) pour lui dire de tourner a gauche de 1*/
		bool verifLose();
		/* verifie si la partie est perdu ou pas */
		~MouvManager();
		/* détruit toute les objects initialisé en mémoire */


};
