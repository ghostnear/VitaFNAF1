#ifndef GAME_LOADINGSTATE_HPP
#define GAME_LOADINGSTATE_HPP

#include <libStorm.hpp>

#include "MainState.hpp"
#include "../nodes/LoadingState/all.hpp"

class LoadingState : public Storm::State
{
public:
    void on_init() override;
    void on_destroy() override;
    void draw() override;
    void update(double dt) override;
};

#endif