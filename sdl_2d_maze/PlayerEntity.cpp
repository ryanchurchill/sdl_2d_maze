#include "PlayerEntity.h"
#include "MazeEntity.h"

PlayerEntity::PlayerEntity(Point startingPoint) : CurrentPoint(startingPoint)
{
}

void PlayerEntity::ProcessEvent(SDL_Event e)
{
	if (e.type == SDL_KEYDOWN) {
		if (e.key.keysym.sym == SDLK_UP) {
			TryMove(UP);
		} else if (e.key.keysym.sym == SDLK_RIGHT) {
			TryMove(RIGHT);
		}
		else if (e.key.keysym.sym == SDLK_DOWN) {
			TryMove(DOWN);
		}
		else if (e.key.keysym.sym == SDLK_LEFT) {
			TryMove(LEFT);
		}
	}
}

void PlayerEntity::LogicLoop()
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

void PlayerEntity::TryMove(Direction d)
{
	// TODO: validate
	switch (d) {
	case UP:
		CurrentPoint.y--;
		break;
	case RIGHT:
		CurrentPoint.x++;
		break;
	case DOWN:
		CurrentPoint.y++;
		break;
	case LEFT:
		CurrentPoint.x--;
		break;
	}
}
