#include "EventManager.h"
#include <stdexcept>

void EventManager::subscribe(std::unique_ptr<IObserver> observer) {
	if (!observer) {
		throw std::invalid_argument("Error: Invalid observer pointer!");
	}
	m_observers.push_back(std::move(observer));
}

void EventManager::checkCursorPositionChanges() {
	notify();
}

void EventManager::notify() {
	for (auto& observer : m_observers) {
		observer->handleEvent();
	}
}