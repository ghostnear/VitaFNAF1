#include "LoadingState.hpp"
#include "prefabs/SpriteNode.hpp"
#include "prefabs/TextNode.hpp"
#include "system/AssetTypes/FontAsset.hpp"

using namespace Storm;

void LoadingState::on_init()
{
    root->add_child(new LoadingText({}), "text_loading");

    AssetLoader::load("./assets/assetlist.json");
    AssetLoader::start();
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
        GameManager::push_state(new WarningState());
    }
}
