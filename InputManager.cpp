#include "InputManager.hpp"
#include <iostream>
#include <conio.h>
InputManager::InputManager() {};
InputManager::Action InputManager::getAction()
{
	char key = _getch();
	return convertKeyToAction(key);
}
InputManager::Action InputManager::convertKeyToAction(char key)
{
	switch (key)
	{
	case 'a': case 'A': case 'ô': case 'Ô': return Action::LIGHT_LEFT;
	case 'd': case 'D': case 'â': case 'Â': return Action::LIGHT_RIGHT;
	case 'w': case 'W': case 'ö': case 'Ö': return Action::LIGHT_JUMP;
	case 'j': case 'J': case 'î': case 'Î': return Action::SHADOW_LEFT;
	case 'l': case 'L': case 'ä': case 'Ä': return Action::SHADOW_RIGHT;
	case 'i': case 'I': case 'ø': case 'Ø': return Action::SHADOW_JUMP;
	case '\r': case '\n': return Action::ACTIVATE;
	case 'q': case 'Q': case 'é': case 'É': return Action::EXIT;
	default: return Action::NONE;
	}
}