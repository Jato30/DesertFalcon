#ifndef __FALCON_HPP__
#define __FALCON_HPP__

#include "GameObject.hpp"
#include "Vec2.hpp"
#include "Sprite.hpp"

#include <string>

#define LINEAR_SPEED 200

class Falcon : public GameObject {
     public:
          Falcon(Vec2 pos, int hitpoints);
          ~Falcon();
          void Update(float);
          void Render(void);
          bool IsDead(void);
          void RequestDelete(void);
          void NotifyCollision(GameObject&);
          bool Is(string);
          Rect GetWorldRenderedRect(void) const;
     
     private:
          Sprite sp;
          int hp;
          Vec2 speed;
};

#include "ActionManager.hpp"
#include "Window.hpp"

#endif // __FALCON_HPP__

