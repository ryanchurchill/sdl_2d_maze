#pragma once

#include <iostream>

#include "Point.h"


/*
Represents the data of a maze
Assuming Resolution of 640 x 480
Let's make a maze of 32 x 24
Each square is 20x20
*/

//const int UNITS_X = 32;
//const int UNITS_Y = 24;

const int UNITS_X = 10;
const int UNITS_Y = 10;

struct MazeCell
{
	bool lineTop;
	bool lineRight;
	bool lineLeft;
	bool lineBottom;
};


class Maze
{
public:
	Maze();

	void DrawAsAscii();

	static Maze GetClosedMaze();

	// TODO: make private?
	// [x][y] starting at upper left
	MazeCell cells[UNITS_X][UNITS_Y];

	Point center;
private:
	
};

