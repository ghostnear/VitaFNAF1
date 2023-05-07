#include "WarningState.hpp"

using namespace Storm;

void WarningState::on_init()
{
    
}

void WarningState::on_destroy()
{

}

void WarningState::draw()
{
    Graphics::clear(0, 0, 0);

    // Draw scene
    root->execute_all("draw");

    Graphics::update();
}

void WarningState::update(double dt)
{
    // Press escape to close window
#ifndef VITA
    if(Input::isKeyReleased(SDLK_ESCAPE))
        Window::close();
#endif

    // Update scene
    root->execute_all("update");
}
