#include "TitleState.hpp"

TitleState::TitleState() : State(), bg("./resources/img/titlescreen.png"){
    pressSpace = new Text("./resources/font/Call me maybe.ttf", 36, Text::TextStyle::SOLID, "Press SPACE button to start", ColorName::WHITE, new Timer());
    pressSpace->SetPos(512, 500, true);
}

void TitleState::Update(float dt){
    dt = dt;
    if(QuitRequested() || InputManager::GetInstance().QuitRequested() || ActionManager::EscapeAction()){
        quitRequested = true;
    }

    pressSpace->Render();

    if(ActionManager::StartAction()){
        popRequested = true;
        StageState* stageState = new StageState();
        Game::GetInstance().Push(stageState);
    }
}

void TitleState::Render(void) const{
    bg.Render(Rect(0., 0., bg.GetHeight(), bg.GetWidth()));
}

void TitleState::LoadAssets(void) const{
    Resources::GetImage("./resources/img/titlescreen.png");
    Resources::GetFont("./resources/font/Call me maybe.ttf", 36);
}

void TitleState::Pause(void){

}

void TitleState::Resume(void){

}

