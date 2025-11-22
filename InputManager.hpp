#pragma once
class InputManager
{
public:
	// Действия, которые могут выполнять персонажи
	enum class Action
	{
		LIGHT_LEFT, LIGHT_RIGHT, LIGHT_JUMP,
		SHADOW_LEFT, SHADOW_RIGHT, SHADOW_JUMP,
		ACTIVATE,
		EXIT,
		NONE
	};
	// Конструктор
	InputManager();
	// Метод для получения действия от пользователя
	Action getAction();
private:
	// Метод для преобразования символа клавиши в действие
	Action convertKeyToAction(char key);
};