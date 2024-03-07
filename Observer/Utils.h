#ifndef _UTILS_H_
#define _UTILS_H_

#include <string>

namespace Utils {
	/**
	* @brief Generate a random integer in range (rangeBegin, rangeEnd)
	* @param rangeBegin Start value of range
	* @param rangeEnd End value of range
	* @throw std::invalid_argument if begin of range is greater than end of range
	* @return A randomly generated integer within specified range
	*/
	int generateRandomNumberInRange(int rangeBegin, int rangeEnd);
	/**
	* @brief Generate a random text color that selected from predefined list of colors
	* @return A randomly selected text color represented as a string
	*/
	std::string getRandomTextColor();
	/**
	* @brief Gets the current local time formatted as a string in format "DD-MM-YYYY HH:MM:SS".
	* @return Current local time in the specified format represented as a string
	*/
	std::string getCurrentTime();
	/**
	* @brief Checks if the cursor is in the console window.
	* @throw std::runtime_error if the console window not found
	* @throw std::runtime_error if unable to get console window rectangle
	* @throw std::runtime_error if unable to get cursor position
	* @return true if the cursor is within the console window, false otherwise.
	*/
	bool isCursorInConsole();
	/**
	* @brief Shows or hide console cursor
	* @throw std::runtime_error if invalid handle to console output
	* @throw std::runtime_error if failed to get console cursor information
	* @throw std::runtime_error if failed to set console cursor information
	*/
	void showConsoleCursor(bool showFlag);
};

#endif 