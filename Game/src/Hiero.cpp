#include "Hiero.hpp"

Hiero::Hiero(Vec2 pos) : GameObject(), sp("./resources/img/hiero.png") {
     box = Vec2(pos.x, pos.y);
     box.SetWidthAndHeight(Vec2(sp.GetWidth(), sp.GetHeight()));
}

Hiero::~Hiero(){

}

void Hiero::Update(float dt){
     
}

void Hiero::Render(void){
     sp.Render(box, rotation);
}

bool Hiero::IsDead(void){
     return dead;
}

void Hiero::RequestDelete(void){
     dead = true;
}

void Hiero::NotifyCollision(GameObject){

}

bool Hiero::Is(string type){
     return "Hiero" == type;
}

Rect Hiero::GetWorldRenderedRect(void) const{
     return box;
}