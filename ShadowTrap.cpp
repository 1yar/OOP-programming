#include "ShadowTrap.h"
#include <iostream>

ShadowTrap::ShadowTrap(int startX, int startY)
    : Trap(startX, startY, 's', 'S')
{
    std::cout << "Создана ShadowTrap в позиции (" << startX << ", " << startY << ")" << std::endl;
}