#include "Activator.hpp"
#include "Level.hpp"
#include "Character.hpp"
#include <iostream>
// Конструктор
Activator::Activator(Type activatorType, int x, int y)
	: type(activatorType), coordX(x), coordY(y), state(State::INACTIVE)
{
	// Устанавливаем символ и название в зависимости от типа
	switch (type)
	{
	case Type::LEVER:
		symbol = '\\'; // Символ рычага
		break;
	case Type::BUTTON:
		symbol = 'O'; // Символ кнопки
		break;
	}
}
// Геттеры
Activator::Type Activator::getType() const
{
	return type;
}
Activator::State Activator::getState() const
{
	return state;
}
int Activator::getX() const
{
	return coordX;
}
int Activator::getY() const
{
	return coordY;
}
char Activator::getSymbol() const
{
	return symbol;
}
std::string Activator::getStateText() const
{
	return (state == State::ACTIVE) ? "АКТИВИРОВАН" : "НЕ АКТИВИРОВАН";
}
void Activator::updateSymbol()
{
	switch (type)
	{
	case Type::LEVER:
		symbol = (state == State::ACTIVE) ? '\\' : '/';
		break;
	case Type::BUTTON:
		symbol = (state == State::ACTIVE) ? '_' : 'o';
		break;
	}
}
// Активация
void Activator::activate()
{
	state = State::ACTIVE;
	updateSymbol();
}
// Деактивация
void Activator::deactivate()
{
	state = State::INACTIVE;
	updateSymbol();
}
// Переключение состояния
void Activator::toggle()
{
	if (state == State::ACTIVE)
	{
		deactivate();
	}
	else
	{
		activate();
	}
}
// Проверка, может ли игрок активировать этот активатор
bool Activator::canLeverBeActivated(const Character* player, const Level& level) const
{
	if (!player) return false;
	// Для рычага проверяем соседние клетки слева/справа
	if (type == Type::LEVER)
	{
		int playerX = player->getX();
		int playerY = player->getY();
		// Проверяем клетки слева и справа от активатора
		return (playerX == coordX - 1 && playerY == coordY) || // Слева
			(playerX == coordX + 1 && playerY == coordY); // Справа
	}
	// Для кнопки активация автоматическая
	return false;
}
// Проверка автоматической активации (для кнопки)
bool Activator::canButtonBeActivated(const Character* player, const Level& level) const
{
	if (!player || type != Type::BUTTON) return false;
	int playerX = player->getX();
	int playerY = player->getY();
	// Для кнопки проверяем клетку сверху
	return (playerX == coordX && playerY == coordY - 1);
}
// Проверка, находится ли игрок рядом (для отображения подсказки)
bool Activator::isPlayerNearby(const Character* player, const Level& level) const
{
	if (!player) return false;
	int playerX = player->getX();
	int playerY = player->getY();
	if (type == Type::LEVER)
	{
		// Для рычага - слева/справа
		return (playerX == coordX - 1 && playerY == coordY) ||
			(playerX == coordX + 1 && playerY == coordY);
	}
	else
	{
		// Для кнопки - сверху
		return (playerX == coordX && playerY == coordY - 1);
	}
}
// Установка позиции
void Activator::setPosition(int x, int y)
{
	coordX = x;
	coordY = y;
}