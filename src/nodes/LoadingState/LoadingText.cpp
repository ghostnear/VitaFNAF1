#include "LoadingText.hpp"

void LoadingText::update_loading_text(Node* slf)
{
    // Check if font was loaded, and if so, set the loading text font to it.
    auto loadingFont = AssetManager::get_asset<FontAsset>("font_pixel");
    
    if(loadingFont != nullptr)
    {
        slf->set_component<FontAsset>(
            "text_font",
            loadingFont
        );
    }
}

LoadingText::LoadingText(LoadingTextConfig config) : TextNode(config.textCFG)
{
    add_function(
        "update",
        LoadingText::update_loading_text
    );
}