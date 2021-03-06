#include "engine.hpp"
#include <cstdlib>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>

using namespace Engine;
using namespace Engine::Game;

int main(int argc, char* argv[])
{
	// Init SDL stuff
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
		Core::exit_process(-1);
	if(IMG_Init(IMG_INIT_PNG) < 0)
		Core::exit_process(-1);
	if(Mix_Init(MIX_INIT_MP3) < 0)
		Core::exit_process(-1);
	if(Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 1024) < 0)
		Core::exit_process(-1);
	Mix_AllocateChannels(50);

	// Initialise RNG
	srand(time(NULL));

	// Create the window and get the renderer pointer
	Game::SDLWindow* win = new Game::SDLWindow();
	SDL_Renderer* ren = win -> getRenderer();
	win -> renameWindow("Five Nights at Freddy's");
	
	// Create the scene manager with the base scene
	Game::SceneManager man(win);
	man.push(new Game::Scenes::SceneLoading(), ren);

	// Event polling and delta timing
	SDL_Event e;
	Core::DeltaTimer dt;

	// While not fully exited
	while(man.getStateCount() >= 1)
	{
		// Handle queue events
		while(SDL_PollEvent(&e))
		{
			// Quit event has been sent
			if(e.type == SDL_QUIT)
			{
				// Clear all states from memory so the game can stop
				man.clear();
			}
		}

		// Update the state
		man.update(dt.getDelta());

		// Clear, draw and update
		SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);
		SDL_RenderClear(ren);
		man.draw();
		SDL_RenderPresent(ren);

		// Update the timing and delay
		SDL_Delay(5);
		dt.update();
	}

	// Quit SDL stuff
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();

	// Exit the process
	Core::exit_process(0);
}