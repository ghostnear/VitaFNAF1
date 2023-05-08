#pragma once

#include <libStorm.hpp>

#include <prefabs/SpriteNode.hpp>

struct BackgroundStaticConfig
{
    int lowAlpha = 50;
    int highAlpha = 144;
    double update_rate = 9 / 100.0;
    double frame_rate = 1 / 60.0;

    int frame_max_count = AssetManager::get_asset<AnimationAsset>("sprite_static")->get_frame_count();

    Prefabs::SpriteNodeConfig spriteCFG = {
        .image = AssetManager::get_asset<AnimationAsset>("sprite_static")->get_frame(0),
        .alpha = 2.0 / (lowAlpha + highAlpha)
    };
};

class BackgroundStatic : public Prefabs::SpriteNode
{
protected:
    static void update_background_static(Node* slf);

public:
    BackgroundStatic(BackgroundStaticConfig config);
};