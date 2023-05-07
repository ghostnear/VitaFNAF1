#pragma once

#include <libStorm.hpp>

#include <prefabs/SpriteNode.hpp>

struct BackgroundFreddyConfig
{
    int lowAlpha = 0;
    int highAlpha = 249;
    double update_rate = 1 / 60.0;
    double frame_rate = 8 / 100.0;

    int frame_max_count = AssetManager::get_asset<AnimationAsset>("sprite_menu_freddy")->get_frame_count();

    Prefabs::SpriteNodeConfig spriteCFG = {
        .image = AssetManager::get_asset<AnimationAsset>("sprite_menu_freddy")->get_frame(0),
        .alpha = 2.0 / (highAlpha - lowAlpha)
    };
};

class BackgroundFreddy : public Prefabs::SpriteNode
{
protected:
    static void update_background_freddy(Node* slf);

public:
    BackgroundFreddy(BackgroundFreddyConfig config);
};