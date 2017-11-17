#ifndef _INPUTMANAGER_HPP_
#define _INPUTMANAGER_HPP_

#include <unordered_map>

class InputManager{
    private:
        bool mouseState[6];
        int mouseUpdate[6];
        std::unordered_map<int, bool> keyState;
        std::unordered_map<int, int> keyUpdate;
        bool quitRequested;
        int updateCounter;
        int mouseX;
        int mouseY;

        InputManager();
        ~InputManager();

    public:
        void Update();
        bool KeyPress(int);
        bool KeyRelease(int);
        bool IsKeyDown(int);
        bool MousePress(int);
        bool MouseRelease(int);
        bool IsMouseDown(int);
        int GetMouseX();
        int GetMouseY();
        bool QuitRequested();
        static InputManager& GetInstance();
};

#ifdef _WIN32
    // windows
    #include "SDL.h"
    #include "SDL_image.h"
#elif __APPLE__
  //  #include "TargetConditionals.h"
    // mac
#elif __linux__
    // linux
    #include<SDL2/SDL.h>
    #include<SDL2/SDL_image.h>
#else
    #error "Unknown compiler"
#endif

// Define para GetInstance() já que será muito usado
#define INPUT_M InputManager::GetInstance()

#define LEFT_ARROW_KEY SDLK_LEFT
#define RIGHT_ARROW_KEY SDLK_RIGHT
#define UP_ARROW_KEY SDLK_UP
#define DOWN_ARROW_KEY SDLK_DOWN
#define ESCAPE_KEY SDLK_ESCAPE
#define LEFT_MOUSE_BUTTON SDL_BUTTON_LEFT // [1]
#define RIGHT_MOUSE_BUTTON SDL_BUTTON_RIGHT // [3]
#define A_KEY SDLK_a
#define W_KEY SDLK_w
#define D_KEY SDLK_d
#define S_KEY SDLK_s
#define Q_KEY SDLK_q
#define E_KEY SDLK_e
#define Y_KEY SDLK_y
#define SPACE_KEY SDLK_SPACE
#define ESC_KEY 27

#endif // _INPUTMANAGER_HPP_