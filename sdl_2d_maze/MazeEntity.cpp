#include "MazeEntity.h"

//MazeEntity::MazeEntity() : maze(NULL) {
//	int x = 0;
//}
MazeEntity::MazeEntity(Maze *m) : maze(m) {}


void MazeEntity::OnRender(SDL_Renderer* gRenderer)
{
	// Blue
	SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0xFF, 0xFF);

	for (int x = 0; x < UNITS_X; x++) {
		for (int y = 0; y < UNITS_Y; y++) {
			RenderCell((maze->cells[x][y]), x, y, gRenderer);
		}
	}
}

void MazeEntity::RenderCell(const MazeCell mc, int gridX, int gridY, SDL_Renderer* gRenderer)
{
	Point upperLeftPos{ gridX * PIXELS_PER_UNIT + MAZE_PADDING, gridY * PIXELS_PER_UNIT + MAZE_PADDING};
	if (mc.lineTop) {
		int x1 = upperLeftPos.x;
		int x2 = x1 + PIXELS_PER_UNIT;
		int y = upperLeftPos.y;
		SDL_RenderDrawLine(gRenderer, x1, y, x2, y);
	}
	if (mc.lineBottom) {
		int x1 = upperLeftPos.x;
		int x2 = x1 + PIXELS_PER_UNIT;
		int y = upperLeftPos.y + PIXELS_PER_UNIT;
		SDL_RenderDrawLine(gRenderer, x1, y, x2, y);
	}
	if (mc.lineLeft) {
		int x = upperLeftPos.x;
		int y1 = upperLeftPos.y;
		int y2 = upperLeftPos.y + PIXELS_PER_UNIT;
		SDL_RenderDrawLine(gRenderer, x, y1, x, y2);
	}
	if (mc.lineRight) {
		int x = upperLeftPos.x + PIXELS_PER_UNIT;
		int y1 = upperLeftPos.y;
		int y2 = upperLeftPos.y + PIXELS_PER_UNIT;
		SDL_RenderDrawLine(gRenderer, x, y1, x, y2);
	}
	
}