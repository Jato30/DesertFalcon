#ifndef __HIERO_HPP__
#define __HIERO_HPP__

#include "GameObject.hpp"
#include "Sprite.hpp"
#include "Vec2.hpp"
#include "GameDefines.hpp"

#include <string>

class Hiero : public GameObject {
     public:
          Hiero(Vec2 pos);
		~Hiero();
		void Update(float);
		void Render(void);
		bool IsDead(void);
		void RequestDelete(void);
		void NotifyCollision(GameObject&);
          bool Is(string);
		Rect GetWorldRenderedRect(void) const;
          
	private:
          Sprite sp;
};

#endif // __HIERO_HPP__

