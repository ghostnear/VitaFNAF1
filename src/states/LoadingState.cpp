#include "LoadingState.hpp"

using namespace Storm;

void LoadingState::on_init()
{
    LoadingBarConfig cfg;
    root->add_child(new LoadingBar(cfg), "loading_bar");

    AssetLoader::load("./assets/assetlist.json");
    AssetLoader::start();
}

void LoadingState::on_destroy()
{

}

void LoadingState::draw()
{
    Graphics::clear(0, 0, 0);

    // Draw scene
    root->execute_all("draw");

    Graphics::update();
}

void LoadingState::update(double dt)
{
    // Press escape to close window
#ifndef VITA
    if(Input::isKeyReleased(SDLK_ESCAPE))
        Window::close();
#endif

    // Update scene
    root->execute_all("update");

    // Go to main scene after waiting for thread to stop
    if(AssetLoader::get_percentage() == 1)
    {
        AssetLoader::finish();
        GameManager::pop_state();
        GameManager::push_state(new MainState());
    }

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
