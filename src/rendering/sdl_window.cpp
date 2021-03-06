#include "sdl_window.hpp"

namespace Engine::Game
{
    SDLWindow::SDLWindow()
    {
        // Create default window
        window = SDL_CreateWindow("<window_name>",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if(window == NULL)
        {
            printf("{E}: Could not create SDL window: %s!", SDL_GetError());
            Core::exit_process(-1);
        }

        // Create default renderer
        renderer = SDL_CreateRenderer(window, -1, 0);

        if(renderer == NULL)
        {
            printf("{E}: Could not create SDL renderer: %s!", SDL_GetError());
            Core::exit_process(-1);
        }
    };

    std::pair<int, int> SDLWindow::getSize()
    {
        int x, y;
        SDL_GetWindowSize(window, &x, &y);
        return std::make_pair(x, y);
    }

    SDLWindow::~SDLWindow()
    {
        // Clean up
        SDL_DestroyWindow(window);
        window = NULL;
        SDL_DestroyRenderer(renderer);
        renderer = NULL;
    }

    SDL_Window *SDLWindow::getWindow()
    {
        // Returns the window pointer
        return window;
    }

    void SDLWindow::renameWindow(std::string newName)
    {
        // Rename the window using the C string
        SDL_SetWindowTitle(window, newName.c_str());
    }

    SDL_Renderer *SDLWindow::getRenderer()
    {
        // Returns the renderer pointer
        return renderer;
    }
};