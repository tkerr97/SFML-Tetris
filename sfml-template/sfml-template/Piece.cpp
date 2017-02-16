//Final Project: Tetris
//Author: Trevor Kerr
//A minimal tetris clone
#include "Piece.h"

Piece::Piece() //default constructor
{
}

Piece::Piece(int rand) //one parameter constructor
{
	thisPiece.resize(5, vector<int>(5, 0));
	SetPieceType(rand);
}

Color Piece::getColor() const //returns the color of the piece
{
	return pieceColor;
}

vector<vector<int>>Piece::getPiece() //returns the piece
{
	return thisPiece;
}

int Piece::getX() const //getter for x
{
	return x;
}

int Piece::getY() const //getter for y
{
	return y;
}

vector<vector<int>> Piece::getRotation(int type, int rotation) const //getter for a rotation of the current piece
{
	vector<vector<int>>thisRotation;
	thisRotation.resize(5, vector<int>(5, 0));
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			thisRotation[i][j] = piecesArray[type][rotation][i][j];
		}
	}
	return thisRotation;
}

void Piece::setXY(int x, int y)  //setter for x and y
{
	this->x = x;
	this->y = y;
}

void Piece::RotatePiece(int type, int rotations) //rotates the piece
{
	for (int i = 0; i < 5;i++) {
		for (int j = 0; j < 5;j++) {
			thisPiece[i][j] = piecesArray[type][rotations][i][j];
		}
	}
}


void Piece::SetPieceType(int rand) //creates the array for the piece
{
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				thisPiece[i][j] = piecesArray[rand][0][i][j];
			}
		}
		switch (rand) {
		case 0:
			pieceColor = Color(255, 255, 0,255);
			break;
		case 1:
			pieceColor = Color(0, 255, 255, 255);
			break;
		case 2:
			pieceColor = Color(255, 165, 0, 255);
			break;
		case 3:
			pieceColor = Color(0, 0, 255, 255);
			break;
		case 4:
			pieceColor = Color(255, 0, 0, 255);
			break;
		case 5:
			pieceColor = Color(0, 255, 0, 255);
			break;
		case 6:
			pieceColor = Color(148, 0, 211, 255);
			break;

		}
		x = 3;
		y = 0;
}


