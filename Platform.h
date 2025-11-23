#pragma once

class Platform {
private:
    int coordX, coordY;
    int width;
    char symbol;

public:
    Platform(int startX, int startY, char platformSymbol, int platformWidth = 3);

    int getX() const;
    int getY() const;
    int getWidth() const;
    char getSymbol() const;

    bool isOnPlatform(int x, int y) const;
};