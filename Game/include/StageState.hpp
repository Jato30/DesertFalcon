#ifndef __STAGE_STATE_HPP__
#define __STAGE_STATE_HPP__

#include <memory>
#include <vector>

#include "ActionManager.hpp"
#include "GameObject.hpp"
#include "InputManager.hpp"
#include "Sprite.hpp"
#include "State.hpp"
#include "Timer.hpp"

using std::vector;

class StageState: public State {
	public:
		StageState(void);
		~StageState(void);
		void Update(float dt);
		void Render(void) const;
		void Pause(void);
		void Resume(void);
		void LoadAssets(void) const;

	private:
		Sprite bg;
};

#endif // __STAGE_STATE_HPP__
