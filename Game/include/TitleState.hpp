#ifndef __TITLESTATE_HPP__
#define __TITLESTATE_HPP__

#include "State.hpp"
#include "Sprite.hpp"
#include "Text.hpp"

class TitleState : public State{
    private:
        Sprite bg;
        Text* pressSpace;
        Timer textTime;

    public:
        TitleState(void);
        void Update(float);
        void Render(void) const;
        void LoadAssets(void) const;
        void Pause(void);
        void Resume(void);
};

#include "ActionManager.hpp"
#include "Game.hpp"
#include "StageState.hpp"
#include "Timer.hpp"
#include "Rect.hpp"
#include "Color.hpp"
#include "Window.hpp"

#endif // __TITLESTATE_HPP__