#pragma once

#include "Maze.h";
#include <SDL.h>

const int PIXELS_PER_UNIT = 40;
const int MAZE_PADDING = 30;

class MazeEntity
{
public:
	//MazeEntity();
	MazeEntity(Maze *m);

	void OnRender(SDL_Renderer* gRenderer);

	
	
private:
	Maze *maze;
	void RenderCell(const MazeCell mc, int gridX, int gridY, SDL_Renderer* gRenderer);
};

