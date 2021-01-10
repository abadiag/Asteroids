#pragma once
#include "GameObject.h"

class Player:GameObject
{
public:
    bool thrust;
    Player();
    void update();
};

