#pragma once

#include <prefabs/TextNode.hpp>

struct MainTextConfig
{
    // Denotes how often does the framerate update, default is once per second
    Storm::Vec2<double> padding = {
        .x = 0.5,
        .y = 0.5
    };
    double scale = 0.5;
    Storm::Prefabs::TextNodeConfig textCfg = {
        .size = 64
    };
};

class MainText : public Storm::Prefabs::TextNode
{
protected:
    static void main_text_update(Node* slf);

public:
    // Constructor
    MainText(MainTextConfig config);
};
