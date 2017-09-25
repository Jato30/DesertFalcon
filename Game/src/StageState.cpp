#include "StageState.hpp"

StageState::StageState() : State(), bg("./resources/img/ocean.jpg"){

    quitRequested = false;
}

StageState::~StageState(){
    objectArray.clear();
}

void StageState::Update(float dt){
    UpdateArray(dt);

    if(QuitRequested() || InputManager::GetInstance().QuitRequested()){
        quitRequested = true;
    }

    if(ActionManager::EscapeAction()){
        popRequested = true;
    }
}

void StageState::Render(void) const {
    bg.Render(Rect(0, 0, bg.GetWidth(), bg.GetHeight()));
}

void StageState::LoadAssets(void) const{
    Resources::GetImage("./resources/img/ocean.jpg");
}

void StageState::Pause(){

}

void StageState::Resume(){
    
}