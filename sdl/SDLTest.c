// Example program:
// Using SDL2 to create an application window

#include "SDL.h"
#include <stdio.h>

int main(int argc, char* argv[]) {

	SDL_Window *window;                    // Declare a pointer

	SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2
	
	// Create an application window with the following settings:
	window = SDL_CreateWindow(
		"SDL Test",                  // window title
		SDL_WINDOWPOS_UNDEFINED,           // initial x position
		SDL_WINDOWPOS_UNDEFINED,           // initial y position
		640,                               // width, in pixels
		480,                               // height, in pixels
		SDL_WINDOW_SHOWN                // flags - see below
	);

	// Check that the window was successfully created
	printf("heh\n");
	if (window == NULL) {
		// In the case that the window could not be made...
		printf("Could not create window: %s\n", SDL_GetError());
		return 1;
	}

	// The window is open: could enter program loop here (see SDL_PollEvent())

	int end = 0;
	
	SDL_Event event;
	while (!end) {
		while (SDL_PollEvent(&event)) {
			// handle your event here
			switch (event.type) {
				case SDL_QUIT:
					end = 1;
				break;
			}
		}
	}


	// Close and destroy the window
	SDL_DestroyWindow(window);

	// Clean up
	SDL_Quit();
	return 0;
}
