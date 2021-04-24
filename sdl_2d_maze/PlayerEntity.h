#pragma once

#include "Point.h"
#include <SDL.h>
#include "SDL_Helper.h"
#include "MazeGenerator.h" // my includes are a mess, i know

class PlayerEntity
{
public:
	PlayerEntity(Point startingPoint);

	Point CurrentPoint;

	void ProcessEvent(SDL_Event e);
	void LogicLoop();
	void OnRender(SDL_Renderer* gRenderer);

private:
	void TryMove(Direction d);
};

