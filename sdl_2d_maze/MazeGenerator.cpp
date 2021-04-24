#include "MazeGenerator.h"

MazeGenerator::MazeGenerator()
{
}

Maze MazeGenerator::GenerateMaze()
{
	// initialize vars
	m = Maze::GetClosedMaze();
	CellsVisited = vector<Point>();

	CarveClosedMazeIntoPerfectMaze();

	return m;
}

int MazeGenerator::GetRandomInt(int min, int max)
{
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> distrib(0, max);

	return distrib(gen);
}

Direction MazeGenerator::GetRandomDirection(vector<Direction> directions)
{
	if (directions.size() == 0) {
		return INVALID;
	}

	int directionIndex = GetRandomInt(0, directions.size() - 1);

	return directions.at(directionIndex);
}

void MazeGenerator::CarveClosedMazeIntoPerfectMaze()
{
	// start at a random cell
	Point startingCell = Point{ GetRandomInt(0, UNITS_X), GetRandomInt(0, UNITS_Y) };

	stack<Point> cellTraversalStack;
	cellTraversalStack.push(startingCell);
	CellsVisited.push_back(startingCell);

	int counter = 0;
	while (!AreAllCellsVisited() && !cellTraversalStack.empty()) {
		Point currentCell = cellTraversalStack.top();
		vector<Direction> availableDirections = GetAvailableDirections(currentCell);
		Direction d = GetRandomDirection(availableDirections);
		if (d == INVALID) {
			cellTraversalStack.pop();
		}
		else {
			ConnectCells(currentCell, d);
			Point nextPoint = GetDestinationPoint(currentCell, d);
			cellTraversalStack.push(nextPoint);
			CellsVisited.push_back(nextPoint);
		}
		counter++;

		if (counter % 1000 == 0) {
			cout << "Counter : " << counter << "\n";
			m.DrawAsAscii();
		}
	}
	cout << "Counter : " << counter << "\n";
}

bool MazeGenerator::CellHasBeenVisited(Point p)
{
	for (auto it = CellsVisited.begin(); it != CellsVisited.end(); it++) {
		if ((*it).x == p.x && (*it).y == p.y) {
			return true;
		}
	}
	return false;
}

bool MazeGenerator::AreAllCellsVisited()
{
	return (CellsVisited.size() == UNITS_X * UNITS_Y);
}

vector<Direction> MazeGenerator::GetAvailableDirections(Point p)
{
	vector<Direction> directions;

	if (p.x > 0) {
		if (!CellHasBeenVisited(GetDestinationPoint(p, Direction::LEFT))) {
			directions.push_back(Direction::LEFT);
		}
	}
	if (p.x < UNITS_X - 1) {
		if (!CellHasBeenVisited(GetDestinationPoint(p, Direction::RIGHT))) {
			directions.push_back(Direction::RIGHT);
		}
	}
	if (p.y > 0) {
		if (!CellHasBeenVisited(GetDestinationPoint(p, Direction::UP))) {
			directions.push_back(Direction::UP);
		}
	}
	if (p.y < UNITS_Y - 1) {
		if (!CellHasBeenVisited(GetDestinationPoint(p, Direction::DOWN))) {
			directions.push_back(Direction::DOWN);
		}
	}

	return directions;
}

void MazeGenerator::ConnectCells(Point a, Direction d)
{
	MazeCell* SourceCell = GetCellFromPoint(a);
	MazeCell* DestinationCell = GetCellFromPoint(GetDestinationPoint(a, d));

	switch (d) {
	case UP:
		SourceCell->lineTop = false;
		DestinationCell->lineBottom = false;
		break;
	case RIGHT:
		SourceCell->lineRight = false;
		DestinationCell->lineLeft = false;
		break;
	case DOWN:
		SourceCell->lineBottom = false;
		DestinationCell->lineTop = false;
		break;
	case LEFT:
		SourceCell->lineLeft = false;
		DestinationCell->lineRight = false;
		break;
	}
	
}

Point MazeGenerator::GetDestinationPoint(Point a, Direction d)
{
	Point ret{ a.x, a.y };

	switch (d) {
	case UP:
		ret.y--;
		break;
	case RIGHT:
		ret.x++;
		break;
	case DOWN:
		ret.y++;
		break;
	case LEFT:
		ret.x--;
		break;
	}

	if (ret.x < 0 || ret.x >= UNITS_X || ret.y < 0 || ret.y >= UNITS_Y) {
		throw new exception("bad coordinates");
	}


	return ret;
}

MazeCell* MazeGenerator::GetCellFromPoint(Point p)
{
	return &(m.cells[p.x][p.y]);
}