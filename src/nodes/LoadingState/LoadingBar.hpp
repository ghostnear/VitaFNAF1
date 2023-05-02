#ifndef LIBSTORM_EXAMPLE_LOADING_BAR_HPP
#define LIBSTORM_EXAMPLE_LOADING_BAR_HPP

#include <libStorm.hpp>

struct LoadingBarConfig
{
    double padding = 0.05;
    SDL_Color primary = {.r = 0x99, .g = 0x99, .b = 0xFF};
    SDL_Color secondary = {.r = 0x33, .g = 0x33, .b = 0x33};
};

class LoadingBar : public Storm::Node
{
public:
    // Constructor
    LoadingBar(LoadingBarConfig config);
};

#endif