#include "LoadingSprite.hpp"

void LoadingSprite::update_loading_sprite(Node* slf)
{
    auto sprite = AssetManager::get_asset<ImageAsset>("sprite_loading");
    if(sprite != nullptr)
        slf->set_component<ImageAsset>("sprite_image", sprite);
}

LoadingSprite::LoadingSprite(LoadingSpriteConfig config) : SpriteNode(config.spriteCFG)
{
    add_function(
        "update",
        LoadingSprite::update_loading_sprite
    );
}