#include "FPSText.hpp"

using namespace Storm;

void fps_text_update(Node* slf)
{
    auto updateTimer = slf->get_component<double>("update_timer");
    auto updateFreq = *(slf->get_component<double>("update_freq"));
    *updateTimer += GameManager::get_delta_time();
    if(*updateTimer > updateFreq)
    {
        // Update text and frame count
        auto text = slf->get_component<std::string>("text");
        auto frameCount = slf->get_component<size_t>("frame_count");
        *text = Utils::to_string<size_t>(*frameCount) + " fps";
        *frameCount = 0;

        // Force the redrawing
        FPSText::redraw_text_node(slf);

        // Clear the timings
        while(*updateTimer >= updateFreq)
            *updateTimer = *updateTimer - updateFreq;
    }
}

void fps_text_draw(Node* slf)
{
    auto frameCount = slf->get_component<size_t>("frame_count");
    *frameCount = *frameCount + 1;
    FPSText::text_node_draw(slf);
}

FPSText::FPSText(FPSTextConfig config) : TextNode(config.textCfg)
{
    add_component<size_t>(
        "frame_count",
        new size_t(0)
    );
    add_component<double>(
        "update_timer",
        new double(0)
    );
    add_component<double>(
        "update_freq",
        new double(config.updateRate)
    );
    add_function(
        "draw",
        fps_text_draw
    );
    add_function(
        "update",
        fps_text_update
    );
}