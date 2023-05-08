#include "SlidingBar.hpp"

void SlidingBar::sliding_bar_update(Node* slf)
{
    auto position = slf->get_component<Vec2<double>>("sprite_position");
    auto slidingSpeed = slf->get_component<double>("sliding_speed");

    (*position).y += *slidingSpeed * GameManager::get_delta_time();
    if((*position).y > 544)
        (*position).y = -(*(slf->get_component<ImageAsset>("sprite_image"))).get_size().y;
}

SlidingBar::SlidingBar(SlidingBarConfig config) : Prefabs::SpriteNode(config.spriteCFG)
{
    set_component<double>(
        "sliding_speed",
        new double(config.slidingSpeed)
    );

    add_function(
        "update",
        sliding_bar_update
    );
}