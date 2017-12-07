#include "EndState.hpp"

EndState::EndState(int newScore) : State(), bg("./resources/img/endscreen.gif"),
    scoreList("./resources/font/Call me maybe.ttf", 16, Text::TextStyle::BLENDED, std::to_string(newScore), ColorName::WHITE, new Timer()),
    title("./resources/font/Call me maybe.ttf", 48, Text::TextStyle::BLENDED, "Score", ColorName::WHITE, new Timer()){

    scoreList.SetPos(400, 280, true);
    title.SetPos(400, 120, true);
}

EndState::~EndState(){
    
}

void EndState::Update(float dt){
    if(QuitRequested() || InputManager::GetInstance().QuitRequested()){
        quitRequested = true;
    }

    if(ActionManager::EscapeAction()){
        popRequested = true;
        TitleState* titleState = new TitleState();
        Game::GetInstance().Push(titleState);
    }
}

void EndState::Render(void) const{
    Vec2 windowPos = Window::GetInstance().GetWindowDimensions();
    bg.Render(Rect(0, 0, windowPos.x, windowPos.y));
    title.Render();
    scoreList.Render();
}

void EndState::Pause(void){

}

void EndState::Resume(void){

}

void EndState::LoadAssets(void) const{
    Resources::GetImage("./resources/img/endscreen.gif");
    Resources::GetFont("./resources/font/Call me maybe.ttf", 16);
    Resources::GetFont("./resources/font/Call me maybe.ttf", 48);
}