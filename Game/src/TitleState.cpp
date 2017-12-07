#include "TitleState.hpp"

TitleState::TitleState() : State(), bg("./resources/img/titlescreen.png"){
    Vec2 windowPos = Window::GetInstance().GetWindowDimensions();
    pressSpace = new Text("./resources/font/Call me maybe.ttf", 36, Text::TextStyle::BLENDED, "Press SPACE button to start", ColorName::WHITE, new Timer(), true);
    pressSpace->SetPos(windowPos.x / 2, windowPos.y / 2, true);
    bg.SetSize(windowPos);
}

void TitleState::Update(float dt){
    pressSpace->Update(dt);
    
    if(QuitRequested() || InputManager::GetInstance().QuitRequested() || ActionManager::EscapeAction()){
        quitRequested = true;
    }


    if(ActionManager::StartAction()){
        popRequested = true;
        StageState* stageState = new StageState();
        Game::GetInstance().Push(stageState);
    }
}

void TitleState::Render(void) const{
    bg.Render(Rect(0., 0., bg.GetHeight(), bg.GetWidth()));
    pressSpace->Render();
}

void TitleState::LoadAssets(void) const{
    Resources::GetImage("./resources/img/titlescreen.png");
    Resources::GetFont("./resources/font/Call me maybe.ttf", 36);
}

void TitleState::Pause(void){

}

void TitleState::Resume(void){

}

