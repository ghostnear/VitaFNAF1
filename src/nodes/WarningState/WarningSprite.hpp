#pragma once

#include <prefabs/SpriteNode.hpp>

struct WarningSpriteConfig
{
    double alphaDecayRate = 0.5;
    Prefabs::SpriteNodeConfig spriteCFG = {
        .image = AssetManager::get_asset<ImageAsset>("sprite_menu_warning"),
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
