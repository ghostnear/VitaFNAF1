#pragma once

#include <libStorm.hpp>

#include "MainState.hpp"

class LoadingState : public Storm::State
{
public:
    void on_init() override;
    void on_destroy() override;
    void draw() override;
    void update(double dt) override;
};
