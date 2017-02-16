//Final Project: Tetris
//Author: Trevor Kerr
//A minimal tetris clone
#include "Control.h"
#include "Piece.h"

void Control::MovePiece(Piece& movePiece) {
	movePiece.setXY(movePiece.getX(), movePiece.getY()+1);
	
}

void Control::MovePieceLeft(Piece & movePiece)
{
	movePiece.setXY(movePiece.getX() - 1, movePiece.getY());
}

void Control::MovePieceRight(Piece & movePiece)
{
	movePiece.setXY(movePiece.getX() + 1, movePiece.getY());
}
