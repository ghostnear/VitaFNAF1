#pragma once

#include <libStorm.hpp>

#include "MainState.hpp"

class WarningState : public Storm::State
{
public:
    void on_init() override;
    void on_destroy() override;
    void draw() override;
    void update(double dt) override;
};
