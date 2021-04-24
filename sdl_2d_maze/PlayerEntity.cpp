#include "PlayerEntity.h"
#include "MazeEntity.h"

PlayerEntity::PlayerEntity(Maze* m) : currentPoint(m->startingPoint), maze(m)
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
	int x = currentPoint.x * PIXELS_PER_UNIT + MAZE_PADDING + (PIXELS_PER_UNIT / 2);
	int y = currentPoint.y * PIXELS_PER_UNIT + MAZE_PADDING + (PIXELS_PER_UNIT / 2);
	int r = (PIXELS_PER_UNIT / 2) - 5;
	SDL_Helper::DrawCircle(gRenderer, x, y, r);
	
}

void PlayerEntity::TryMove(Direction d)
{
	// TODO: validate
	switch (d) {
	case UP:
		if (!(maze->GetCellFromPoint(currentPoint)->lineTop)) {
			currentPoint.y--;
		}
		break;
	case RIGHT:
		if (!(maze->GetCellFromPoint(currentPoint)->lineRight)) {
			currentPoint.x++;
		}
		break;
	case DOWN:
		if (!(maze->GetCellFromPoint(currentPoint)->lineBottom)) {
			currentPoint.y++;
		}
		break;
	case LEFT:
		if (!(maze->GetCellFromPoint(currentPoint)->lineLeft)) {
			currentPoint.x--;
		}
		break;
	}
}
