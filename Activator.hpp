#pragma once
#include <string>
class Level;
class Character;
class Activator
{
public:
	// Типы активаторов
	enum class Type
	{
		LEVER, // Рычаг - активируется по Enter
		BUTTON // Кнопка - активируется автоматически при "нажатии"
	};
	// Состояние активатора
	enum class State
	{
		ACTIVE, // Активирован
		INACTIVE // Не активирован
	};
private:
	Type type; // Тип активатора
	State state; // Текущее состояние
	int coordX, coordY; // Координаты на карте
	char symbol; // Символ для отображения
public:
	// Конструктор
	Activator(Type activatorType, int x, int y);
	// Геттеры
	Type getType() const;
	State getState() const;
	int getX() const;
	int getY() const;
	char getSymbol() const;
	std::string getStateText() const;
	// Основные методы
	void activate(); // Активировать
	void deactivate(); // Деактивировать
	void toggle(); // Переключить состояние
	// Методы для проверки взаимодействия
	bool canLeverBeActivated(const Character* player, const Level& level) const;
	bool canButtonBeActivated(const Character* player, const Level& level) const;
	bool isPlayerNearby(const Character* player, const Level& level) const;
	// Метод для установки позиции
	void setPosition(int x, int y);
	// Метод для обновления символа в зависимости от состояния
	void updateSymbol();
};