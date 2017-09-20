#include <SDL.h>
#include <stdio.h>
#include "Matrix.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;

bool keyState[285] = {false};

// Initialize SDL and set window, screenSurface
bool init();

// Quits SDL and closes application
void quit();

// Runs the main event loop
void mainloop();

// Fired when a key is pressed
void keydown(SDL_Keycode& key);

// Fired when a key is released
void keyup(SDL_Keycode& key);

int main(int argc, char* args[]) {
	if (!init()) { // Initialization
		return 0;
	}

	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0x00, 0x00));
	SDL_UpdateWindowSurface(window);

	mainloop(); // Start the main event loop

	quit();
	return 0;
}

bool init() {
	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return false;
	}

	// Create the SDL window
	window = SDL_CreateWindow("3D Engine Sample", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL) {
		return false;
	}

	// Create the screen surface
	screenSurface = SDL_GetWindowSurface(window);

	return true;
}

void quit() {
	// Dispose of window and quit SDL
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void mainloop() {
	bool quit = false; // Should the loop end?
	SDL_Event e;
	while (!quit) { // While running
		while (SDL_PollEvent(&e) != 0) { // Get events
			switch (e.type) {
				case SDL_QUIT: // Quit the program
					quit = true;
					break;
				case SDL_KEYDOWN: // Key down event
					if (!keyState[SDL_GetScancodeFromKey(e.key.keysym.sym)]) keydown(e.key.keysym.sym);
					break;
				case SDL_KEYUP: // Key up event
					if (keyState[SDL_GetScancodeFromKey(e.key.keysym.sym)]) keyup(e.key.keysym.sym);
					break;
			}
		}
	}
}

void keydown(SDL_Keycode& key) {
	keyState[SDL_GetScancodeFromKey(key)] = true;

	if (key == SDLK_RETURN) {
		SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0x00));

		Matrix matrix;
		matrix.SetMatrix({
		0.0, 0.0, 0.0, 1.0,
		0.0, 0.0, 1.0, 0.0,
		0.0, 1.0, 0.0, 0.0,
		1.0, 0.0, 0.0, 0.0
		});

		matrix.SetValues({ 1, 2, 3, 4 });

		std::array<double, 4> mout = matrix.Calculate();

		int j = 50;
		for each(double f in mout) {
			SDL_Rect* r = new SDL_Rect();
			r->x = j;
			r->y = 50;
			r->w = 20;
			r->h = f * 20;

			SDL_FillRect(screenSurface, r, SDL_MapRGB(screenSurface->format, 0xFF, 0x00, 0x00));

			j += 30;
		}

		SDL_UpdateWindowSurface(window);
	}
}

void keyup(SDL_Keycode& key) {
	keyState[SDL_GetScancodeFromKey(key)] = false;

	if (key == SDLK_RETURN) {
		SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0x00, 0x00));
		SDL_UpdateWindowSurface(window);
	}
}