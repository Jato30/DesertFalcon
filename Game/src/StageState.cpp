#include "StageState.hpp"

StageState::StageState() : State(), bg("./resources/img/ocean.jpg"){
    AddObject(new Hiero(Game::GetInstance().GetWindowDimensions() / 2));
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


    // if(INPUT_MANAGER.IsKeyDown('[')){
	// 	Resources::ChangeMusicVolume(-STAGE_STATE_DELTA_VOLUME);
	// }
	// if(INPUT_MANAGER.IsKeyDown(']')){
	// 	Resources::ChangeMusicVolume(STAGE_STATE_DELTA_VOLUME);
	// }
	// if(INPUT_MANAGER.IsKeyDown(',')){
	// 	Resources::ChangeSoundVolume(-STAGE_STATE_DELTA_VOLUME);
	// }
	// if(INPUT_MANAGER.IsKeyDown('.')){
	// 	Resources::ChangeSoundVolume(STAGE_STATE_DELTA_VOLUME);
	// }
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