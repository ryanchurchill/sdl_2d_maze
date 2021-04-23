#include "Maze.h"

Maze::Maze()
{
	MazeCell cells[UNITS_X][UNITS_Y];
	
	// instantiate a completely closed maze
	for (int y = 0; y < UNITS_Y; y++) {
		for (int x = 0; x < UNITS_X; x++) {
			cells[x][y] = MazeCell{ true, true, true, true };
		}
	}
}

void Maze::DrawAsAscii()
{
	for (int y = 0; y < UNITS_Y; y++) {
		for (int x = 0; x < UNITS_X; x++) {
			DrawCell(cells[x][y]);
		}
	}
}

void Maze::DrawCell(MazeCell c)
{
}

