#ifndef __FALCON_HPP__
#define __FALCON_HPP__

#include "GameObject.hpp"
#include "Vec2.hpp"
#include "Sprite.hpp"
#include "GameDefines.hpp"

#include <string>

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
          void Damage(int) const;
     
     private:
          Sprite sp;
          int hp;
          Vec2 speed;
};

#include "ActionManager.hpp"
#include "Window.hpp"
#include "Hiero.hpp"

#endif // __FALCON_HPP__

