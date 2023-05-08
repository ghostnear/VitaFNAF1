#pragma once

#include <prefabs/SpriteNode.hpp>

struct GameTitleConfig
{
    Prefabs::SpriteNodeConfig spriteCFG = {
        .image = AssetManager::get_asset<ImageAsset>("sprite_game_title"),
        .position = {
            .x = 110,
            .y = 50
        },
        .scale = {
            .x = 544.0 / 720,
            .y = 544.0 / 720
        }
    };
};

class GameTitle : public Prefabs::SpriteNode
{
public:
    // Constructor
    GameTitle(GameTitleConfig config);
};
