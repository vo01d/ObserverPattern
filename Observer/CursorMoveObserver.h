#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#include "IObserver.h"
#include "Utils.h"

#include <optional>

class CursorMoveObserver : public IObserver {
public:
	CursorMoveObserver() = default;
	~CursorMoveObserver() noexcept {};
	/**
	* @brief Handles the event triggered by changes in cursor position.
	*
	* When the cursor enters the area of the console window, the color of the text in the console changes, and the current time is written to the log file
	* with the tag "Enter". When the cursor leaves the area of the console window, the color of the text in the console changes to the original and the
	* current time is recorded in the log with the tag "Leave".
	*
	* @throws std::runtime_error if unable to open the log file.
	*/
	virtual void handleEvent() override;
private:
	std::optional<bool> m_isCursorInConsoleBefore;
};

#endif 