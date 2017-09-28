#include "StageState.hpp"

StageState::StageState() : State()/*, bg("./resources/img/ocean.jpg")*/, newHiero(){
    Vec2 center(Window::GetInstance().GetWindowDimensions() / 2);
    AddObject(new Falcon(Vec2(0., center.y), PLAYER_LIFE));
    AddObject(new Hiero(center));
    quitRequested = false;
}

StageState::~StageState(){
    objectArray.clear();
}

void StageState::Update(float dt){
    UpdateArray(dt);
    
    // Novo Hiero
    newHiero.Update(dt);
    if(newHiero.Get() > HIERO_COOLDOWN){
        AddObject(new Hiero(Vec2(rand() % (int) Window::GetInstance().GetWindowDimensions().x, rand() % (int) Window::GetInstance().GetWindowDimensions().y)));
        newHiero.Restart();
    }

    // Confere colisão entre GOs
    if(!objectArray.empty()){
		for(uint count1 = 0; count1 < objectArray.size() - 1; count1++) {
			for(uint count2 = count1 + 1; count2 < objectArray.size(); count2++) {
				if(Collision::IsColliding(objectArray[count1]->box, objectArray[count2]->box, objectArray[count1]->rotation, objectArray[count2]->rotation)) {
					objectArray[count1]->NotifyCollision(*objectArray[count2]);
					objectArray[count2]->NotifyCollision(*objectArray[count1]);
				}
			}
		}
    }
    

    if(QuitRequested() || InputManager::GetInstance().QuitRequested()){
        quitRequested = true;
    }
    
    if(ActionManager::EscapeAction()){
        popRequested = true;
    }
}

void StageState::Render(void) const {
    // bg.Render(Rect(0, 0, bg.GetWidth(), bg.GetHeight()));

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