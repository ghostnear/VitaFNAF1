#pragma once

#include <libStorm.hpp>
#include <prefabs/all.hpp>

struct FPSTextConfig
{
    // Denotes how often does the framerate update, default is once per second
    double updateRate = 1.0;
    Storm::Prefabs::TextNodeConfig textCfg;
};

class FPSText : public Storm::Prefabs::TextNode
{
public:
    // Constructor
    FPSText(FPSTextConfig config);
};
