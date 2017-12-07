#include "Game.hpp"
#include "Window.hpp"

#include <stdlib.h>
#include <ctime>

#include "Error.hpp"
#include "Resources.hpp"

Game* Game::instance = nullptr;

Game::Game(std::string title, int width, int height)
		: dt(0.0)
		, inputManager(InputManager::GetInstance())
		, window(title, width, height) {
		//, frameStart(SDL_GetTicks()) {
	SDL_version compiled;
	SDL_version linked;

	SDL_VERSION(&compiled);
	SDL_GetVersion(&linked);
	printf("Compiled against SDL version %d.%d.%d " END_LINE, compiled.major, compiled.minor, compiled.patch);
	printf("Linked against SDL version %d.%d.%d" END_LINE, linked.major, linked.minor, linked.patch);

	frameStart = SDL_GetTicks();
	srand(time(NULL));
	
	if(nullptr != Game::instance) {
		Error("Second instantion of the game!");
	}
	Game::instance = this;

	int result = IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);
	
	if(0 == result) {
		Error("Loading IMG_Init failed: " << IMG_GetError());
	}
	
	if(0 == (result & IMG_INIT_JPG)) {
		Error("Loading IMG_INIT_JPG failed: " << IMG_GetError());
	}

	if(0 == (result & IMG_INIT_PNG)) {
		Error("Loading IMG_INIT_PNG failed: " << IMG_GetError());
	}

	if(0 == (result & IMG_INIT_TIF)) {
		Error("Loading IMG_INIT_TIF failed: " << IMG_GetError());
	}

	// window = Window(title, width, height);

	result = Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG);
	if(0 == result) {
		Error("Loading Mix_Init failed: " << Mix_GetError());
	}

/*	if(0 == (result & MIX_INIT_MP3 ) ) {
		Error("Loading MIX_INIT_MP3 failed: " << Mix_GetError());
	}*/
	
	if(0 == (result & MIX_INIT_OGG)) {
		Error("Loading MIX_INIT_OGG failed: " << Mix_GetError());
	}

	if(0 != Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, MIXER_CHUCK_SIZE)) {
		Error("Loading Mix_OpenAudio failed: " << Mix_GetError());
	}

	int numAllocatedChannels = Mix_AllocateChannels(1024);
	REPORT_DEBUG2(1, " Succesfully allocated " << numAllocatedChannels << " out of 1024 tried channels.");

	if(0 != TTF_Init()) {
		Error("Loading TTF_Init failed: " << TTF_GetError());
	}
	
	REPORT_I_WAS_HERE;
	storedState = nullptr;
	REPORT_I_WAS_HERE;
	capFramerate = true;
	maxFramerate = INITIAL_FRAMERATE;
	frameDuration = 1000.0/INITIAL_FRAMERATE;
}

Game::~Game() {
	IMG_Quit();
	if(nullptr != storedState) {
		delete storedState;
	}
	while(!stateStack.empty()) {
		stateStack.pop();
	}
	Resources::ClearResources();
	TTF_Quit();
	Mix_CloseAudio();
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}

Game& Game::GetInstance(void) {
	return *(Game::instance);
}

State& Game::GetCurrentState(void) const {
	return *stateStack.top();
}

void Game::Push(State* state) {
	if(nullptr != storedState) {
		std::cout << WHERE << "[WARNING]Não era para ter um state aqui...\n";
	}
	storedState = state;
	storedState->LoadAssets();
}

void Game::Run(void) {
	if(nullptr != storedState) {
		stateStack.push(std::unique_ptr<State>(storedState));
		storedState = nullptr;
	} else {
		// Jogo terminou
		return;
	}

	while(!stateStack.empty()) {
		if (capFramerate) {
			float timeRemaining = frameDuration - (SDL_GetTicks() - frameStart);
			if (0 < timeRemaining) {
				SDL_Delay(timeRemaining);
			}
		}
	
		if(stateStack.top()->QuitRequested()){
            while(!stateStack.empty()){
                stateStack.pop();
            }
            break;
        	}

		if(stateStack.top()->PopRequested()){
			stateStack.pop();
			if(!stateStack.empty()){
				stateStack.top()->Resume();
			}
		}
		if(storedState != nullptr){
			if(!stateStack.empty()){
				stateStack.top()->Pause();
			}
			stateStack.push(std::unique_ptr<State>(storedState));
			storedState = nullptr;
		}
	
		CalculateDeltaTime();
		inputManager.Update();
		stateStack.top()->Update(GetDeltaTime());
		Window::GetInstance().ReDoRenderer();
		stateStack.top()->Render();
		SDL_RenderPresent(Window::GetInstance().GetRenderer());
		UpdateStack();
	}

	while(!stateStack.empty()) {
		stateStack.pop();
	}
	
	Resources::ClearResources();
}

void Game::CalculateDeltaTime(void) {
	u_int32_t newTick = SDL_GetTicks();
	// Converter de milissegundos para segundos
	dt = ((float)(newTick-frameStart))/1000.0;
	frameStart = newTick;
}

float Game::GetDeltaTime(void) const {
	return dt;
}

void Game::UpdateStack(void) {
	bool popped = false;
	if(stateStack.top()->PopRequested()) {
		stateStack.pop();
		Resources::ClearResources();
		popped = true;
	}

	if(nullptr != storedState) {
		if(!stateStack.empty()) {
			stateStack.top()->Pause();
		}
		stateStack.push(std::unique_ptr<State>(storedState));
		storedState = nullptr;
	}

	if(!stateStack.empty() && popped) {
		stateStack.top()->Resume();
	}
}

void Game::SetMaxFramerate(signed long int newMaxFramerate) {
	REPORT_DEBUG("\tnewMaxFramerate= " << newMaxFramerate);
	if (newMaxFramerate < 1) {
		maxFramerate = 1;
	} else {
		maxFramerate = newMaxFramerate;
	}
	frameDuration = 1000.0/maxFramerate;
}

unsigned int Game::GetMaxFramerate(void) const {
	return maxFramerate;
}

float Game::GetCurrentFramerate(void) const {
	return 1.0/dt;
}

void Game::LimitFramerate(bool limit) {
	capFramerate = limit;
}

bool Game::IsFramerateLimited(void) const {
	return capFramerate;
}

unsigned int Game::GetTicks(void){
	return frameStart;
}
