#pragma once

class Door {
private:
    int coordX, coordY;
    char doorType;  // 'L' для Light, 'S' для Shadow
    bool isActive;
    int requiredCrystals;  // сколько кристаллов нужно для активации

public:
    Door(int startX, int startY, char type, int required = 1);

    // Геттеры
    int getX() const;
    int getY() const;
    char getDoorType() const;
    bool getIsActive() const;
    int getRequiredCrystals() const;

    // Методы для управления состоянием
    void activate();
    void deactivate();
    bool canEnter(char playerType, int playerCrystals) const;

    // Демонстрация работы с указателями
    void setPosition(int newX, int newY);
};