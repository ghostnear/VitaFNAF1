#pragma once

#include <libStorm.hpp>

#include <prefabs/SpriteNode.hpp>

struct MenuControllerConfig
{
    
};

class MenuController : public Node
{
protected:
    static void menu_draw_function(Node* slf);

public:
    MenuController(MenuControllerConfig config);
};