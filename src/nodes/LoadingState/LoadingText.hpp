#pragma once

#include <prefabs/TextNode.hpp>

struct LoadingTextConfig
{
    Prefabs::TextNodeConfig textCFG = {
        .size = 32,
        .textOffset ={
            .y = 0.5
        },
        .boundaries = {
            .position = {
                .x = 40,
                .y = 500,
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
