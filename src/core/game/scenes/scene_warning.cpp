#include "scene_warning.hpp"

namespace Engine::Game::Scenes
{
    void SceneWarning::onLoad(SDL_Renderer* renderer)
    {
        // Save the renderer refference for later use
        ren = renderer;

        // Text alpha
        textAlpha = 0;
        textAlphaSpeed = 1.0 / 1.0;
        waitTimer = 1.5;

        // Text rectangle
        textRect = {
            SCREEN_WIDTH  * 1 / 4, 
            SCREEN_HEIGHT * 3 / 8, 
            SCREEN_WIDTH  * 1 / 2, 
            SCREEN_HEIGHT * 1 / 4 
        };
        warningSprite.updateRect(&textRect);

        // Sprite alpha set to 0
        warningSprite.setAlpha(0);
    }

    void SceneWarning::goToMenu()
    {
        // Create menu scene in memory and remove this one
        SceneMenu* newScene = new SceneMenu();
        newScene -> changeManager(man);
        parent -> push(newScene, ren);
        parent -> pop();
    }

    void SceneWarning::update(double dt)
    {
        // TODO: make this better
        textRect.x = parent -> getWindow() -> getSize().first  * 1 / 4;
        textRect.y = parent -> getWindow() -> getSize().second  * 3 / 8;
        textRect.w = parent -> getWindow() -> getSize().first  * 1 / 2;
        textRect.h = parent -> getWindow() -> getSize().second  * 1 / 4;

        // Fade in
        if(textAlpha < 1 && waitTimer == 1.5)
        {
            textAlpha += dt * textAlphaSpeed;
            if(textAlpha > 1) textAlpha = 1;
        }
        // Wait a bit
        else if(textAlpha == 1 && waitTimer > 0)
        {
            waitTimer -= dt;
        }
        // Fade out
        else
        {
            textAlpha -= dt * textAlphaSpeed;
            if(textAlpha < 0)
            {
                textAlpha = 0;

                // Switch to the menu scene
                goToMenu();
            }
             
        }

        // Update text alpha
        warningSprite.setAlpha(255 * textAlpha);
    }

    void SceneWarning::draw()
    {
        // Get the text image pointer
        // (don't force the conversion in real scenarios, it is going to fail if assets are not present)
        textImage = (Assets::ImageAsset*) man -> getAsset("text_warning");

        // Check if the pointer exists so no crashes occur
        if(textImage != NULL)
        {
            // Do the text drawing
            warningSprite.setSprite(textImage);
            warningSprite.draw(ren);
        }
    }
};