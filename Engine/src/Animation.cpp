#include "Animation.hpp"

Animation::Animation(
		float x, float y, float rotation,
		string sprite,
        float frameTime, int frameCount,
        bool ends)
            : GameObject()
            , endTimer()
            , timeLimit(frameCount*frameTime)
	        , oneTimeOnly(ends)
            , sp(sprite, false, frameTime, frameCount ) {

    sp.SetScale(0.5);
	box= Rect(x, y, sp.GetWidth(), sp.GetHeight());
	this->rotation = rotation;
}

void Animation::Update(float dt) {
	sp.Update(dt);
	endTimer.Update(dt);
}

void Animation::Render(void) {
	sp.Render(box, rotation);
}


bool Animation::IsDead(void) {
	if(oneTimeOnly) {
		if(endTimer.Get() > timeLimit) {
			return true;
		}
	}
	return false;
}

void Animation::NotifyCollision(GameObject &other) {}

bool Animation::Is(string type) {
	return "Animation" == type;
}

void Animation::RequestDelete(void) {
	if(!oneTimeOnly) {
		oneTimeOnly = true;
	}
	endTimer.Update(timeLimit);
}

