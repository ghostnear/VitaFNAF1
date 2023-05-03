#include "MainState.hpp"

using namespace Storm;

void MainState::on_init()
{
    FPSTextConfig fpsTextcfg;
    fpsTextcfg.textCfg.size = 32;
    root->add_child(new FPSText(fpsTextcfg), "fps_text");

    MainTextConfig config;
    root->add_child(new MainText(config), "main_text");
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

    // Toggle fullscreen
#ifndef VITA
    if(Input::isKeyPressed(SDLK_F11))
    {
        if(!Window::is_fullscreen())
            Window::set_fullscreen(SDL_WINDOW_FULLSCREEN_DESKTOP);
        else
            Window::set_fullscreen(0);
    }
#endif
}
