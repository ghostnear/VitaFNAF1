#ifndef LIBSTORM_EXAMPLE_SCROLLING_RECTANGLES_HPP
#define LIBSTORM_EXAMPLE_SCROLLING_RECTANGLES_HPP

#include <libStorm.hpp>

struct ScrollingRectanglesConfig
{
    double size = 60;
    double speed = 60;
    SDL_Color primary = {.r = 50, .g = 100, .b = 200};
    SDL_Color secondary = {.r = 50, .g = 50, .b = 160};
};

class ScrollingRectangles : public Storm::Node
{
public:
    // Constructor
    ScrollingRectangles(ScrollingRectanglesConfig config);
};

#endif
