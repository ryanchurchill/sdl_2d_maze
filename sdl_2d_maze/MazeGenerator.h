#pragma once
#include <vector>
#include <ctime>
#include <random>
#include <stack>

#include "Maze.h"

using namespace std;

enum Direction {
	UP, RIGHT, DOWN, LEFT, INVALID
};

class MazeGenerator
{
public:
	MazeGenerator();
	Maze GenerateMaze();

	static int GetRandomInt(int min, int max);
	static Direction GetRandomDirection(vector<Direction>);
private:
	Maze m;
	vector<Point> CellsVisited;

	void CarveClosedMazeIntoPerfectMaze();
	bool CellHasBeenVisited(Point p);
	bool AreAllCellsVisited();
	vector<Direction> GetAvailableDirections(Point p);
	void ConnectCells(Point a, Direction d);
	Point GetDestinationPoint(Point a, Direction d);
	MazeCell* GetCellFromPoint(Point p);
};