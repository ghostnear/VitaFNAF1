#pragma once

#include <prefabs/all.hpp>

struct LoadingTextConfig
{
    Storm::Prefabs::TextNodeConfig textCfg;
};

class LoadingText : public Storm::Prefabs::TextNode
{
public:
    // Constructor
    LoadingText(LoadingTextConfig config);
};
