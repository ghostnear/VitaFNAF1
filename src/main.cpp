#include <libStorm.hpp>
#include "states/all.hpp"

using namespace Storm;

int main(int argc, char* argv[])
{
    // Init and quit on fail
    if(StormInit() == EXIT_FAILURE)
        return EXIT_FAILURE;

    // Set metadata
    Window::set_name("Five Nights At Freddy's");

    // Original game is supposed to run at 60 fps, but VSync will work.
    Graphics::toggle_vsync();
    GameManager::push_state(new LoadingState());

    // Main loop
    while(!Window::should_close() && GameManager::is_running())
    {
        // Poll events
        Input::pollEvents();

        // Update
        GameManager::update();

        // Draw
        if(!Window::is_minimized())
            GameManager::draw();
    }

    // Quit and return the quit result
    return StormQuit(EXIT_SUCCESS);
}
