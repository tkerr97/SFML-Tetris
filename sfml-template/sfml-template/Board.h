//Final Project: Tetris
//Author: Trevor Kerr
//A minimal tetris clone
#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Piece.h"
#include "Control.h"

using namespace sf;
using namespace std;

class Board {
public:
	Board();
	void UpdateBoard();
	void DrawPiece(RenderWindow &window);
	void GetNextPiece();
	int board[10][25] = { 0 };
	int linesCleared;
	Color boardColor[12][25];
	void CheckCollisionDown();
	void CheckCollisionLeft();
	void CheckCollisionRight();
	void CheckCollisionRotate();
	void DeleteLines();
	bool GameOver(RenderWindow &window);
	

private:
	
	int pieceType;
	int rotations;
	void MoveDown(int y);
	Piece piecesToDraw;
	//void GetNextPiece();
};