#include "LightTrap.h"
#include <iostream>

LightTrap::LightTrap(int startX, int startY)
    : Trap(startX, startY, 'l', 'L')
{
    std::cout << "Создана LightTrap в позиции (" << startX << ", " << startY << ")" << std::endl;
}