#include "Falcon.hpp"

Falcon::Falcon(int hitpoints) : GameObject()
          , sp("./resources/img/penguin_sheet.png",false, 0.1, 4)
          , spShade("./resources/img/penguin_shade.png",false, 0.03, 2)
          , hp(hitpoints)
          , speed(0., 0.) {

     sp.SetScale(0.7);
     spShade.SetScale(0.7);
     rotation = -38.264;
     box.SetWidthAndHeight(Vec2(sp.GetWidth(), sp.GetHeight()));
     Vec2 windowPos = Window::GetInstance().GetWindowDimensions();
     box = Vec2((windowPos.x / 2) - box.w, windowPos.y - box.h);
     scoreUp.Open("./resources/audio/Curando.wav");
     Resources::ChangeSoundVolume(MAX_VOLUME);
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
          speed.x = -LINEAR_SPEED * FALCON_SPEED_PROPORTION_X * dt;
          speed.y = -LINEAR_SPEED * FALCON_SPEED_PROPORTION_Y * dt;
          if(box.x < 0){
               speed = 0;
          }
     }
     
     if(ActionManager::RightArrowAction()){
          speed.x = LINEAR_SPEED * FALCON_SPEED_PROPORTION_X * dt;
          speed.y = LINEAR_SPEED * FALCON_SPEED_PROPORTION_Y * dt;
          if(box.y + box.h > windowSize.y){
               speed = 0;
          }
     }



     // Out of bounds
     // if(box.y + box.h > windowSize.y){
          // box.x = (windowSize.x / 2) - box.w;
          // box.y = windowSize.y - box.h;
     // }
     // else if(box.x < 0){
          // box.x = 0;
          // box.y = windowSize.y / 2;
     // }

     box = box + speed;
     speed = 0;


     // Verifica morte
     if(hp <= 0){
          hp = 0;
          RequestDelete();
     }
}

void Falcon::Render(void){
     if(!IsDead()){
          Rect falconBox (box);
          falconBox.y -= (box.h + 20) * height; 
          spShade.Render(box, rotation);
          sp.Render(falconBox, rotation);
     }
}

bool Falcon::IsDead(void){
     return dead;
}

void Falcon::RequestDelete(void){
     dead = true;
}

void Falcon::NotifyCollision(GameObject& object){
     if(object.Is("Hiero")){
          if(height == object.height){
               scoreUp.Play(1);
               Damage(HIERO_DAMAGE);
               Score::Increase(1);
          }
	}
     if(object.Is("Enemy")){
          if(height == object.height){
               Damage(HIERO_DAMAGE * 200);
          }
	}
     if(object.Is("Obstacle")){
          if(height == 0){
               GlobalVars::SET_ALL_SPEED = false;
               Damage(HIERO_DAMAGE * 50);
          }
	}
}

bool Falcon::Is(string type){
     return "Falcon" == type;
}

void Falcon::Damage(int damage){
     hp -= damage;
     if(hp < 1){
          Animation* death = new Animation(box.x, box.y, 0, "./resources/img/penguindeath.png", 0.15, 5);
          Game::GetInstance().GetCurrentState().AddObject(death);
          Sound* soundExplosion = new Sound("./resources/audio/boom.wav");
          soundExplosion->Play(1);
          RequestDelete();
     }
}

