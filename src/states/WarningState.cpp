#include "WarningState.hpp"

using namespace Storm;

void WarningState::on_init()
{
    root->add_child(new WarningSprite({}), "warning_sprite");
}

void WarningState::draw()
{
    Graphics::clear(0, 0, 0);

    // Draw scene
    root->execute_all("draw");

    Graphics::update();
}

void WarningState::update(double dt)
{
    // Press escape to close window
#ifndef VITA
    if(Input::isKeyReleased(SDLK_ESCAPE))
        Window::close();
#endif

    // Press enter to skip to next scene.
#ifndef VITA
    if(Input::isKeyReleased(SDLK_RETURN))
    {
        GameManager::pop_state();
        GameManager::push_state(new MenuState());
    }
#endif

    // Check if transition is over to move to next scene.
    auto warningSprite = root->get_child("warning_sprite");
    if(*warningSprite->get_component<double>("sprite_alpha") <= 0)
    {
        GameManager::pop_state();
        GameManager::push_state(new MenuState());
    }

    // Update scene
    root->execute_all("update");
}
