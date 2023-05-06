#pragma once

#include <prefabs/TextNode.hpp>

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
