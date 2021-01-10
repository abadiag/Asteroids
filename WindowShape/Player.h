#pragma once
#include "GameObject.h"

class Player: public GameObject
{
public:
    bool thrust;
    Player();
    void InputKeyb(Actions* a);
    void update();
};

