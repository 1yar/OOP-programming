#include "Level.hpp"
#include "CollisionManager.hpp"
#include "Character.hpp"
#include <iostream>
Level::Level()
	: width(0), height(0), lightPlayer(nullptr), shadowPlayer(nullptr)
{
	collisionManager = new CollisionManager();
	loadLevel();
}
Level::~Level()
{
	delete lightPlayer;
	delete shadowPlayer;
	delete collisionManager;
}
Character* Level::getLightPlayer() const
{
	return lightPlayer;
}
Character* Level::getShadowPlayer() const
{
	return shadowPlayer;
}
void Level::spawnPlayers(int lightX, int lightY, int shadowX, int shadowY)
{
	delete lightPlayer;
	delete shadowPlayer;
	lightPlayer = new Character(Character::Type::LIGHT, lightX, lightY);
	shadowPlayer = new Character(Character::Type::SHADOW, shadowX, shadowY);
	lightPlayer->setGrounded(true);
	shadowPlayer->setGrounded(true);
	setCell(lightX, lightY, 'L');
	setCell(shadowX, shadowY, 'S');
}
void Level::updatePlayerPosition(Character* player, int dx, int dy)
{
	if (!player) return;
	int oldX = player->getX();
	int oldY = player->getY();
	int newX = oldX + dx;
	int newY = oldY + dy;
	if (!isPositionValid(newX, newY) || !collisionManager->canMoveTo(*this, newX, newY))
	{
		return;
	}
	clearPlayerPosition(oldX, oldY);
	player->move(dx, dy);
	setCell(newX, newY, player->getSymbol());
}
void Level::clearPlayerPosition(int x, int y)
{
	if (isPositionValid(x, y))
	{
		grid[y][x] = ' ';
	}
}
void Level::loadLevel() {
	grid.clear();
	grid.push_back("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
	grid.push_back("X X");
	grid.push_back("X X");
	grid.push_back("X X");
	grid.push_back("X X");
	grid.push_back("X X");
	grid.push_back("X X");
	grid.push_back("X X");
	grid.push_back("X X");
	grid.push_back("X X");
	grid.push_back("X X");
	grid.push_back("X X");
	grid.push_back("X X");
	grid.push_back("X X");
	grid.push_back("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
	height = grid.size();
	width = grid[0].size();
}
void Level::draw() const {
	system("cls");
	for (const auto& row : grid)
	{
		std::cout << row << std::endl;
	}
}
char Level::getCell(int x, int y) const
{
	return grid[y][x];
}
void Level::setCell(int x, int y, char symbol)
{
	grid[y][x] = symbol;
}
bool Level::isPositionValid(int x, int y) const
{
	return !grid.empty() && x >= 0 && x < width && y >= 0 && y < height;
}