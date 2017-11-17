#include "Score.hpp"

using std::string;

Score* Score::score = nullptr;

Score::Score() : totalScore(0), isToShow(true) {
     Vec2 windowSize (Window::GetInstance().GetWindowDimensions());
     text = new Text("./resources/font/Call me maybe.ttf", 26, Text::TextStyle::BLENDED, "", ColorName::BLACK, new Timer());
     text->SetPos(windowSize.x - 150, windowSize.y - 100);
}

Score::~Score(){
     delete text;
}

void Score::DeleteInstance(){
     score->~Score();
}

void Score::CreateInstance(void){
     if(score != nullptr){
          Error("Second instantion of score!");
     }
     score = new Score();
}

void Score::Update(float dt){
     score->text->SetText(string("Score  ") + std::to_string(score->totalScore));
     score->text->Update(dt);
}

void Score::Render(void){
     score->text->Render();
}

void Score::SetScore(int value){
     score->totalScore = value;
}

int Score::GetScore(void){
     return score->totalScore;
}

void Score::Increase(int value){
     score->totalScore += value;
}

void Score::Decrease(int value){
     score->totalScore -= value;
}

void Score::Show(void){
     score->isToShow = true;
}

void Score::Hide(void){
     score->isToShow = false;
}

