//Final Project: Tetris
//Author: Trevor Kerr
//A minimal tetris clone
#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Piece.h"

using namespace sf;
using namespace std;

class Control {
public:
	static void MovePiece(Piece& movePiece);
	static void MovePieceLeft(Piece& movePiece);
	static void MovePieceRight(Piece& movePiece);
};