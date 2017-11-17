#include "InputManager.hpp"

InputManager::InputManager(){
    for(int i = 0; i < 6; i++){
        mouseState[i] = false;
        mouseUpdate[i] = 0;
    }
    quitRequested = false;
    updateCounter = 0;
}

InputManager::~InputManager(){

}

InputManager& InputManager::GetInstance(){
    static InputManager input = InputManager();
    return input;
}

void InputManager::Update(){
    SDL_Event event;
    
    // Obter as coordenadas do mouse
    SDL_GetMouseState(&mouseX, &mouseY);

    quitRequested = false;
    updateCounter++;

    // SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
    while(SDL_PollEvent(&event)){
        switch(event.type){
            // Clique no X, Alt+F4, etc.
            case SDL_QUIT: case ESC_KEY:
                quitRequested = true;
                break;

            // Botões do mouse pressionados
            case SDL_MOUSEBUTTONDOWN:
                // Botões do mouse
                switch(event.button.button){
                    // Botão esquerdo [1]
                    case LEFT_MOUSE_BUTTON:
                        mouseState[LEFT_MOUSE_BUTTON] = true;
                        mouseUpdate[LEFT_MOUSE_BUTTON] = updateCounter;
                        break;

                    // Botão direito [3]
                    case RIGHT_MOUSE_BUTTON:
                        mouseState[RIGHT_MOUSE_BUTTON] = true;
                        mouseUpdate[RIGHT_MOUSE_BUTTON] = updateCounter;
                        break;
                    // ACRESCENTAR OUTROS BOTÕES DO MOUSE
                }
                break;

            // Botões do mouse soltos
            case SDL_MOUSEBUTTONUP:
                // Release de um botão específico do mouse
                switch(event.button.button){
                    // Botão esquerdo [1]
                    case LEFT_MOUSE_BUTTON:
                        mouseState[LEFT_MOUSE_BUTTON] = false;
                        mouseUpdate[LEFT_MOUSE_BUTTON] = updateCounter;
                        break;

                    // Botão direito [3]
                    case RIGHT_MOUSE_BUTTON:
                        mouseState[RIGHT_MOUSE_BUTTON] = false;
                        mouseUpdate[RIGHT_MOUSE_BUTTON] = updateCounter;
                        break;
                }
                break;

            // Tecla pressionada
            case SDL_KEYDOWN:
                // Impede de registrar mais de 1 down sem ocorrer o up
                if(event.key.repeat == 1){
                    continue;
                }

                // Se ESC for pressionado
                if(event.key.keysym.sym == ESCAPE_KEY){
                    // PAUSAR
                }

                // Qual tecla foi pressionada
                keyState[event.key.keysym.sym] = true;
                keyUpdate[event.key.keysym.sym] = updateCounter;
                break;

            // Release de uma tecla
            case SDL_KEYUP:
                keyState[event.key.keysym.sym] = false;
                keyUpdate[event.key.keysym.sym] = updateCounter;
                break;
        }
    }
}

bool InputManager::KeyPress(int key){
    return keyUpdate[key] == updateCounter ? keyState[key] : false; 
}

bool InputManager::KeyRelease(int key){
    return keyUpdate[key] == updateCounter ? !keyState[key] : false; 
}

bool InputManager::IsKeyDown(int key){
    return keyState[key]; 
}

bool InputManager::MousePress(int button){
    return mouseUpdate[button] == updateCounter ? mouseState[button] : false;
}

bool InputManager::MouseRelease(int button){
    return mouseUpdate[button] == updateCounter ? !mouseState[button] : false;
}

bool InputManager::IsMouseDown(int button){
    return mouseState[button];
}

int InputManager::GetMouseX(){
    return mouseX;
}

int InputManager::GetMouseY(){
    return mouseY;
}

bool InputManager::QuitRequested(){
    return quitRequested;
}