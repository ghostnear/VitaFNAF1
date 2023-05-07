#include "MenuState.hpp"

using namespace Storm;

void MenuState::on_init()
{
    root->add_child(new BackgroundFreddy({}), "background_freddy");
    root->add_child(new BackgroundStatic({}), "background_static");
}

void MenuState::draw()
{
    Graphics::clear(0, 0, 0);

    // Draw scene
    root->execute_all("draw");

    Graphics::update();
}

void MenuState::update(double dt)
{
    // Press escape to close window
#ifndef VITA
    if(Input::isKeyReleased(SDLK_ESCAPE))
        Window::close();
#endif

    // Update scene
    root->execute_all("update");
}
