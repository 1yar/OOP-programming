#include "Character.hpp"
#include "Level.hpp"
#include <iostream>
#include <thread>
// Конструктор: инициализирует персонажа с заданным типом и позицией
Character::Character(Type characterType, int startX, int startY)
	: type(characterType), coordX(startX), coordY(startY), isGrounded(false)
{
	// Устанавливаем символ в зависимости от типа персонажа
	switch (type)
	{
	case Type::LIGHT:
		symbol = 'L';
		break;
	case Type::SHADOW:
		symbol = 'S';
		break;
	}
}
// Возвращает тип персонажа
Character::Type Character::getType() const
{
	return type;
}
// Возвращает координату по x
int Character::getX() const
{
	return coordX;
}
// Возвращает координату по y
int Character::getY() const
{
	return coordY;
}
// Возвращает символ отображения персонажа
char Character::getSymbol() const
{
	return symbol;
}
// Возвращает статус (на земле/не на земле)
bool Character::getIsGrounded() const
{
	return isGrounded;
}
// Установка новой позиции
void Character::setPosition(int newX, int newY)
{
	coordX = newX;
	coordY = newY;
}
// Метод для установки состояния "на земле"
void Character::setGrounded(bool grounded)
{
	isGrounded = grounded;
}
// Метод для перемещения персонажа
void Character::move(int dx, int dy)
{
	coordX += dx;
	coordY += dy;
}
// Метод для прыжка
void Character::jump(Level* currentLevel)
{
	if (isGrounded)
	{
		isGrounded = false;
		currentLevel->updatePlayerPosition(this, 0, -2);
		currentLevel->draw();
		std::thread fallThread([this, currentLevel]()
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(800));
				if (!isGrounded)
				{
					currentLevel->updatePlayerPosition(this, 0, 2);
					isGrounded = true;
					currentLevel->draw();
				}
			});
		fallThread.detach();
	}
}