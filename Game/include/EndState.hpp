#ifndef __ENDSTATE_HPP__
#define __ENDSTATE_HPP__

class EndState;

#include "Sprite.hpp"
#include "Text.hpp"
#include "State.hpp"

class EndState : public State{
    private:
        Sprite bg;
        Text scoreList;
        Text title;
    
    public:
        EndState(int newScore);
        ~EndState();
        void Update(float);
        void Render(void) const;
        void Pause(void);
        void Resume(void);
        void LoadAssets(void) const;
};

#include "ActionManager.hpp"
#include "InputManager.hpp"
#include "Resources.hpp"
#include "Game.hpp"
#include "Window.hpp"
#include "TitleState.hpp"
#include "Timer.hpp"
#include <cstdio>

#endif // __ENDSTATE_HPP__