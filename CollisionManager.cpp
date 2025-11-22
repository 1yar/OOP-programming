#include "CollisionManager.hpp"
#include "Level.hpp"
#include <iostream>
CollisionManager::CollisionManager() {};
bool CollisionManager::canMoveTo(const Level& level, int x, int y) const
{
	char cell = level.getCell(x, y);
	return (cell == ' ');
}
bool CollisionManager::checkWallCollision(const Level& level, int x, int y) const
{
	char cell = level.getCell(x, y);
	return (cell == 'X');
}
bool CollisionManager::checkTrapCollision(const Level& level, int x, int y) const
{
	char cell = level.getCell(x, y);
	if (level.getLightPlayer()) return (cell == '*');
	if (level.getShadowPlayer()) return (cell == '$');
}