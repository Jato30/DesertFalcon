#ifndef __ACTIONMANAGER_HPP__
#define __ACTIONMANAGER_HPP__

#include "InputManager.hpp"

class ActionManager{

	public:

		static bool LeftArrowAction();

		static bool RightArrowAction();

		static bool UpArrowAction();

		static bool DownArrowAction();

		static bool StartAction();

		static bool EscapeAction();

		static bool EnterKeyAction();

	private:

		ActionManager();

};

#endif // __ACTIONMANAGER_HPP__
