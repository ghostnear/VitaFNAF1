#include "WarningSprite.hpp"

void WarningSprite::update_warning_sprite(Node* slf)
{
    double newAlpha = *slf->get_component<double>("sprite_alpha");
    newAlpha -= *slf->get_component<double>("alpha_decay_rate") * GameManager::get_delta_time();

    // Update alpha value.
    slf->set_component<double>(
        "sprite_alpha",
        new double(
            (newAlpha > 0) ? newAlpha : 0
        )
    );
    
    // Make sure the sprite is centered.
    slf->set_component<Vec2<double>>(
        "sprite_position",
        new Vec2<double>{
            .x = Window::get_size().x / 2.0,
            .y = Window::get_size().y / 2.0
        }
    );
}

WarningSprite::WarningSprite(WarningSpriteConfig config) : SpriteNode(config.spriteCFG)
{
    set_component(
        "alpha_decay_rate",
        new double(config.alphaDecayRate)
    );
    add_function(
        "update",
        WarningSprite::update_warning_sprite
    );
}