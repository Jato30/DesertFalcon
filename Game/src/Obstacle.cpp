#include "Obstacle.hpp"

Obstacle::Obstacle(Vec2 pos) : GameObject(), sp("./resources/img/obstacle.png"), speed(0., 0.) {
    float random = rand() % 20;
    sp.SetScale((random + 10) / 100);
    rotation = -38.264;
    box.SetWidthAndHeight(Vec2(sp.GetWidth(), sp.GetHeight()));
    box = Vec2(pos.x, pos.y - box.h);
}

Obstacle::~Obstacle(){

}

void Obstacle::Update(float dt){
    sp.Update(dt);

    // Movimento
    speed = 0;
    if(GlobalVars::SET_ALL_SPEED){
        speed.x = -LINEAR_SPEED * FALCON_SPEED_PROPORTION_X * 0.9 * dt;
        speed.y = LINEAR_SPEED * FALCON_SPEED_PROPORTION_Y * 0.9 * dt;
    }
    box = box + speed;

    // Out of bounds
    if(((box.x + box.w) < 0) || (box.y > Window::GetInstance().GetWindowDimensions().y) ){
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

}

bool Obstacle::Is(string type){
    return "Obstacle" == type;
}

