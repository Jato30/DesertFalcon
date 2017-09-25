#include "InputManager.hpp"
#include <string>
#include "Error.hpp"

InputManager::InputManager() : quitRequested(false), updateCounter(0), mouseX(0), mouseY(0), mouseScroolUpdate(0) {
	memset(mouseState, 0, 6*sizeof(bool));
	memset(mouseUpdate, 0, 6*sizeof(int));
}

InputManager::~InputManager() {
}

InputManager& InputManager::GetInstance(void) {
	static InputManager inputManager;
	return inputManager;
}

void InputManager::Update(){
	SDL_Event event;
	updateCounter ++;
	quitRequested = false;
	// Obtenha as coordenadas do mouse
	SDL_GetMouseState(&mouseX, &mouseY);
	// SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
	while (SDL_PollEvent(&event)){
		// Se o evento for quit, setar a flag para terminação
		if( SDL_QUIT == event.type){
			quitRequested = true;
		}
		// Se o evento for clique...
		else if(SDL_MOUSEBUTTONDOWN == event.type){
			mouseState[event.button.button] = true;
			mouseUpdate[event.button.button] = updateCounter;
			
		}
		else if(SDL_MOUSEBUTTONUP == event.type ) {
			
			mouseState[event.button.button] = false;
			mouseUpdate[event.button.button] = updateCounter;
		}
		else if(SDL_MOUSEWHEEL == event.type){
			mouseScroolState= Vec2(event.wheel.x, event.wheel.y);
			mouseScroolUpdate= updateCounter;
		}
		else if(SDL_KEYDOWN == event.type){
			if(!event.key.repeat){
				keyState[event.key.keysym.sym] = true;
				keyUpdate[event.key.keysym.sym] = updateCounter;
			}
		}
		else if(SDL_KEYUP == event.type ){
			keyState[event.key.keysym.sym] = false;
			keyUpdate[event.key.keysym.sym] = updateCounter;
		}
	}
}

bool InputManager::KeyPress(int key) const{
	try{
		return(keyUpdate.at(key) == updateCounter && keyState.at(key));
	}
	catch (const std::out_of_range& oor){
		return false;
	}
}

bool InputManager::KeyRelease(int key) const{
	try{
		return(keyUpdate.at(key) != updateCounter && !keyState.at(key));
	}
	catch (const std::out_of_range& oor){
		return false;
	}
}

bool InputManager::IsKeyDown(int key) const{
	try{
		return(keyState.at(key) == true);
	}
	catch (const std::out_of_range& oor){
		return false;
	}
}

bool InputManager::IsKeyUp(int key) const{
	try{
		return(keyState.at(key) == false);
	}
	catch (const std::out_of_range& oor){
		return false;
	}
}

bool InputManager::MousePress(int button) const{
	return (mouseUpdate[button] == updateCounter && mouseState[button]);
}

bool InputManager::MouseRelease(int button) const{
	return (mouseUpdate[button] == updateCounter && !mouseState[button]);
}

bool InputManager::IsMouseDown(int button) const{
	return (true == mouseState[button] );
}

bool InputManager::IsMouseUp(int button) const{
	return (false == mouseState[button] );
}

int InputManager::GetMouseX() const{
	return(mouseX);
}

int InputManager::GetMouseY() const{
	return(mouseY);
}

bool InputManager::QuitRequested() const{
	return(quitRequested);
}

Vec2 InputManager::GetMousePos() const{
	return Vec2(mouseX, mouseY);
}

Vec2 InputManager::MouseScroll(void) const{
	return mouseScroolState;
}

bool InputManager::IsMouseScrolling(void) const{
	return (mouseScroolUpdate == updateCounter);
}
