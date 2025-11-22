#include "Trap.h"

Trap::Trap(int startX, int startY, char trapSymbol, char type)
    : coordX(startX), coordY(startY), symbol(trapSymbol), trapType(type), isActive(true) {
}

int Trap::getX() const {
    return coordX;
}

int Trap::getY() const {
    return coordY;
}

char Trap::getSymbol() const {
    return symbol;
}

char Trap::getTrapType() const {
    return trapType;
}

bool Trap::getIsActive() const {
    return isActive;
}

void Trap::activate() {
    isActive = true;
}

void Trap::deactivate() {
    isActive = false;
}