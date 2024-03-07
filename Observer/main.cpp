#include "EventManager.h"

#include "CursorMoveObserver.h"
#include <iostream>

int main() {
	try {
		EventManager eventManager;
		eventManager.subscribe(std::make_unique<CursorMoveObserver>());

		Utils::showConsoleCursor(false);

		std::cout << "Hello! How are you doing? I hope you're having a wonderful day filled with joy and success!" << std::endl;

		while (true) {
			eventManager.checkCursorPositionChanges();
		}
	}
	catch (const std::runtime_error& ex) {
		std::cout << ex.what() << std::endl;
	}
	catch (const std::invalid_argument& ex) {
		std::cout << ex.what() << std::endl;
	}
	catch (...) {
		std::cout << "Something went wrong!" << std::endl;
	}

	return 0;
}