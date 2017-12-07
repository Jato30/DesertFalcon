#include "ActionManager.hpp"

#define INPUT_INSTANCE InputManager::GetInstance()


bool ActionManager::LeftArrowAction(){

	return (INPUT_INSTANCE.IsKeyDown('a') 
		 || INPUT_INSTANCE.IsKeyDown('A') 
		 || INPUT_INSTANCE.IsKeyDown(SDLK_LEFT) );

}

bool ActionManager::RightArrowAction(){

	return (INPUT_INSTANCE.IsKeyDown('d') 
		 || INPUT_INSTANCE.IsKeyDown('D') 
		 || INPUT_INSTANCE.IsKeyDown(SDLK_RIGHT) );

}

bool ActionManager::UpArrowAction(){

	return (INPUT_INSTANCE.IsKeyDown('w') 
		 || INPUT_INSTANCE.IsKeyDown('W') 
		 || INPUT_INSTANCE.IsKeyDown(SDLK_UP) );

}

bool ActionManager::DownArrowAction(){

	return (INPUT_INSTANCE.IsKeyDown('s') 
		 || INPUT_INSTANCE.IsKeyDown('S') 
		 || INPUT_INSTANCE.IsKeyDown(SDLK_DOWN) );

}

bool ActionManager::EscapeAction(){

	return INPUT_INSTANCE.IsKeyDown(SDLK_ESCAPE);

}

bool ActionManager::StartAction(){

	return INPUT_INSTANCE.IsKeyDown(SDLK_SPACE);

}

bool ActionManager::EnterKeyAction(){

	return (INPUT_INSTANCE.IsKeyDown(SDLK_RETURN) 
		 || INPUT_INSTANCE.IsKeyDown(SDLK_KP_ENTER) );

}

