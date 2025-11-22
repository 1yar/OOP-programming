#pragma once
#include "Activator.hpp"
class Level;
class InputManager;
class Character;
class GameManager
{
private:
	Level* currentLevel;
	InputManager* inputManager;
	bool gameRunning;
	Activator* lever1;
	Activator* lever2;
	Activator* button1;
public:
	GameManager();
	~GameManager();
	void runGame();
	void initializeLevel();
	void processInput();
	bool checkLeverActivation();
	void leverActivation();
	void checkButtonActivation();
	void stopGame();
private:
	bool isGameRunning() const;
};