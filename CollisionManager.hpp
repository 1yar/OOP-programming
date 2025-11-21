#pragma once
class Level;
class CollisionManager
{
public:
	CollisionManager();
	// Метод для проверки может ли персонаж переместиться в указанную позицию
	bool canMoveTo(const Level& level, int x, int y) const;
	// Метод для проверки столкновение со стеной
	bool checkWallCollision(const Level& level, int x, int y) const;
	// Метод для проверки столкновения с ловушкой
	bool checkTrapCollision(const Level& level, int x, int y) const;
};