#pragma once

#include <libStorm.hpp>

#include "../nodes/MenuState/all.hpp"

class MenuState : public State
{
public:
    void on_init() override;
};
