#include "GameObject.hpp"
#include "Error.hpp"

GameObject::GameObject(void): rotation(0.), height(0), dead(false){
}


GameObject::~GameObject(){
	REPORT_I_WAS_HERE;
}

void GameObject::Update(float dt){

}

void GameObject::Render(void){
	REPORT_DEBUG("\t GameObject::Render called!");
}

bool GameObject::IsDead(void){
	return dead;
}

void GameObject::RequestDelete(void){
	dead = true;
}

void GameObject::NotifyCollision(GameObject &other){
	REPORT_DEBUG("\t GameObject::NotifyCollision called!");
}

bool GameObject::Is(string type){
	REPORT_DEBUG("\t GameObject::Is called!");
	return ("GameObject" == type);
}


