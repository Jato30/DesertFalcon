#include "Falcon.hpp"

Falcon::Falcon(int hitpoints) : GameObject()
          , sp("./resources/img/falcon.png")
          , hp(hitpoints)
          , speed(0., 0.) {

     rotation = 0;
     box = Vec2(20, 0);
     box.SetWidthAndHeight(Vec2(sp.GetWidth(), sp.GetHeight()));
}

Falcon::~Falcon(){

}

void Falcon::Update(float dt){
     sp.Update(dt);


     // Movimento
     if(ActionManager::LeftArrowAction()){
          speed = -LINEAR_SPEED * dt;
     }
     else if(ActionManager::RightArrowAction()){
          speed = LINEAR_SPEED * dt;
     }
     box = box + speed;
     speed = 0;


     // Out of bounds
     if((box.x + box.w) > Window::GetInstance().GetWindowDimensions().x){
          box.x = -box.w + Window::GetInstance().GetWindowDimensions().x;
     }
     if((box.y + box.h) > Window::GetInstance().GetWindowDimensions().y){
          box.y = -box.h + Window::GetInstance().GetWindowDimensions().y;
     }
     if(box.x < 0){
          box.x = 0;
     }
     if(box.y < 0){
          box.y = 0;
     }


     // Verifica morte
     if(hp <= 0){
          hp = 0;
          RequestDelete();
     }
}

void Falcon::Render(void){
     sp.Render(box, rotation);
}

bool Falcon::IsDead(void){
     return dead;
}

void Falcon::RequestDelete(void){
     dead = true;
}

void Falcon::NotifyCollision(GameObject& object){
     if(object.Is("Hiero")){
          Damage(HIERO_DAMAGE);
	}
}

bool Falcon::Is(string type){
     return "Falcon" == type;
}

Rect Falcon::GetWorldRenderedRect(void) const{
     return box;
}

void Falcon::Damage(int damage){
     hp -= damage;
}

