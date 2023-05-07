#pragma once

#include <libStorm.hpp>

#include "../nodes/WarningState/all.hpp"

class WarningState : public Storm::State
{
public:
    void on_init() override;
    void on_destroy() override;
    void draw() override;
    void update(double dt) override;
};
