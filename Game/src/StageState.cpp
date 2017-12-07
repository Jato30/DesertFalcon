#include "StageState.hpp"

StageState::StageState() : State(), bg("./resources/img/paisagem-do-deserto.jpg"), newHiero(), newObstacle(){
    AddObject(new Falcon(PLAYER_BASE_LIFE));
    quitRequested = false;
    Score::CreateInstance();
    music.Open("./resources/audio/loop_4_atualizado.ogg");
    music.Play(0);
}

StageState::~StageState(){
    objectArray.clear();
    Score::DeleteInstance();
    music.Stop();
}

void StageState::Update(float dt){
    UpdateArray(dt);
    Score::Update(dt);
    
    Vec2 windowPos = Window::GetInstance().GetWindowDimensions();
    
    // Novo Hiero
    newHiero.Update(dt);
    if(newHiero.Get() > HIERO_COOLDOWN){
        // Escolhe uma reta aleatória entre (x: meia tela ~ tela, y: 0 ~ 0) e (x: tela ~ tela, y: 0 ~ meia tela)
        Vec2 randLine;
        randLine = rand() % 2 == 0 ? Vec2((windowPos.x / 2), 0) : Vec2(windowPos.x, (windowPos.y / 2));
        // Escolhe um ponto aleatório entre a reta escolhida
        Vec2 hieroPos((rand() % ((int) (windowPos.x - randLine.x) + 1)) + randLine.x, rand() % ((int) randLine.y + 1));
        AddObject(new Hiero(hieroPos));
        newHiero.Restart();
    }

    // Novo Obstáculo
    newObstacle.Update(dt);
    if(newObstacle.Get() > OBSTACLE_COOLDOWN){
        // Escolhe uma reta aleatória entre (x: meia tela ~ tela, y: 0 ~ 0) e (x: tela ~ tela, y: 0 ~ meia tela)
        Vec2 randLine;
        randLine = rand() % 2 == 0 ? Vec2((windowPos.x / 2), 0) : Vec2(windowPos.x, (windowPos.y / 2));
        // Escolhe um ponto aleatório entre a reta escolhida
        Vec2 obstaclePos((rand() % ((int) (windowPos.x - randLine.x) + 1)) + randLine.x, rand() % ((int) randLine.y + 1));
        AddObject(new Obstacle(obstaclePos));
        newObstacle.Restart();
    }

    // Confere colisão entre GOs
    if(!objectArray.empty()){
		for(uint count1 = 0; count1 < objectArray.size() - 1; count1++) {
			for(uint count2 = count1 + 1; count2 < objectArray.size(); count2++) {
				if(Collision::IsColliding(objectArray[count1]->box, objectArray[count2]->box, objectArray[count1]->rotation, objectArray[count2]->rotation)) {
					objectArray[count1]->NotifyCollision(*objectArray[count2]);
					objectArray[count2]->NotifyCollision(*objectArray[count1]);
				}
			}
		}
    }
    

    if(QuitRequested() || InputManager::GetInstance().QuitRequested()){
        quitRequested = true;
    }
    
    if(ActionManager::EscapeAction()){
        popRequested = true;
        EndState* endState = new EndState(Score::GetScore());
        Game::GetInstance().Push(endState);
    }
}

void StageState::Render(void) const {
    Vec2 windowPos = Window::GetInstance().GetWindowDimensions();
    bg.Render(Rect(0, 0, windowPos.x, windowPos.y));
    Score::Render();

    RenderArray();
}

void StageState::LoadAssets(void) const{
    Resources::GetImage("./resources/img/penguin_sheet.png");
    Resources::GetImage("./resources/img/penguin_shade.png");
    Resources::GetImage("./resources/img/paisagem-do-deserto.jpg");
    Resources::GetImage("./resources/img/hiero.png");
    Resources::GetImage("./resources/img/obstacle.png");
    Resources::GetMusic("./resources/audio/loop_4_atualizado.ogg");
    Resources::GetSound("./resources/audio/Curando.wav");
    Resources::GetSound("./resources/audio/shock.wav");
    Resources::GetFont("./resources/font/Call me maybe.ttf", 26);
}

void StageState::Pause(){

}

void StageState::Resume(){
    
}