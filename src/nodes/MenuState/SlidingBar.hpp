#pragma once

#include <prefabs/SpriteNode.hpp>

struct SlidingBarConfig
{
    double slidingSpeed = 40;
    Prefabs::SpriteNodeConfig spriteCFG = {
        .image = AssetManager::get_asset<ImageAsset>("sprite_menu_bar"),
        .position = {
            .x = 0,
            .y = 200
        },
        .alpha = 0.125
    };
};

class SlidingBar : public Prefabs::SpriteNode
{
protected:
    static void sliding_bar_update(Node *slf);

public:
    // Constructor
    SlidingBar(SlidingBarConfig config);
};
