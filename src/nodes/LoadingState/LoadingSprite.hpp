#pragma once

#include <prefabs/SpriteNode.hpp>

struct LoadingSpriteConfig
{
    Prefabs::SpriteNodeConfig spriteCFG = {
        .position = {
            .x = 920,
            .y = 500
        },
        .offset = {
            .x = 1,
            .y = .5
        }
    };
};

class LoadingSprite : public Prefabs::SpriteNode
{
private:
    static void update_loading_sprite(Node* slf);

public:
    // Constructor
    LoadingSprite(LoadingSpriteConfig config);
};
