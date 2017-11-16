#include "StageState.hpp"

StageState::StageState() : State(), bg("./resources/img/paisagem-do-deserto.jpg"), newHiero(){
    AddObject(new Falcon(PLAYER_BASE_LIFE));
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
        // Escolhe uma reta aleatória entre (x: meia tela ~ tela, y: 0 ~ 0) e (x: tela ~ tela, y: 0 ~ meia tela)
        Vec2 randLine;
        randLine = rand() % 2 == 0 ? Vec2((Window::GetInstance().GetWindowDimensions().x / 2), 0) : Vec2(Window::GetInstance().GetWindowDimensions().x, (Window::GetInstance().GetWindowDimensions().y / 2));
        // Escolhe um ponto aleatório entre a reta escolhida
        Vec2 hieroPos((rand() % ((int) (Window::GetInstance().GetWindowDimensions().x - randLine.x) + 1)) + randLine.x, rand() % ((int) randLine.y + 1));
        AddObject(new Hiero(hieroPos));
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

    RenderArray();
}

void StageState::LoadAssets(void) const{
    Resources::GetImage("./resources/img/paisagem-do-deserto.jpg");
    Resources::GetImage("./resources/img/hiero.png");
}

void StageState::Pause(){

}

void StageState::Resume(){
    
}