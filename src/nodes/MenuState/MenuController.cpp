#include "MenuController.hpp"

void MenuController::menu_draw_function(Node* slf)
{
    for(auto child : slf->get_children())
        child.second->execute("draw");
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