#pragma once

#include <libStorm.hpp>

#include "WarningState.hpp"
#include "../nodes/LoadingState/all.hpp"

class LoadingState : public State
{
public:
    void on_init() override;
    void update() override;
};
