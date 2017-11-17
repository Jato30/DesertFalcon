#include "Hiero.hpp"

Hiero::Hiero(Vec2 pos) : GameObject(), sp("./resources/img/hiero.png"), speed(0., 0.) {
     rotation = -38.264;
     box = Vec2(pos.x, pos.y);
     box.SetWidthAndHeight(Vec2(sp.GetWidth(), sp.GetHeight()));
}

Hiero::~Hiero(){
     
}

void Hiero::Update(float dt){
     sp.Update(dt);

     // Movimento
     speed.x = -LINEAR_SPEED * FALCON_SPEED_PROPORTION_X * dt;
     speed.y = LINEAR_SPEED * FALCON_SPEED_PROPORTION_Y * dt;
     box = box + speed;

     // Out of bounds
     if((box.x < 0) || ((box.y + box.h) > Window::GetInstance().GetWindowDimensions().y) ){
          RequestDelete();
     }
}

void Hiero::Render(void){
     sp.Render(box);
}

bool Hiero::IsDead(void){
     return dead;
}

void Hiero::RequestDelete(void){
     dead = true;
}

void Hiero::NotifyCollision(GameObject& object){
     if(object.Is("Falcon")){
          RequestDelete();
	}
}

bool Hiero::Is(string type){
     return "Hiero" == type;
}

Rect Hiero::GetWorldRenderedRect(void) const{
     return box;
}

