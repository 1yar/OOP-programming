#include "Platform.h"

Platform::Platform(int startX, int startY, char platformSymbol, int platformWidth)
    : coordX(startX), coordY(startY), width(platformWidth), symbol(platformSymbol) {
}

int Platform::getX() const {
    return coordX;
}

int Platform::getY() const {
    return coordY;
}

int Platform::getWidth() const {
    return width;
}

char Platform::getSymbol() const {
    return symbol;
}

bool Platform::isOnPlatform(int x, int y) const {
    return (y == coordY && x >= coordX && x < coordX + width);
}
