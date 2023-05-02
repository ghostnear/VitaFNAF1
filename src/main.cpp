#include <libStorm.hpp>
#include "states/all.hpp"

using namespace Storm;

// The role of this example is mostly to show how to make a window and manage states.
// It is also used as a base for anything else.

int main(int argc, char* argv[])
{
    // Init and quit on fail
    if(StormInit() == EXIT_FAILURE)
        return EXIT_FAILURE;

    // Set metadata
    Window::set_name("libStorm Example");

    // Push the default state to the manager
    // TODO: replace this with a config system to make everything customizable
    // TODO: also make it actually work as it limits nothing.
#ifdef VITA
    GameManager::limit_FPS(60);
#else
    GameManager::limit_FPS(200);
#endif

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
