#pragma once

class Collectible {
private:
    int coordX, coordY;
    char symbol;
    bool isActive;
    char orbType;

public:
    Collectible(int startX, int startY, char collectibleSymbol, char type);

    int getX() const;
    int getY() const;
    char getSymbol() const;
    bool getIsActive() const;
    char getOrbType() const;

    void collect();
};