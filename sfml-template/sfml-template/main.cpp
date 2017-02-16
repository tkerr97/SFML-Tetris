//Final Project: Tetris
//Author: Trevor Kerr
//A minimal tetris clone
#include <iostream>
#include <SFML\Graphics.hpp>
#include <ctime>
#include <string>
#include "Board.h"

using namespace std;
using namespace sf;

void makeWalls(RenderWindow& window);
void drawTetros(RenderWindow& window, Board& board);
void drawLevel(RenderWindow& window, int level);
void gameOver(RenderWindow& window, Board&  board);

int main() {
	int level = 1;
	srand(time(NULL)); //seed random number generator
	Board board; //create board object
	RenderWindow window(VideoMode(640, 800), "Tetris"); //setup the window
	window.setFramerateLimit(144); //set framerate to 144fps
	int i = 0;
	board.GetNextPiece(); //generate first piece
	while(window.isOpen()) {
		window.clear();
		
		drawTetros(window, board);		
		makeWalls(window);
		level = board.linesCleared / 10 +1;
		gameOver(window, board);
		drawLevel(window, level);

		if (i % (144/level) == 0) { //move the piece down automatically
			board.CheckCollisionDown();
		}
		Event event;
		window.display();
		while (window.pollEvent(event)) { //check for events and check collision when they are moved
			if (event.type == Event::Closed) {
				window.close();
			}
			else if (event.type == Event::KeyPressed) {
				if (Keyboard::isKeyPressed(Keyboard::Q)) {
					window.close();
				}
				else if (Keyboard::isKeyPressed(Keyboard::Left)) {
					board.CheckCollisionLeft();
				}
				else if (Keyboard::isKeyPressed(Keyboard::Right)) {
					board.CheckCollisionRight();
				}
				else if (Keyboard::isKeyPressed(Keyboard::Down)) {
					board.CheckCollisionDown();
				}
				else if (Keyboard::isKeyPressed(Keyboard::Up)) {
					board.CheckCollisionRotate();
				}
			}
		}

		i++; //add one to the counter
		
	}
	return 0;
}

void makeWalls(RenderWindow& window) {
	RectangleShape wall1, wall2, wall3; //draw the walls of the board
	wall1.setSize(Vector2f(15, 600));
	wall2.setSize(Vector2f(15, 600));
	wall3.setSize(Vector2f(330, 15));
	wall1.setPosition(Vector2f(155, 60));
	wall2.setPosition(Vector2f(470, 60));
	wall3.setPosition(Vector2f(155, 660));
	wall1.setFillColor(Color(255, 255, 255, 255));
	wall2.setFillColor(Color(255, 255, 255, 255));
	wall3.setFillColor(Color(255, 255, 255, 255));
	window.draw(wall1);
	window.draw(wall2);
	window.draw(wall3);
}

void drawTetros(RenderWindow& window, Board& board) {
	board.DrawPiece(window); //draws the piece to the board
	for (int i = 0; i < 10; i++) { //checks the board for occupied space and draws it if it is occupied
		for (int j = 0; j < 25; j++) {
			if (board.board[i][j] == 1) {
				RectangleShape newTetro;
				newTetro.setSize(Vector2f(30, 30));
				newTetro.setFillColor(board.boardColor[i][j]);
				newTetro.setPosition(Vector2f((30 * i + 170), 30 * j));
				window.draw(newTetro);
			}

		}
	}
}

void drawLevel(RenderWindow& window, int level) {
	Font myFont;
	if (!myFont.loadFromFile("data\\arial.ttf")) {
		return;
	}
	Text text; //draws the level number onto the window
	text.setFont(myFont);
	string numberLevel = "Level: ";
	numberLevel.append(to_string(level));
	text.setString(numberLevel);
	text.setPosition(20, 100);
	text.setColor(Color(255, 255, 255, 255));
	text.setCharacterSize(20);
	window.draw(text);
}

void gameOver(RenderWindow& window, Board& board) {
	if (board.GameOver(window)) { //check to see if there are tetros in the top row
		Clock clock;
		while (1) {
			window.clear();
			Font myFont;
			if (!myFont.loadFromFile("data\\arial.ttf")) {
				return;
			}
			Text text;
			text.setFont(myFont);
			text.setString("GAME OVER");
			text.setPosition(20, 100);
			text.setColor(Color(255, 255, 255, 255));
			text.setCharacterSize(100);
			window.draw(text);
			window.display(); //display game over text
			Time elapsed = clock.getElapsedTime();
			if (elapsed > seconds(5)) { //wait 5 seconds before quitting
				return;
			}
		}
	}
}