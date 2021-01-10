#pragma once
#include "GameObject.h"

class Player: public GameObject
{
public:
    bool thrust;
    Player();
    void update();
};

