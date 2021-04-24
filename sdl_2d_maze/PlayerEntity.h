#pragma once

#include "Point.h"
#include <SDL.h>
#include "SDL_Helper.h"
#include "MazeGenerator.h" // my includes are a mess, i know
#include "Maze.h"

class PlayerEntity
{
public:
	PlayerEntity(Maze* m);

	void ProcessEvent(SDL_Event e);
	void LogicLoop();
	void OnRender(SDL_Renderer* gRenderer);

	Point currentPoint;

private:
	void TryMove(Direction d);

	// Bad practice?
	Maze* maze;
};

