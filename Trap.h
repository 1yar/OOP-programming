#pragma once

class Trap {
private:
    int coordX, coordY;
    char symbol;
    char trapType;
    bool isActive;

public:
    Trap(int startX, int startY, char trapSymbol, char type);
    virtual ~Trap() = default;

    int getX() const;
    int getY() const;
    char getSymbol() const;
    char getTrapType() const;
    bool getIsActive() const;

    void activate();
    void deactivate();
};
