#include <iostream>
#include "SDL.h"
#include "Engine.h"
#include "StartScreen.h"

int main(int argc, char *argv[]) {
	std::cout << "Hello, world!" << std::endl;

	Engine *engine = Engine::getInstance();
	engine->setScreen(new StartScreen());
	engine->doGameLoop();
	delete engine;

	std::cout << "Goodbye" << std::endl;
	return 0;
}
