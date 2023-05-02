#include "LoadingBar.hpp"

using namespace Storm;

#define renderer Graphics::get_SDL()

void loading_bar_draw(Node* slf)
{
    auto primary_color = *(slf->get_component<SDL_Color>("primary_color"));
    auto secondary_color = *(slf->get_component<SDL_Color>("secondary_color"));
    auto padding = *(slf->get_component<double>("padding"));
    auto w_size = Window::get_size();
    
    Graphics::set_color(secondary_color);
    // TODO: stop using the stack
    SDL_Rect r = {
        .x = int(padding * w_size.x),
        .y = int((1 - 3 * padding) * w_size.y),
        .w = int(w_size.x * (1 - 2 * padding)),
        .h = int(std::min(w_size.x, w_size.y) * padding)
    };
    SDL_RenderFillRect(renderer, &r);

    Graphics::set_color(primary_color);
    r.w = int(w_size.x * (1 - 2 * padding) * AssetLoader::get_percentage());
    SDL_RenderFillRect(renderer, &r);
}

LoadingBar::LoadingBar(LoadingBarConfig config)
{
    add_component<double>(
        "padding",
        new double(config.padding)
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
        loading_bar_draw
    );
}

#undef renderer