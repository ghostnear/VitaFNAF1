#include "BackgroundFreddy.hpp"

#include <ctime>

void BackgroundFreddy::update_background_freddy(Node* slf)
{
    // Update alpha timer.
    auto update_timer = slf->get_component<double>("update_timer");
    auto update_rate = slf->get_component<double>("update_rate");
    *update_timer += GameManager::get_delta_time();

    // Update sprite frame.
    auto frame = slf->get_component<int>("sprite_frame");
    auto frame_max_count = slf->get_component<int>("frame_max_count");
    auto frame_timer = slf->get_component<double>("frame_timer");
    auto frame_rate = slf->get_component<double>("frame_rate");
    *frame_timer += GameManager::get_delta_time();

    if(*update_timer > *update_rate)
    {
        while(*update_timer > *update_rate)
            *update_timer -= *update_rate;

        auto alpha = slf->get_component<double>("sprite_alpha");
        auto highAlpha = slf->get_component<int>("alpha_upper_bound");
        auto lowAlpha = slf->get_component<int>("alpha_lower_bound");
        *alpha = (double)(rand() % (*highAlpha - *lowAlpha + 1) + *lowAlpha) / 255.0;
    }

    if(*frame_timer > *frame_rate)
    {
        while(*frame_timer > *frame_rate)
            *frame_timer -= *frame_rate;
        
        static int random_number;
        random_number = rand() % 100;
        if(random_number < 97)
            *frame = 0;
        else
            *frame = random_number - 96;

        slf->set_component<ImageAsset>(
            "sprite_image",
            AssetManager::get_asset<AnimationAsset>("sprite_menu_freddy")->get_frame(*frame)
        );
    }
}

BackgroundFreddy::BackgroundFreddy(BackgroundFreddyConfig config) : SpriteNode(config.spriteCFG)
{
    set_component<int>(
        "sprite_frame",
        new int(0)
    );

    set_component<int>(
        "frame_max_count",
        new int(config.frame_max_count)
    );

    set_component<int>(
        "alpha_lower_bound",
        new int(config.lowAlpha)
    );

    set_component<int>(
        "alpha_upper_bound",
        new int(config.highAlpha)
    );

    set_component<double>(
        "update_rate",
        new double(config.update_rate)
    );

    set_component<double>(
        "update_timer",
        new double(0)
    );

    set_component<double>(
        "frame_rate",
        new double(config.frame_rate)
    );

    set_component<double>(
        "frame_timer",
        new double(0)
    );

    add_function(
        "update",
        update_background_freddy
    );
}