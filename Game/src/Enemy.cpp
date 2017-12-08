#include "Enemy.hpp"

Enemy::Enemy(Vec2 pos, Rect dest) : GameObject(), sp("./resources/img/Enemy.png", false, 0.1, 4), speed(0., 0.) {
     rotation = -38.264;
     sp.SetScale(0.2);
     box.SetWidthAndHeight(Vec2(sp.GetWidth(), sp.GetHeight()));
     box = Vec2(pos.x, pos.y - box.h);
     pos = Vec2(pos.x + (box.w / 2), pos.y + (box.h / 2));
     destiny = Vec2(dest.x + (dest.w / 2), dest.y + (dest.h / 2));
     float angle = destiny.Inclination(pos);
     destiny.x = std::cos(angle);
     destiny.y = std::sin(angle);

}

Enemy::~Enemy(){
     
}

void Enemy::Update(float dt){
     sp.Update(dt);

     speed = 0;
     // Movimento
     if(GlobalVars::SET_ALL_SPEED){
          // speed.x = LINEAR_SPEED * dt;
          // speed.y = LINEAR_SPEED * dt;
          speed.x = -LINEAR_SPEED *  FALCON_SPEED_PROPORTION_X * 1.5 * dt;
          speed.y = LINEAR_SPEED * FALCON_SPEED_PROPORTION_Y * 1.5 * dt;
     }
     // speed *= destiny;
     box = box + speed;

     // Out of bounds
     if(((box.x + box.w) < 0) || (box.y > Window::GetInstance().GetWindowDimensions().y) ){
          RequestDelete();
     }
}

void Enemy::Render(void){
     sp.Render(box, rotation);
}

bool Enemy::IsDead(void){
     return dead;
}

void Enemy::RequestDelete(void){
     dead = true;
}

void Enemy::NotifyCollision(GameObject& object){

}

bool Enemy::Is(string type){
     return "Enemy" == type;
}

