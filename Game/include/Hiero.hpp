#ifndef __HIERO_HPP__
#define __HIERO_HPP__

#include "GameObject.hpp"
#include "Sprite.hpp"
#include "Vec2.hpp"

#include <string>

#define LINEAR_SPEED 200

class Hiero : public GameObject {
     public:
          Hiero(Vec2 pos);
		~Hiero();
		void Update(float);
		void Render(void);
		bool IsDead(void);
		void RequestDelete(void);
		void NotifyCollision(GameObject);
          bool Is(string);
		Rect GetWorldRenderedRect(void) const;
          
	private:
          Sprite sp;
          Vec2 speed;
          int hp;
};

#include "ActionManager.hpp"

#endif // __HIERO_HPP__