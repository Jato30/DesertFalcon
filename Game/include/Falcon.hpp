#ifndef __FALCON_HPP__
#define __FALCON_HPP__

#include "GameObject.hpp"
#include "Vec2.hpp"
#include "Sprite.hpp"

#include <string>

class Falcon : public GameObject {
public:
     Falcon(int hitpoints);
     ~Falcon();
     void Update(float);
     void Render(void);
     bool IsDead(void);
     void RequestDelete(void);
     void NotifyCollision(GameObject&);
     bool Is(string);
     Rect GetWorldRenderedRect(void) const;
     void Damage(int);
     
private:
     Sprite sp;
     int hp;
     Vec2 speed;
};

#include "GameDefines.hpp"
#include "ActionManager.hpp"
#include "Window.hpp"
#include "Hiero.hpp"

#endif // __FALCON_HPP__

