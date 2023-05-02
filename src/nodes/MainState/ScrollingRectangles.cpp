#include "ScrollingRectangles.hpp"

using namespace Storm;

#define renderer Graphics::get_SDL()

void rectangle_draw(Node* slf)
{
    auto primary_color = *(slf->get_component<SDL_Color>("primary_color"));
    auto secondary_color = *(slf->get_component<SDL_Color>("secondary_color"));
    auto offset = *(slf->get_component<double>("offset"));
    auto size = *(slf->get_component<double>("size"));
    auto w_size = Window::get_size();
    for(size_t i = 0; i <= size_t(w_size.x / size) + 1; i++)
        for(size_t j = 0; j <= size_t(w_size.y / size) + 1; j++)
        {
            Graphics::set_color((i + j) % 2 ? primary_color : secondary_color);
            SDL_Rect r = {
                .x = int(i * size + offset),
                .y = int(j * size + offset),
                .w = int(size),
                .h = int(size)
            };
            SDL_RenderFillRect(renderer, &r);
        }
}

void rectangle_change_offset(Node* slf)
{
    auto offset = slf->get_component<double>("offset");
    auto size = *(slf->get_component<double>("size"));
    auto speed = *(slf->get_component<double>("speed"));
    *offset = *offset - GameManager::get_delta_time() * speed;
    while(*offset <= -size)
        *offset = *offset + size;
}

ScrollingRectangles::ScrollingRectangles(ScrollingRectanglesConfig config)
{
    add_component<double>(
        "offset",
        new double(0)
    );
    add_component<double>(
        "speed",
        new double(config.speed)
    );
    add_component<double>(
        "size",
        new double(config.size)
    );
    add_component<SDL_Color>(
        "primary_color",
        new SDL_Color(config.primary)
    );
    add_component<SDL_Color>(
        "secondary_color",
        new SDL_Color(config.secondary)
    );
    add_function(
        "draw",
        rectangle_draw
    );
    add_function(
        "update",
        rectangle_change_offset
    );
}

#undef window
