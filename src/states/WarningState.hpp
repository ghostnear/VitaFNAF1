#pragma once

#include <libStorm.hpp>

#include "MenuState.hpp"
#include "../nodes/WarningState/all.hpp"

class WarningState : public State
{
public:
    void on_init() override;
    void update() override;
};
