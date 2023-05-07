#include "WarningSprite.hpp"

void WarningSprite::update_warning_sprite(Node* slf)
{
    // Update alpha value.
    auto newAlpha = slf->get_component<double>("sprite_alpha");
    *newAlpha -= *slf->get_component<double>("alpha_decay_rate") * GameManager::get_delta_time();
    *newAlpha = (*newAlpha > 0) ? *newAlpha : 0;
    
    // Make sure the sprite is centered.
    auto spritePosition = slf->get_component<Vec2<double>>("sprite_position");
    (*spritePosition).x = Window::get_size().x / 2.0;
    (*spritePosition).y = Window::get_size().y / 2.1;
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