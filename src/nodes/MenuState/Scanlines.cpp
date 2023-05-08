#include "Scanlines.hpp"

void Scanlines::scanlines_update(Node *slf)
{
    // Update alpha
    auto alpha = slf->get_component<double>("sprite_alpha");
    auto alphaMax = slf->get_component<int>("scanlines_alpha_max");
    auto alphaMin = slf->get_component<int>("scanlines_alpha_min");
    auto alphaUpdateRate = slf->get_component<double>("scanlines_alpha_update_rate");
    auto alphaUpdateTimer = slf->get_component<double>("scanlines_alpha_update_timer");
    *alphaUpdateTimer += GameManager::get_delta_time();
    if(*alphaUpdateTimer > *alphaUpdateRate)
    {
        while(*alphaUpdateTimer > *alphaUpdateRate)
            *alphaUpdateTimer -= *alphaUpdateRate;

        *alpha = (double)(rand() % (*alphaMax - *alphaMin + 1) + *alphaMin) / 255.0;
    }

    // Update sprite visibility
    auto visibilityUpdateRate = slf->get_component<double>("scanlines_visibility_update_rate");
    auto visibilityUpdateTimer = slf->get_component<double>("scanlines_visibility_update_timer");
    *visibilityUpdateTimer += GameManager::get_delta_time();
    if(*visibilityUpdateTimer > *visibilityUpdateRate)
    {
        while(*visibilityUpdateTimer > *visibilityUpdateRate)
            *visibilityUpdateTimer -= *visibilityUpdateRate;

        slf->add_function(
            "draw",
            (rand() % 3 == 1) ? sprite_node_draw : nullptr
        );
    }

    // Update frame
    auto frameTime = slf->get_component<double>("sprite_frametime");
    *frameTime += GameManager::get_delta_time();

    auto frame = slf->get_component<int>("sprite_frame");
    auto frameRate = slf->get_component<double>("sprite_framerate");
    auto sprite = AssetManager::get_asset<AnimationAsset>("sprite_scanlines");
    if(*frameTime > *frameRate)
    {
        while(*frameTime > *frameRate)
        {
            *frame = (*frame + 1) % sprite->get_frame_count();
            *frameTime -= *frameRate;
        }
        slf->set_component<ImageAsset>(
            "sprite_image",
            sprite->get_frame(*frame)
        );
    }
}

Scanlines::Scanlines(ScanlinesConfig config) : SpriteNode(config.spriteCFG)
{
    set_component<double>(
        "sprite_frametime",
        new double(0)
    );

    set_component<double>(
        "scanlines_visibility_update_rate",
        new double(config.visibilityUpdateRate)
    );

    set_component<double>(
        "scanlines_visibility_update_timer",
        new double(0)
    );

    set_component<int>(
        "scanlines_alpha_max",
        new int(config.alphaMax)
    );

    set_component<int>(
        "scanlines_alpha_min",
        new int(config.alphaMin)
    );

    set_component<double>(
        "scanlines_alpha_update_rate",
        new double(config.alphaUpdateRate)
    );

    set_component<double>(
        "scanlines_alpha_update_timer",
        new double(0)
    );

    set_component<int>(
        "sprite_frame",
        new int(0)
    );

    set_component<double>(
        "sprite_framerate",
        new double(config.spriteFrameRate)
    );

    add_function(
        "update",
        scanlines_update
    );
}