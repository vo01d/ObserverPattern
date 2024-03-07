#include "CursorMoveObserver.h"

#include <fstream>
#include <iostream>
#include <Windows.h>

void CursorMoveObserver::handleEvent() {
	std::ofstream fout("log.txt", std::ios::app);
	if (!fout.is_open()) {
		throw std::runtime_error("Error: Unable to open log file!");
	}

	std::string textColor;

	const bool isCursorInConsoleNow = Utils::isCursorInConsole();
	if (!m_isCursorInConsoleBefore.has_value()) {
		m_isCursorInConsoleBefore = !isCursorInConsoleNow;
	}

	if (isCursorInConsoleNow && !m_isCursorInConsoleBefore.value()) {
		fout << "Enter: " << Utils::getCurrentTime() << std::endl;
		std::system(Utils::getRandomTextColor().c_str());
		m_isCursorInConsoleBefore = true;
	}
	else if (!isCursorInConsoleNow && m_isCursorInConsoleBefore.value()) {
		fout << "Leave: " << Utils::getCurrentTime() << std::endl;
		std::system("color 7");
		m_isCursorInConsoleBefore = false;
	}
	fout.close();
}