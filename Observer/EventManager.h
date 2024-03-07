#ifndef _OBSERVED_CURSOR_H_
#define _OBSERVED_CURSOR_H_

#include "ISubject.h"

#include <memory>
#include <vector>

class EventManager : public ISubject {
public:
	EventManager() = default;
	~EventManager() noexcept {};
	/**
	* @brief Subscribes an observer to event manager
	* @param observer A unique pointer to the observer
	* @throw std::invalid_argument if pointer to the observer is invalid
	*/
	virtual void subscribe(std::unique_ptr<IObserver> observer);
	/**
	* @brief Notifies all observers to check cursor position changes
	*/
	void checkCursorPositionChanges();
private:
	/**
	* @brief Notifies all observers
	*/
	virtual void notify();

	std::vector<std::unique_ptr<IObserver>> m_observers;
};

#endif 