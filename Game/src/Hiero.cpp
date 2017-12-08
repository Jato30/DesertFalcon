#include "Hiero.hpp"

Hiero::Hiero(Vec2 pos) : GameObject(), sp("./resources/img/hiero.png"), speed(0., 0.) {
     rotation = -38.264;
     box.SetWidthAndHeight(Vec2(sp.GetWidth(), sp.GetHeight()));
     box = Vec2(pos.x, pos.y - box.h);
}

Hiero::~Hiero(){
     
}

void Hiero::Update(float dt){
     sp.Update(dt);

     // Movimento
     if(GlobalVars::SET_ALL_SPEED){
          speed.x = -LINEAR_SPEED * FALCON_SPEED_PROPORTION_X * 0.9 * dt;
          speed.y = LINEAR_SPEED * FALCON_SPEED_PROPORTION_Y * 0.9 * dt;
     }
     box = box + speed;
     speed = 0;

     // Out of bounds
     if(((box.x + box.w) < 0) || (box.y > Window::GetInstance().GetWindowDimensions().y) ){
          RequestDelete();
     }
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

void Hiero::NotifyCollision(GameObject& object){
     if(object.Is("Falcon")){
          RequestDelete();
	}
}

bool Hiero::Is(string type){
     return "Hiero" == type;
}

