#include "MenuState.hpp"

using namespace Storm;

void MenuState::on_init()
{
    root->add_child(new BackgroundFreddy({}), "background_freddy");
    root->add_child(new BackgroundStatic({}), "background_static");
    root->add_child(new GameTitle({}), "game_title");
    root->add_child(new MenuController({}), "menu_controller");

#ifdef DEMO
    root->add_child(new DemoText({}), "demo_text");
#endif
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
