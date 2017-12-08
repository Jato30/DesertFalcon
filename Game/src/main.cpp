#include <iostream>
#include <string>

#include "Game.hpp"
#include "TitleState.hpp"

using std::cout;
using std::endl;

namespace GlobalVars{
     bool SET_ALL_SPEED = true;
}

int main(int argc, char **argv) {
	Game game(std::string("Desert Falcon"), 800, 600);
	game.Push(new TitleState());
	game.Run();
	return 0;
}

