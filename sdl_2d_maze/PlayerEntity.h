#pragma once

#include "Point.h"
#include <SDL.h>
#include "SDL_Helper.h"

class PlayerEntity
{
public:
	PlayerEntity(Point startingPoint);

	Point CurrentPoint;

	void OnRender(SDL_Renderer* gRenderer);
};

