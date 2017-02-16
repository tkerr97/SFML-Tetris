//Final Project: Tetris
//Author: Trevor Kerr
//A minimal tetris clone
#pragma once
#include <SFML\Graphics.hpp>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;
using namespace sf;

class Piece {
public:
	Piece();
	Piece(int rand);
	Color getColor() const;
	vector<vector<int>> getPiece();
	int getX() const;
	int getY() const;
	vector<vector<int>> getRotation(int type, int rotation) const;
	void setXY(int x, int y);
	void RotatePiece(int type, int rotations);

private:
	vector<vector<int>> thisPiece;
	Color pieceColor;
	int x;
	int y;
	int piecesArray[7][4][5][5] =
	
		{
			// Square
			{
				{
					{ 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0 },
					{ 0, 0, 1, 1, 0 },
					{ 0, 0, 1, 1, 0 },
					{ 0, 0, 0, 0, 0 }
				},
				{
					{ 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0 },
					{ 0, 0, 1, 1, 0 },
					{ 0, 0, 1, 1, 0 },
					{ 0, 0, 0, 0, 0 }
				},
				{
					{ 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0 },
					{ 0, 0, 1, 1, 0 },
					{ 0, 0, 1, 1, 0 },
					{ 0, 0, 0, 0, 0 }
				},
				{
					{ 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0 },
					{ 0, 0, 1, 1, 0 },
					{ 0, 0, 1, 1, 0 },
					{ 0, 0, 0, 0, 0 }
				}
			},

		// I
			{
				{
					{ 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0 },
					{ 0, 1, 1, 1, 1 },
					{ 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0 }
				},
				{
					{ 0, 0, 0, 0, 0 },
					{ 0, 0, 1, 0, 0 },
					{ 0, 0, 1, 0, 0 },
					{ 0, 0, 1, 0, 0 },
					{ 0, 0, 1, 0, 0 }
				},
				{
					{ 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0 },
					{ 1, 1, 1, 1, 0 },
					{ 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0 }
				},
				{
					{ 0, 0, 1, 0, 0 },
					{ 0, 0, 1, 0, 0 },
					{ 0, 0, 1, 0, 0 },
					{ 0, 0, 1, 0, 0 },
					{ 0, 0, 0, 0, 0 }
				}
			}
		,
		// L
		{
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 1, 0, 0 },
				{ 0, 0, 1, 0, 0 },
				{ 0, 0, 1, 1, 0 },
				{ 0, 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 1, 1, 1, 0 },
				{ 0, 1, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 1, 1, 0, 0 },
				{ 0, 0, 1, 0, 0 },
				{ 0, 0, 1, 0, 0 },
				{ 0, 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 1, 0 },
				{ 0, 1, 1, 1, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 }
			}
		},
		// L mirrored
		{
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 1, 0, 0 },
				{ 0, 0, 1, 0, 0 },
				{ 0, 1, 1, 0, 0 },
				{ 0, 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 1, 0, 0, 0 },
				{ 0, 1, 1, 1, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 1, 1, 0 },
				{ 0, 0, 1, 0, 0 },
				{ 0, 0, 1, 0, 0 },
				{ 0, 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 1, 1, 1, 0 },
				{ 0, 0, 0, 1, 0 },
				{ 0, 0, 0, 0, 0 }
			}
		},
		// N
		{
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 1, 0 },
				{ 0, 0, 1, 1, 0 },
				{ 0, 0, 1, 0, 0 },
				{ 0, 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 1, 1, 0, 0 },
				{ 0, 0, 1, 1, 0 },
				{ 0, 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 1, 0, 0 },
				{ 0, 1, 1, 0, 0 },
				{ 0, 1, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 1, 1, 0, 0 },
				{ 0, 0, 1, 1, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 }
			}
		},
		// N mirrored
		{
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 1, 0, 0 },
				{ 0, 0, 1, 1, 0 },
				{ 0, 0, 0, 1, 0 },
				{ 0, 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 1, 1, 0 },
				{ 0, 1, 1, 0, 0 },
				{ 0, 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 1, 0, 0, 0 },
				{ 0, 1, 1, 0, 0 },
				{ 0, 0, 1, 0, 0 },
				{ 0, 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 1, 1, 0 },
				{ 0, 1, 1, 0, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 }
			}
		},
		// T
		{
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 1, 0, 0 },
				{ 0, 0, 1, 1, 0 },
				{ 0, 0, 1, 0, 0 },
				{ 0, 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 1, 1, 1, 0 },
				{ 0, 0, 1, 0, 0 },
				{ 0, 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 1, 0, 0 },
				{ 0, 1, 1, 0, 0 },
				{ 0, 0, 1, 0, 0 },
				{ 0, 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 1, 0, 0 },
				{ 0, 1, 1, 1, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 }
			}
		}
		};
	void SetPieceType(int rand);
};