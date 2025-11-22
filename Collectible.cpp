#include "Collectible.h"

Collectible::Collectible(int startX, int startY, char collectibleSymbol, char type)
    : coordX(startX), coordY(startY), symbol(collectibleSymbol), isActive(true), orbType(type) {
}

int Collectible::getX() const {
    return coordX;
}

int Collectible::getY() const {
    return coordY;
}

char Collectible::getSymbol() const {
    return symbol;
}

bool Collectible::getIsActive() const {
    return isActive;
}

char Collectible::getOrbType() const {
    return orbType;
}

void Collectible::collect() {
    isActive = false;
}