#pragma once

#include <SDL.h>
#include <stdio.h>
#include <string>
#include <ctime>
#include <iostream>

#include "Maze.h"
#include "MazeGenerator.h"

class App
{

public:
	App();

	int OnExecute();

	bool Init();

	void ProcessEvent(SDL_Event e);
	void LogicLoop();
	void RenderLoop();

	void Close();

private:
	//Screen dimension constants
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	//The window we'll be rendering to
	SDL_Window* gWindow;

	//The window renderer
	SDL_Renderer* gRenderer;

	// Main Loop flag
	bool Quit;
};


