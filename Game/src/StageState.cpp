#include "StageState.hpp"

StageState::StageState() : State(), bg("./resources/img/paisagem-do-deserto.jpg"), newHiero(), newObstacle(){
    player = new Falcon(PLAYER_BASE_LIFE);
    AddObject(player);
    quitRequested = false;
    Score::CreateInstance();
    music.Open("./resources/audio/loop_4_atualizado.ogg");
    music.Play(0);
    toEnd = Timer();
}

StageState::~StageState(){
    objectArray.clear();
    Score::DeleteInstance();
    music.Stop();
}

void StageState::Update(float dt){
    // Condições de saída
    if(player != nullptr){
        if(player->IsDead()){
            player = nullptr;
            Finish();
        }
    }
    else{
        Finish();
    }

    if(QuitRequested() || InputManager::GetInstance().QuitRequested()){
        quitRequested = true;
    }
    
    if(ActionManager::EscapeAction()){
        popRequested = true;
        EndState* endState = new EndState(Score::GetScore());
        Game::GetInstance().Push(endState);
    }


    toEnd.Update(dt);
    UpdateArray(dt);
    Score::Update(dt);

    Vec2 windowPos = Window::GetInstance().GetWindowDimensions();
    
    if(GlobalVars::SET_ALL_SPEED){
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

        // Novo Inimigo
        newEnemy.Update(dt);
        if(newEnemy.Get() > HIERO_COOLDOWN - 1 + rand()%3){
            // Escolhe uma reta aleatória entre (x: meia tela ~ tela, y: 0 ~ 0) e (x: tela ~ tela, y: 0 ~ meia tela)
            Vec2 randLine;
            randLine = rand() % 2 == 0 ? Vec2((windowPos.x / 2), 0) : Vec2(windowPos.x, (windowPos.y / 2));
            // Escolhe um ponto aleatório entre a reta escolhida
            Vec2 enemyPos((rand() % ((int) (windowPos.x - randLine.x) + 1)) + randLine.x, rand() % ((int) randLine.y + 1));
            AddObject(new Enemy(enemyPos, player->box));
            newEnemy.Restart();
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
    }

    GlobalVars::SET_ALL_SPEED = true;
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
}

void StageState::Render(void) const {
    Vec2 windowPos = Window::GetInstance().GetWindowDimensions();
    bg.Render(Rect(0, 0, windowPos.x, windowPos.y));
    Score::Render();

    RenderArray();
}

void StageState::Pause(){

}

void StageState::Resume(){
    
}

void StageState::Finish(void){
    if(toEnd.Get() > 2){
        toEnd.Restart();
    }

    else if(toEnd.Get() >= 0.75){
        popRequested = true;
        EndState* endState = new EndState(Score::GetScore());
        Game::GetInstance().Push(endState);
    }
}

void StageState::LoadAssets(void) const{
    Resources::GetImage("./resources/img/penguin_sheet.png");
    Resources::GetImage("./resources/img/penguin_shade.png");
    Resources::GetImage("./resources/img/paisagem-do-deserto.jpg");
    Resources::GetImage("./resources/img/hiero.png");
    Resources::GetImage("./resources/img/Enemy.png");
    Resources::GetImage("./resources/img/obstacle.png");
    Resources::GetImage("./resources/img/penguindeath.png");
    Resources::GetMusic("./resources/audio/loop_4_atualizado.ogg");
    Resources::GetSound("./resources/audio/Curando.wav");
    Resources::GetSound("./resources/audio/shock.wav");
    Resources::GetFont("./resources/font/Call me maybe.ttf", 26);
}

