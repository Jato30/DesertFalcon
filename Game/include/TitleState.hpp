#ifndef __TITLESTATE_HPP__
#define __TITLESTATE_HPP__

class TitleState;

#include "State.hpp"
#include "Sprite.hpp"

class TitleState : public State{
    private:
        Sprite bg;
        Text* pressSpace;
        Timer textTime;

    public:
        TitleState();
        void Update(float);
        void Render();
        void LoadAssets();
        void Pause();
        void Resume();
};

#include "InputManager.hpp"
#include "Game.hpp"
#include "StageState.hpp"
#include "Timer.hpp"

#endif // __TITLESTATE_HPP__