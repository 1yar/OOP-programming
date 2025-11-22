#pragma once
#include <vector>
#include <string>
#include "LightCharacter.h"
#include "ShadowCharacter.h"
#include "Platform.h"
#include "Collectible.h"
#include "LightTrap.h"    
#include "ShadowTrap.h"  
#include "EnergyTrap.h" 
#include "Door.h"
class CollisionManager;

class Level {
private:
    std::vector<std::string> grid;
    std::vector<Platform*> platforms;  // Вектор для платформ
    std::vector<Collectible*> collectibles; // Вектор для кристаллов
    std::vector<Trap*> traps;  // Один вектор для всех типов ловушек
    std::vector<Door*> doors;  // Вектор для дверей
    int lightScore;  // Счет Light игрока
    int shadowScore; // Счет Shadow игрока
    int width;
    int height;
    LightCharacter* lightPlayer;
    ShadowCharacter* shadowPlayer;
    CollisionManager* collisionManager;

public:
    Level();
    ~Level();

    void draw() const;
    void loadLevel();
    void spawnPlayers(int lightX, int lightY, int shadowX, int shadowY);
    void updatePlayerPosition(Character* player, int dx, int dy);

    LightCharacter* getLightPlayer() const;
    ShadowCharacter* getShadowPlayer() const;

    char getCell(int x, int y) const;
    void setCell(int x, int y, char symbol);
    bool isPositionValid(int x, int y) const;

private:
    void clearPlayerPosition(int x, int y);
};