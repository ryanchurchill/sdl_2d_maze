#include "PlayerEntity.h"
#include "MazeEntity.h"

PlayerEntity::PlayerEntity(Point startingPoint) : CurrentPoint(startingPoint)
{
}

void PlayerEntity::OnRender(SDL_Renderer* gRenderer)
{
	// Red
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
	int x = CurrentPoint.x * PIXELS_PER_UNIT + MAZE_PADDING + (PIXELS_PER_UNIT / 2);
	int y = CurrentPoint.y * PIXELS_PER_UNIT + MAZE_PADDING + (PIXELS_PER_UNIT / 2);
	int r = (PIXELS_PER_UNIT / 2) - 5;
	SDL_Helper::DrawCircle(gRenderer, x, y, r);
	
}
