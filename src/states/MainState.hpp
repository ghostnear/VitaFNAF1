#ifndef GAME_MAINSTATE_HPP
#define GAME_MAINSTATE_HPP

#include <libStorm.hpp>

#include "../nodes/MainState/all.hpp"

class MainState : public Storm::State
{
public:
    void on_init() override;
    void on_destroy() override;
    void draw() override;
    void update(double dt) override;
};

#endif
