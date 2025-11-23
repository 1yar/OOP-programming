#include "Level.h"
#include "CollisionManager.h"
#include "LightCharacter.h"
#include "ShadowCharacter.h"
#include <iostream>

//МОИ ИЗМЕНЕНИЯ: 
// добавил счетчики очков
Level::Level()
    : width(0), height(0), lightPlayer(nullptr), shadowPlayer(nullptr),
    lightScore(0), shadowScore(0) {
    collisionManager = new CollisionManager();
    loadLevel();
}

//МОИ ИЗМЕНЕНИЯ 
Level::~Level() {
    delete lightPlayer;
    delete shadowPlayer;
    delete collisionManager;

    for (auto platform : platforms) {
        delete platform;
    }

    for (auto collectible : collectibles) {
        delete collectible;
    }

    for (auto trap : traps) {
        delete trap;
    }

    for (auto door : doors) {
        delete door;
    }
}

LightCharacter* Level::getLightPlayer() const
{
    return lightPlayer;
}

ShadowCharacter* Level::getShadowPlayer() const
{
    return shadowPlayer;
}

void Level::spawnPlayers(int lightX, int lightY, int shadowX, int shadowY) {
    delete lightPlayer;
    delete shadowPlayer;
    lightPlayer = new LightCharacter(lightX, lightY);
    shadowPlayer = new ShadowCharacter(shadowX, shadowY);
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

    if (!collisionManager->isPositionValid(*this, newX, newY) ||
        !collisionManager->canMoveTo(*this, newX, newY))
    {
        return;
    }

    clearPlayerPosition(oldX, oldY);
    player->move(dx, dy);
    setCell(newX, newY, player->getSymbol());
}

void Level::clearPlayerPosition(int x, int y) {
    if (isPositionValid(x, y)) {
        grid[y][x] = ' ';
    }
}

// МОИ ИЗМЕНЕНИЯ
void Level::loadLevel() {
    grid.clear();
    grid.push_back("XXXXXXXXXXXXXXXXXXXX");
    grid.push_back("X                  X");
    grid.push_back("X                  X");
    grid.push_back("X                  X");
    grid.push_back("X                  X");
    grid.push_back("X                  X");
    grid.push_back("X                  X");
    grid.push_back("X                  X");
    grid.push_back("X                  X");
    grid.push_back("X L              S X");
    grid.push_back("XXXXXXXXXXXXXXXXXXXX");

    height = grid.size();
    width = grid[0].size();

    //платформы
    platforms.push_back(new Platform(2, 8, '-'));     // слева
    platforms.push_back(new Platform(14, 8, '-'));    // справа
    platforms.push_back(new Platform(8, 6, '-'));     // Центральная платформа

    // Создание кристалов для сбора очков
    collectibles.push_back(new Collectible(3, 7, 'O', 'L'));
    collectibles.push_back(new Collectible(16, 7, '0', 'S'));
    collectibles.push_back(new Collectible(9, 5, 'O', 'L'));
    collectibles.push_back(new Collectible(11, 5, '0', 'S'));

    // Создание ловушек для создания опасностей
    traps.push_back(new LightTrap(7, 9));   // LightTrap(убивает только Light)
    traps.push_back(new ShadowTrap(11, 9));  // ShadowTrap(убивает только Shadow) 
    traps.push_back(new EnergyTrap(10, 5));  // EnergyTrap(убивает обоих)

    // Создание дверей
    doors.push_back(new Door(5, 5, 'L', 2));   // Дверь для Light, требует 2 кристалла
    doors.push_back(new Door(15, 5, 'S', 2));  // Дверь для Shadow, требует 2 кристалла
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
