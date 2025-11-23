#include "Door.h"
#include <iostream>

Door::Door(int startX, int startY, char type, int required)
    : coordX(startX), coordY(startY), doorType(type),
    isActive(false), requiredCrystals(required) {
}

int Door::getX() const {
    return coordX;
}

int Door::getY() const {
    return coordY;
}

char Door::getDoorType() const {
    return doorType;
}

bool Door::getIsActive() const {
    return isActive;
}

int Door::getRequiredCrystals() const {
    return requiredCrystals;
}

void Door::activate() {
    isActive = true;
}

void Door::deactivate() {
    isActive = false;
}

bool Door::canEnter(char playerType, int playerCrystals) const {
    return (playerType == doorType) && isActive &&
        (playerCrystals >= requiredCrystals);
}

void Door::setPosition(int newX, int newY) {
    coordX = newX;
    coordY = newY;
}