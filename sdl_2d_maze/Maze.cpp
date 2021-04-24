#include "Maze.h"


Maze::Maze()
{
	center.x = UNITS_X / 2;
	center.y = UNITS_Y / 2;

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
				/*if (x == center.x && y == center.y) {
					std::cout << "x\u0332";
				}
				else {*/
					std::cout << "_";
				//}
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

Maze Maze::GetClosedMaze()
{
	Maze m = Maze();
	// instantiate a completely closed maze
	for (int y = 0; y < UNITS_Y; y++) {
		for (int x = 0; x < UNITS_X; x++) {
			m.cells[x][y] = MazeCell{ true, true, true, true };
		}
	}

	// now mess with it
	/*m.cells[4][0].lineTop = false;

	m.cells[5][5].lineRight = false;
	m.cells[6][5].lineLeft = false;*/

	return m;
}

