#include "LoadingState.hpp"

using namespace Storm;

void LoadingState::on_init()
{
    root->add_child(new LoadingSprite({}), "sprite_loading");
    root->add_child(new LoadingText({}), "text_loading");

    AssetLoader::load("./assets/assetlist.json");
    AssetLoader::start();
}

void LoadingState::update()
{
    State::update();

    // Go to main scene after waiting for thread to stop
    if(AssetLoader::get_percentage() == 1)
    {
        AssetLoader::finish();
        GameManager::pop_state();
        GameManager::push_state(new WarningState());
    }
}
