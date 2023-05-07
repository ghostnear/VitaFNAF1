#pragma once

#include <prefabs/SpriteNode.hpp>

struct WarningSpriteConfig
{
    double alphaDecayRate = 0.5;
    Prefabs::SpriteNodeConfig spriteCFG = {
        .image = AssetManager::get_asset<ImageAsset>("sprite_menu_warning"),
        .position = {
            .x = Window::get_size().x / 2.0,
            .y = Window::get_size().y / 2.1
        },
        .scale = {
            .x = 1,
            .y = 1
        },
        .offset = {
            .x = 0.5,
            .y = 0.5
        },
        .alpha = 1
    };
};

class WarningSprite : public Prefabs::SpriteNode
{
private:
    static void update_warning_sprite(Node* slf);

public:
    // Constructor
    WarningSprite(WarningSpriteConfig config);
};
