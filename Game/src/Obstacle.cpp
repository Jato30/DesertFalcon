#include "Obstacle.hpp"

Obstacle::Obstacle(Vec2 pos) : GameObject(), sp("./resources/img/obstacle.png"), speed(0., 0.) {
     float random = rand() % 20;
     sp.SetScale((random + 10) / 100);
     rotation = -38.264;
     box = Vec2(pos.x, pos.y);
     box.SetWidthAndHeight(Vec2(sp.GetWidth(), sp.GetHeight()));
}

Obstacle::~Obstacle(){

}

void Obstacle::Update(float dt){
     sp.Update(dt);

     // Movimento
     speed.x = -(LINEAR_SPEED - 50) * FALCON_SPEED_PROPORTION_X * dt;
     speed.y = (LINEAR_SPEED - 50) * FALCON_SPEED_PROPORTION_Y * dt;
     box = box + speed;

     // Out of bounds
     if((box.x < 0) || ((box.y + box.h) > Window::GetInstance().GetWindowDimensions().y) ){
          RequestDelete();
     }
}

void Obstacle::Render(void){
     sp.Render(box, rotation);
}

bool Obstacle::IsDead(void){
     return dead;
}

void Obstacle::RequestDelete(void){
     dead = true;
}

void Obstacle::NotifyCollision(GameObject& object){
    if(object.Is("Falcon")){
          box.x -= speed.x;
          box.y -= speed.y;
	}
}

bool Obstacle::Is(string type){
     return "Obstacle" == type;
}

