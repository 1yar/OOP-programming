#include "GameManager.hpp"
#include "Level.hpp"
#include "InputManager.hpp"
#include <iostream>
#include <thread>
GameManager::GameManager()
	: currentLevel(nullptr), gameRunning(true),
	lever1(nullptr), lever2(nullptr), button1(nullptr)
{
	currentLevel = new Level();
	inputManager = new InputManager();
}
GameManager::~GameManager()
{
	delete currentLevel;
	delete inputManager;
	delete lever1;
	delete lever2;
	delete button1;
}
void GameManager::runGame()
{
	initializeLevel();
	while (isGameRunning())
	{
		processInput();
		currentLevel->draw();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}
void GameManager::initializeLevel()
{
	currentLevel = new Level();
	currentLevel->spawnPlayers(2, 13, 17, 13);
	lever1 = new Activator(Activator::Type::LEVER, 10, 13);
	currentLevel->setCell(lever1->getX(), lever1->getY(), lever1->getSymbol());
	lever2 = new Activator(Activator::Type::LEVER, 20, 13);
	currentLevel->setCell(lever2->getX(), lever2->getY(), lever2->getSymbol());
	button1 = new Activator(Activator::Type::BUTTON, 15, 13);
	currentLevel->setCell(button1->getX(), button1->getY(), button1->getSymbol());
}
void GameManager::processInput()
{
	InputManager::Action action = inputManager->getAction();
	switch (action)
	{
	case InputManager::Action::LIGHT_LEFT:
		currentLevel->updatePlayerPosition(currentLevel->getLightPlayer(), -1, 0);
		if (checkLeverActivation()) std::cout << "Можно активировать рычаг";
		checkButtonActivation();
		break;
	case InputManager::Action::LIGHT_RIGHT:
		currentLevel->updatePlayerPosition(currentLevel->getLightPlayer(), 1, 0);
		if (checkLeverActivation()) std::cout << "Можно активировать рычаг";
		checkButtonActivation();
		break;
	case InputManager::Action::LIGHT_JUMP:
		currentLevel->getLightPlayer()->jump(currentLevel);
		if (checkLeverActivation()) std::cout << "Можно активировать рычаг";
		checkButtonActivation();
		break;
	case InputManager::Action::SHADOW_LEFT:
		currentLevel->updatePlayerPosition(currentLevel->getShadowPlayer(), -1, 0);
		if (checkLeverActivation()) std::cout << "Можно активировать рычаг";
		checkButtonActivation();
		break;
	case InputManager::Action::SHADOW_RIGHT:
		currentLevel->updatePlayerPosition(currentLevel->getShadowPlayer(), 1, 0);
		if (checkLeverActivation()) std::cout << "Можно активировать рычаг";
		checkButtonActivation();
		break;
	case InputManager::Action::SHADOW_JUMP:
		currentLevel->getShadowPlayer()->jump(currentLevel);
		if (checkLeverActivation()) std::cout << "Можно активировать рычаг";
		checkButtonActivation();
		break;
	case InputManager::Action::ACTIVATE:
		leverActivation();
		break;
	case InputManager::Action::EXIT:
		stopGame();
		break;
	default:
		break;
	}
}
bool GameManager::checkLeverActivation()
{
	if (lever1->canLeverBeActivated(currentLevel->getLightPlayer(), *currentLevel) ||
		lever1->canLeverBeActivated(currentLevel->getShadowPlayer(), *currentLevel)
		|| lever2->canLeverBeActivated(currentLevel->getLightPlayer(), *currentLevel)
		||
		lever2->canLeverBeActivated(currentLevel->getShadowPlayer(), *currentLevel))
	{
		return true;
	}
}
void GameManager::leverActivation()
{
	// Проверяем и активируем рычаги
	if (lever1->canLeverBeActivated(currentLevel->getLightPlayer(), *currentLevel) ||
		lever1->canLeverBeActivated(currentLevel->getShadowPlayer(), *currentLevel))
	{
		lever1->toggle();
		currentLevel->setCell(lever1->getX(), lever1->getY(), lever1->getSymbol());
	}
	if (lever2->canLeverBeActivated(currentLevel->getLightPlayer(), *currentLevel) ||
		lever2->canLeverBeActivated(currentLevel->getShadowPlayer(), *currentLevel))
	{
		lever2->toggle();
		currentLevel->setCell(lever2->getX(), lever2->getY(), lever2->getSymbol());
	}
}
void GameManager::checkButtonActivation()
{
	if (button1->canButtonBeActivated(currentLevel->getLightPlayer(), *currentLevel) ||
		button1->canButtonBeActivated(currentLevel->getShadowPlayer(), *currentLevel))
	{
		button1->activate();
		currentLevel->setCell(button1->getX(), button1->getY(), button1->getSymbol());
	}
	else
	{
		button1->deactivate();
		currentLevel->setCell(button1->getX(), button1->getY(), button1->getSymbol());
	}
}
void GameManager::stopGame()
{
	gameRunning = false;
}
bool GameManager::isGameRunning() const
{
	return gameRunning;
}