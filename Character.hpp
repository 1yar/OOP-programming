#pragma once
class Level;
class Character
{
public:
	// Типы персонажей
	enum class Type
	{
		LIGHT,
		SHADOW
	};
private:
	Type type; // Тип персонажа (Свет/Тень)
	int coordX, coordY; // Координаты
	char symbol; // Символ для отображения
	bool isGrounded; // Статус (на земле/не на земле)
public:
	// Конструктор
	Character(Type characterType, int startX, int startY);
	// Геттеры
	Type getType() const;
	int getX() const;
	int getY() const;
	char getSymbol() const;
	bool getIsGrounded() const;
	// Сеттеры
	void setPosition(int newX, int newY);
	void setGrounded(bool grounded);
	// Метод для движения
	void move(int dx, int dy);
	// Метод для прыжка
	void jump(Level* currentLevel);
};