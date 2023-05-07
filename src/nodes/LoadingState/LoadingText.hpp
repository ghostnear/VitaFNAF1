#pragma once

#include <prefabs/TextNode.hpp>

struct LoadingTextConfig
{
    Prefabs::TextNodeConfig textCFG = {
        .size = 32,
        .textOffset = {
            .x = 1,
            .y = 0
        },
        .boundaries = {
            .position = {
                .x = 920,
                .y = 490,
            },
            .size = {
                .x = 100,
                .y = 25,
            }
        },
        .initialText = "Loading..."
    };
};

class LoadingText : public Prefabs::TextNode
{
private:
    static void update_loading_text(Node* slf);

public:
    // Constructor
    LoadingText(LoadingTextConfig config);
};
