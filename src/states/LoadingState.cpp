#include "LoadingState.hpp"
#include "prefabs/SpriteNode.hpp"
#include "prefabs/TextNode.hpp"
#include "system/AssetTypes/FontAsset.hpp"

using namespace Storm;

void LoadingState::on_init()
{
    Prefabs::TextNodeConfig textCFG;
    textCFG.size = 32;
    textCFG.initialText = "Loading...";
    textCFG.boundaries = {
        .position = {
            .x = 920,
            .y = 490,
        },
        .size = {
            .x = 100,
            .y = 25,
        }
    };
    textCFG.textOffset = {
        .x = 1,
        .y = 0
    };
    root->add_child(new Prefabs::TextNode(textCFG), "text_loading");

    Prefabs::SpriteNodeConfig loadingChimeCFG;
    root->add_child(new Prefabs::SpriteNode(loadingChimeCFG), "sprite_loading");

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

    // Check if font was loaded, and if so, set the loading text font to it.
    static FontAsset* loadingFont; loadingFont = AssetManager::get_asset<FontAsset>("font_pixel");
    if(loadingFont != nullptr)
    {
        auto textLoading = root->get_child("text_loading");
        textLoading->set_component<FontAsset>(
            "text_font",
            loadingFont
        );
    }

    // Update scene
    root->execute_all("update");

    // Go to main scene after waiting for thread to stop
    if(AssetLoader::get_percentage() == 1.1)
    {
        AssetLoader::finish();
        GameManager::pop_state();
        GameManager::push_state(new MainState());
    }
}
