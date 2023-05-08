#include "MenuController.hpp"

void MenuController::menu_draw_function(Node* slf)
{
    for(auto child : slf->get_children())
        child.second->execute("draw");

    auto blip = slf->get_child("sprite_menu_options_arrow");
    auto choice = slf->get_component<int>("choice");
    auto max_choice = slf->get_component<int>("max_choice");

#ifndef VITA
    // Navigation using arrow keys.
    if(Input::isKeyPressed(SDLK_DOWN) || Input::isKeyPressed(SDLK_s))
        (*choice) = ((*choice) + 1) % (*max_choice);
    if(Input::isKeyPressed(SDLK_UP) || Input::isKeyPressed(SDLK_w))
    {
        (*choice) = ((*choice) - 1) % (*max_choice);
        if(*choice < 0)
            *choice = *(max_choice) - 1;
    }
#endif

    blip->set_component<Vec2<double>>(
        "sprite_position",
        new Vec2<double>{
            .x = 97,
            .y = 297.0 + 55 * (*choice)
        }
    );
}

MenuController::MenuController(MenuControllerConfig config)
{
    Prefabs::SpriteNodeConfig spriteConfig = {
        .position = {
            .x = 110,
            .y = 240
        },
        .scale = {
            .x = 544.0 / 720,
            .y = 544.0 / 720
        }
    };

    set_component<int>(
        "max_choice",
        new int(4)
    );

    set_component<int>(
        "choice",
        new int(0)
    );

    add_function(
        "draw",
        menu_draw_function
    );

    for(auto index = 0; index < 4; index++)
    {
        spriteConfig.image = AssetManager::get_asset<AnimationAsset>("sprite_menu_options")->get_frame(index);
        spriteConfig.position.y += 55;
        add_child(new Prefabs::SpriteNode(spriteConfig), "sprite_menu_options_" + Utils::to_string<int>(index));
    }

    spriteConfig = {
        .image = AssetManager::get_asset<AnimationAsset>("sprite_menu_options")->get_frame(4),
        .position = {
            .x = 97,
            .y = 297
        },
        .scale = {
            .x = 544.0 / 720,
            .y = 544.0 / 720
        },
        .offset = {
            .x = 1,
            .y = 0
        }
    };
    add_child(new Prefabs::SpriteNode(spriteConfig), "sprite_menu_options_arrow");
}