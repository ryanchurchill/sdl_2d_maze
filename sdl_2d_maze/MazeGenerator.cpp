#include "MazeGenerator.h"

vector<PathSegment> PathGenerator::GeneratePath(Point a, Point b)
{
	

	vector<PathSegment> path;
	
	path = TryGeneratePath(a, b);
	

	return path;
}

vector<PathSegment> PathGenerator::TryGeneratePath(Point a, Point b)
{
	Point currentPoint = a;
	vector<PathSegment> pathSoFar;
	while (!(currentPoint.x == b.x && currentPoint.y == b.y)) {
		
		Direction d = Approach(currentPoint, b, pathSoFar);
		if (d != INVALID) {
			pathSoFar.push_back(PathSegment{ currentPoint.x, currentPoint.y, d });
			currentPoint = GetDestinationPoint(currentPoint, d);
		}
		else {
			return vector<PathSegment>();
		}
	}

	return pathSoFar;
}

Direction PathGenerator::Approach(Point a, Point b, vector<PathSegment> pathSoFar)
{
	//srand((unsigned)time(0));	
	
	
	//PathSegment segment{ a.x, a.y };
	vector<Direction> availableDirections;
	if (a.x > 0) {
		if (!PathContainsPoint(GetDestinationPoint(a, Direction::LEFT), pathSoFar)) {
			availableDirections.push_back(Direction::LEFT);
		}
	}
	if (a.x < UNITS_X - 1) {
		if (!PathContainsPoint(GetDestinationPoint(a, Direction::RIGHT), pathSoFar)) {
			availableDirections.push_back(Direction::RIGHT);
		}
	}
	if (a.y > 0) {
		if (!PathContainsPoint(GetDestinationPoint(a, Direction::UP), pathSoFar)) {
			availableDirections.push_back(Direction::UP);
		}
	}
	if (a.y < UNITS_Y - 1) {
		if (!PathContainsPoint(GetDestinationPoint(a, Direction::DOWN), pathSoFar)) {
			availableDirections.push_back(Direction::DOWN);
		}
	}
	if (availableDirections.size() > 0) {

		//int randomDirectionIndex = rand() % availableDirections.size();
		std::random_device rd;  //Will be used to obtain a seed for the random number engine
		std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
		std::uniform_int_distribution<> distrib(0, availableDirections.size()-1);
		int randomDirectionIndex = distrib(gen);
		return availableDirections[randomDirectionIndex];
	}
	else {
		return INVALID;
	}
}

bool PathGenerator::PathContainsPoint(Point p, vector<PathSegment> path)
{
	for (auto it = path.begin(); it != path.end(); it++) {
		if ((*it).start_x == p.x && (*it).start_y == p.y) {
			return true;
		}
	}
	return false;
}

Point PathGenerator::GetDestinationPoint(Point a, Direction d)
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

	return ret;
}