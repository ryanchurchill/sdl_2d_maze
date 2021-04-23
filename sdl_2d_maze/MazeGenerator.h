#pragma once
#include <vector>
#include <ctime>
#include <random>

#include "Maze.h"

using namespace std;

enum Direction {
	UP, RIGHT, DOWN, LEFT, INVALID
};

struct PathSegment {
	int start_x;
	int start_y;
	Direction direction;
};

class MazeGenerator
{
};

class PathGenerator
{
public:
	int grid[UNITS_X][UNITS_Y];

	// array of segments
	//Vector<PathSegment> path;

	vector<PathSegment> GeneratePath(Point a, Point b);

	

private:
	vector<PathSegment> TryGeneratePath(Point a, Point b);
	Direction Approach(Point a, Point b, vector<PathSegment> pathSoFar);
	bool PathContainsPoint(Point p, vector<PathSegment> path);
	Point GetDestinationPoint(Point a, Direction d);
};