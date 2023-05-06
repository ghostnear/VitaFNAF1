#pragma once

#include <prefabs/all.hpp>

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
public:
    // Constructor
    MainText(MainTextConfig config);
};
