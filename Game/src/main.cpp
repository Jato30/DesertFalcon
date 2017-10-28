#include <iostream>
#include <string>

#include "Game.hpp"
#include "TitleState.hpp"

using std::cout;
using std::endl;

int main(int argc, char **argv) {
	Game game(std::string("Desert Falcon"), 1024, 600);
	game.Push(new TitleState());
	game.Run();
	return 0;
}

