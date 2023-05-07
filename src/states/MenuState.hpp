#pragma once

#include <libStorm.hpp>

class MenuState : public State
{
public:
    void on_init() override;
    void draw() override;
    void update(double dt) override;
};
