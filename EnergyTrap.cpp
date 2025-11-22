#include "EnergyTrap.h"
#include <iostream>

EnergyTrap::EnergyTrap(int startX, int startY)
    : Trap(startX, startY, 'e', 'E')
{
    std::cout << "Создана EnergyTrap в позиции (" << startX << ", " << startY << ")" << std::endl;
}