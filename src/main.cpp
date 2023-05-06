#include <libStorm.hpp>
#include "states/all.hpp"
#include "system/GameManager.hpp"

using namespace Storm;

int main(int argc, char* argv[])
{
    // Init and quit on fail
    if(StormInit() == EXIT_FAILURE)
        return EXIT_FAILURE;

    // Set metadata
    Window::set_name("Five Nights At Freddy's");

    // Original game is supposed to run at 60 fps, but VSync will do.
    Graphics::toggle_vsync();
    GameManager::push_state(new LoadingState());
    
    // PSVita screen resolution.
    Window::set_size({960, 544});

    // Main loop
    return StormMainLoop();
}
