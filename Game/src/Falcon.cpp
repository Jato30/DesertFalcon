#include "Falcon.hpp"

Falcon::Falcon(Vec2 pos, int hitpoints) : GameObject()
          , sp("./resources/img/falcon.png")
          , hp(hitpoints)
          , speed(0., 0.) {

     rotation = 0;
     box = Vec2(pos.x, pos.y);
     box.SetWidthAndHeight(Vec2(sp.GetWidth(), sp.GetHeight()));
}

Falcon::~Falcon(){

}

void Falcon::Update(float dt){
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

void Falcon::Render(void){
     sp.Render(box);
}

bool Falcon::IsDead(void){
     return dead;
}

void Falcon::RequestDelete(void){
     dead = true;
}

void Falcon::NotifyCollision(GameObject& object){

}

bool Falcon::Is(string type){
     return "Falcon" == type;
}

Rect Falcon::GetWorldRenderedRect(void) const{
     return box;
}

