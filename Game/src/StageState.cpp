#include "StageState.hpp"

StageState::StageState() : State()/*, bg("./resources/img/ocean.jpg")*/, newHiero(){
    AddObject(new Falcon(PLAYER_BASE_LIFE));
    quitRequested = false;
    Score::CreateInstance();
}

StageState::~StageState(){
    objectArray.clear();
    Score::DeleteInstance();
}

void StageState::Update(float dt){
    UpdateArray(dt);
    Score::Update(dt);
    
    // Novo Hiero
    newHiero.Update(dt);
    if(newHiero.Get() > HIERO_COOLDOWN){
        AddObject(new Hiero(Vec2(Window::GetInstance().GetWindowDimensions().x, rand() % (int) Window::GetInstance().GetWindowDimensions().y)));
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
    Vec2 windowPos = Window::GetInstance().GetWindowDimensions();
    bg.Render(Rect(0, 0, windowPos.x, windowPos.y));
    Score::Render();

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