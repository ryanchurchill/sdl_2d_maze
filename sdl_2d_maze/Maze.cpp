#include "Maze.h"
#include <iostream>

Maze::Maze()
{
	// instantiate a completely closed maze
	for (int y = 0; y < UNITS_Y; y++) {
		for (int x = 0; x < UNITS_X; x++) {
			cells[x][y] = MazeCell{ true, true, true, true };
		}
	}

	// now mess with it
	cells[4][0].lineTop = false;

	cells[5][5].lineRight = false;
	cells[6][5].lineLeft = false;

}

// This is insane
void Maze::DrawAsAscii()
{
	for (int y = 0; y < UNITS_Y; y++) {

		if (y == 0) {
			std::cout << " ";
			for (int x = 0; x < UNITS_X; x++) {
				MazeCell c = cells[x][y];
				if (c.lineTop) {
					std::cout << "_";
				}
				else {
					std::cout << " ";
				}
				std::cout << " ";
			}
			std::cout << "\n";
		}

		for (int x = 0; x < UNITS_X; x++) {
			MazeCell c = cells[x][y];
			if (x == 0) {
				if (c.lineLeft) {
					std::cout << "|";
				}
				else {
					std::cout << " ";
				}
			}
			if (c.lineBottom) {
				std::cout << "_";
			}
			else {
				std::cout << " ";
			}
			if (c.lineRight) {
				std::cout << "|";
			}
			else {
				std::cout << " ";
			}
		}
		std::cout << "\n";
	}
}

