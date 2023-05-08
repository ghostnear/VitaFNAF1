#pragma once

#include <prefabs/SpriteNode.hpp>

struct ScanlinesConfig
{
    int alphaMax = 100;
    int alphaMin = 50;
    double alphaUpdateRate = 8.0 / 100;

    double spriteFrameRate = 1.0 / 6;

    double visibilityUpdateRate = 30.0 / 100;

    Prefabs::SpriteNodeConfig spriteCFG = {
        .image = AssetManager::get_asset<AnimationAsset>("sprite_scanlines")->get_frame(0),
        .alpha = 0.5
    };
};

class Scanlines : public Prefabs::SpriteNode
{
protected:
    static void scanlines_update(Node *slf);

public:
    // Constructor
    Scanlines(ScanlinesConfig config);
};