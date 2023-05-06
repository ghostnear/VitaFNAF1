#include "MainState.hpp"

using namespace Storm;

void MainState::on_init()
{
    MainTextConfig config;
    root->add_child(new MainText(config), "text_main");
}

void MainState::on_destroy()
{

}

void MainState::draw()
{
    Graphics::clear(0, 0, 0);

    // Draw scene
    root->execute_all("draw");

    Graphics::update();
}

void MainState::update(double dt)
{
    // Press escape to close window
#ifndef VITA
    if(Input::isKeyReleased(SDLK_ESCAPE))
        Window::close();
#endif

    // Update scene
    root->execute_all("update");
}
