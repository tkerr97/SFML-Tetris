//Final Project: Tetris
//Author: Trevor Kerr
//A minimal tetris clone
#include "Board.h"

Board::Board() //default constructor
{
	linesCleared = 0;
}

void Board::UpdateBoard() { //fill the board where it is occupied
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (piecesToDraw.getPiece()[i][j] == 1) {
				board[i + piecesToDraw.getX()][j+piecesToDraw.getY()] = 1;
				boardColor[i + piecesToDraw.getX()][j + piecesToDraw.getY()] = piecesToDraw.getColor();
			}
			
				
		}
	}
}



void Board::DrawPiece(RenderWindow &window) //draw the picece that is still moving
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (piecesToDraw.getPiece()[i][j] == 1) {
				RectangleShape newTetro;
				newTetro.setSize(Vector2f(30, 30));
				newTetro.setFillColor(piecesToDraw.getColor());
				newTetro.setPosition(Vector2f((piecesToDraw.getX()*30) + (i* 30)+170, (piecesToDraw.getY() * 30) + j * 30));
				window.draw(newTetro);
			}

		}
	}
}

void Board::CheckCollisionDown() //check to see if the piece can move down
{
	bool move = true;
	for (int j = 0; j < 5; j++) {
		for (int k = 0; k < 5; k++) {
			if (k+piecesToDraw.getY() > 20) {
				if (piecesToDraw.getPiece()[j][k] != 0 )
				{
						 if (Keyboard::isKeyPressed(Keyboard::Left)) {
								CheckCollisionLeft();
								CheckCollisionDown();
							}
							else if (Keyboard::isKeyPressed(Keyboard::Right)) {
								CheckCollisionRight();
								CheckCollisionDown();

							}
						
					
					
					move = false;
					UpdateBoard();
					DeleteLines();
					GetNextPiece();
					break;
				}
			}
			else if (board[piecesToDraw.getX() + j][piecesToDraw.getY() + k +1] == 1 && piecesToDraw.getPiece()[j][k] == 1) {
				if (Keyboard::isKeyPressed(Keyboard::Left)) {
					CheckCollisionLeft();
					//CheckCollisionDown();

				}
				else if (Keyboard::isKeyPressed(Keyboard::Right)) {
					CheckCollisionRight();
				//	CheckCollisionDown();
				}
				move = false;
				UpdateBoard();
				DeleteLines();
				GetNextPiece();
				break;
			}
		}
	}

	if (move == true) {
		Control::MovePiece(piecesToDraw);
	}
}

void Board::CheckCollisionLeft() //check to see if the piece can move left
{
	bool move = true;
	for (int j = 0; j < 5; j++) {
		for (int k = 0; k < 5; k++) {
			if (piecesToDraw.getPiece()[j][k] == 1) {
				if (piecesToDraw.getX() + 1 + j == 1 && piecesToDraw.getPiece()[j][k] == 1) {
					move = false;
					break;
				}
				else if (board[piecesToDraw.getX() + j - 1][piecesToDraw.getY() + k] == 1) {
					move = false;
					break;
				}
			}
		}
	}

	if (move == true) {
		Control::MovePieceLeft(piecesToDraw);
	}
	

}

void Board::CheckCollisionRight() //check to see if the piece can move right
{
	bool move = true;
	for (int j = 0; j < 5; j++) {
		for (int k = 0; k < 5; k++) {
			if (piecesToDraw.getX() + 1 + j == 10 && piecesToDraw.getPiece()[j][k] == 1) {
				move = false;
			}
			else if (board[piecesToDraw.getX() + j + 1][piecesToDraw.getY() + k] == 1 && piecesToDraw.getPiece()[j][k] == 1){
				move = false;
			}

		}
	}

	if (move == true) {
		Control::MovePieceRight(piecesToDraw);
	}
	
}

void Board::CheckCollisionRotate() //check to see if the piece can rotate
{
	bool rotate = true;
	int tempRotate;
		if (rotations > 2) {
			tempRotate = rotations;
			rotations = 0;
		}
		else {
			tempRotate = rotations;
			rotations += 1;
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (piecesToDraw.getRotation(pieceType, rotations)[j][i] == 1) {
					if (piecesToDraw.getX() + 1 + j == 11) {
						CheckCollisionLeft();
					}
					else if (board[piecesToDraw.getX() + j + 1][piecesToDraw.getY() + j] == 1) {
						rotate = false;
					}
					else if (piecesToDraw.getX() + 1 + j == 0) {
						CheckCollisionRight();
					}
					else if (board[piecesToDraw.getX() + j - 1][piecesToDraw.getY() + i] == 1) {
						rotate = false;
						break;
					}
				}
			}
		}
		if (rotate) {
			piecesToDraw.RotatePiece(pieceType, rotations);
		}
		else
			rotations = tempRotate;
}

void Board::DeleteLines() //check to see if lines can be deleted
{
	for (int i = 0; i < 22; i++) {
		bool line = true;
		for (int j = 0; j < 10; j++) {
			if (board[j][i] != 1) {
				line = false;
				break;
				break;
			}
			
		}
		if (line) {
			linesCleared++;
			MoveDown(i);
			}
			
		
	}
}

bool Board::GameOver(RenderWindow &window) //check to see if the game is finished
{
	bool endGame = false;
	for (int i = 0; i < 10; i++) {
		if (board[i][2] == 1) {
			endGame = true;
		}
	}
	if (endGame == true) {
		return true;

	}
	else {
		return false;
	}
}

void Board::MoveDown(int y) //move the board down if a line is deleted
{
	for (int i = y; i > 0; i--) {
		for (int j = 0; j < 10; j++) {
			board[j][i] = board[j][i - 1];
			}
		}
}

void Board::GetNextPiece() //get the next piece to draw
{
	
	int random = rand() % 7;
	Piece newPiece(random);
	piecesToDraw = newPiece;
	pieceType = random;
	rotations = 0;

}


