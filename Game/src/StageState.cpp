#include "StageState.hpp"

StageState::StageState() : State(), bg("./resources/img/ocean.jpg"), newHiero(){
    quitRequested = false;
}

StageState::~StageState(){
    objectArray.clear();
}

void StageState::Update(float dt){
    UpdateArray(dt);
    
    newHiero.Update(dt);
    if(newHiero.Get() > 10){
        AddObject(new Hiero(Vec2(rand() % (int) Game::GetInstance().GetWindowDimensions().x, rand() % (int) Game::GetInstance().GetWindowDimensions().y)));
        newHiero.Restart();
    }


    if(QuitRequested() || InputManager::GetInstance().QuitRequested()){
        quitRequested = true;
    }
    
    if(ActionManager::EscapeAction()){
        popRequested = true;
    }
}

void StageState::Render(void) const {
    bg.Render(Rect(0, 0, bg.GetWidth(), bg.GetHeight()));

    RenderArray();
}

void StageState::LoadAssets(void) const{
    Resources::GetImage("./resources/img/ocean.jpg");
    Resources::GetImage("./resources/img/hiero.png");
}

void StageState::Pause(){

}

void StageState::Resume(){
    
}