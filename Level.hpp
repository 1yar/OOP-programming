#pragma once
#include <vector>
#include <string>
#include "Character.hpp"
class CollisionManager;
class Level
{
private:
	std::vector<std::string> grid;
	int width, height;
	Character* lightPlayer;
	Character* shadowPlayer;
	CollisionManager* collisionManager;
public:
	Level();
	~Level();
	void draw() const;
	void loadLevel();
	void spawnPlayers(int lightX, int lightY, int shadowX, int shadowY);
	void updatePlayerPosition(Character* player, int dx, int dy);
	Character* getLightPlayer() const;
	Character* getShadowPlayer() const;
	char getCell(int x, int y) const;
	void setCell(int x, int y, char symbol);
	bool isPositionValid(int x, int y) const;
private:
	void clearPlayerPosition(int x, int y);
};