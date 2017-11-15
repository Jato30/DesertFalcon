#include "Falcon.hpp"

Falcon::Falcon(int hitpoints) : GameObject()
          , height(0)
          , sp("./resources/img/penguin_sheet.png",false, 0.1, 4)
          , spShade("./resources/img/penguin_shade.png",false, 0.01, 2)
          , hp(hitpoints)
          , speed(0., 0.) {

     sp.SetScale(0.7);
     spShade.SetScale(0.7);
     rotation = -30;
     box.SetWidthAndHeight(Vec2(sp.GetWidth(), sp.GetHeight()));
     box = Vec2((Window::GetInstance().GetWindowDimensions().x / 2) - box.w, Window::GetInstance().GetWindowDimensions().y - box.h);
}

Falcon::~Falcon(){

}

void Falcon::Update(float dt){
     sp.Update(dt);
     spShade.Update(dt);

     Vec2 windowSize = Window::GetInstance().GetWindowDimensions();

     // Movimento
     if(InputManager::GetInstance().KeyPress('w') || InputManager::GetInstance().KeyPress(SDLK_UP)){
          if(height < 2){
               height++;
          }
     }
     if(InputManager::GetInstance().KeyPress('s') || InputManager::GetInstance().KeyPress(SDLK_DOWN)){
          if(height > 0){
               height--;
          }
     }
     if(ActionManager::LeftArrowAction()){
          speed.x = -LINEAR_SPEED * FALCON_SPEED_PROPORTION * dt;
          speed.y = -LINEAR_SPEED * (1 / FALCON_SPEED_PROPORTION) * dt;
     }
     if(ActionManager::RightArrowAction()){
          speed.x = LINEAR_SPEED * FALCON_SPEED_PROPORTION * dt;
          speed.y = LINEAR_SPEED * (1 / FALCON_SPEED_PROPORTION) * dt;
     }

     box = box + speed;


     // Out of bounds
     if(box.y + box.h > windowSize.y){
          box.x = (windowSize.x / 2) - box.w;
          box.y = windowSize.y - box.h;
     }
     else if(box.x < 0){
          box.x = 0;
          box.y = windowSize.y / 2;
     }

     speed = 0;


     // Verifica morte
     if(hp <= 0){
          hp = 0;
          RequestDelete();
     }
}

void Falcon::Render(void){
     Rect falconBox (box);
     falconBox.y -= (box.h + 20) * height; 
     spShade.Render(box, rotation);
     sp.Render(falconBox, rotation);
}

bool Falcon::IsDead(void){
     return dead;
}

void Falcon::RequestDelete(void){
     dead = true;
}

void Falcon::NotifyCollision(GameObject& object){
     if(object.Is("Hiero")){
          if(height == 0){
               Damage(HIERO_DAMAGE);
          }
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

