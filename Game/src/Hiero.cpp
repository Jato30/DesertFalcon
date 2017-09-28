#include "Hiero.hpp"

Hiero::Hiero(Vec2 pos) : GameObject()
          , sp("./resources/img/hiero.png")
          , speed(Vec2(0, 0) ){

     rotation = 0;
     box = Vec2(pos.x, pos.y);
     box.SetWidthAndHeight(Vec2(sp.GetWidth(), sp.GetHeight()));
}

Hiero::~Hiero(){

}

void Hiero::Update(float dt){
     sp.Update(dt);

     // Movimento
     if(ActionManager::LeftArrowAction()){
          speed.x -= LINEAR_SPEED * dt;
     }
     if(ActionManager::RightArrowAction()){
          speed.x += LINEAR_SPEED * dt;
     }
     if(ActionManager::UpArrowAction()){
          speed.y -= LINEAR_SPEED * dt;
     }
     if(ActionManager::DownArrowAction()){
          speed.y += LINEAR_SPEED * dt;
     }

     box.x += speed.x;
     box.y += speed.y;
     speed = 0;
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