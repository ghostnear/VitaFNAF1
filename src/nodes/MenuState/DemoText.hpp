#pragma once

#include <prefabs/SpriteNode.hpp>

struct DemoTextConfig
{
    Prefabs::SpriteNodeConfig spriteCFG = {
        .image = AssetManager::get_asset<ImageAsset>("sprite_demo_text"),
        .position = {
            .x = 110,
            .y = 222
        },
        .scale = {
            .x = 544.0 / 720,
            .y = 544.0 / 720
        }
    };
};

class DemoText : public Prefabs::SpriteNode
{
public:
    // Constructor
    DemoText(DemoTextConfig config);
};
