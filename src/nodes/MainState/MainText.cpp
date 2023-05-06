#include "MainText.hpp"

using namespace Storm;

void main_text_update(Node* slf)
{
    auto boundaries = slf->get_component<Rect<double>>("boundaries");
    auto scaling = *(slf->get_component<double>("mainText_scaling"));
    Vec2<int> position = Window::get_size().multiply_by_components(*(slf->get_component<Vec2<double>>("mainText_padding")));
    boundaries->position.x = position.x;
    boundaries->position.y = position.y;

    Vec2<int> winSize = Window::get_size();
    auto ratio = 1.0 * winSize.x / winSize.y;
    
    if(winSize.x > winSize.y)
    {
        boundaries->size.x = winSize.x * scaling * ratio;
        boundaries->size.y = winSize.y * scaling;
    }
    else
    {
        boundaries->size.x = winSize.x * scaling;
        boundaries->size.y = winSize.y * scaling * ratio;
    }
}

MainText::MainText(MainTextConfig config) : TextNode(config.textCfg)
{
    // Set stuff to a desired value to make all look nice
    set_component<std::string>(
        "text",
        new std::string("FNAF1")
    );
    set_component<Vec2<double>>(
        "text_offset",
        new Vec2<double>{
            .x = 0.5,
            .y = 0.5
        }
    );

    // Init values
    set_component<double>(
        "mainText_scaling",
        new double(config.scale)
    );
    set_component<Vec2<double>>(
        "mainText_padding",
        new Vec2<double>(config.padding)
    );
    add_function(
        "update",
        main_text_update
    );
}