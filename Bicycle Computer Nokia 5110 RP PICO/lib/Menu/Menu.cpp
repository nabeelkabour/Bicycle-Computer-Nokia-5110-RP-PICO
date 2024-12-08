#include "Menu.h"

void MenuManager::update()
{
    if(currentMenuPage == nullptr) return;

    currentMenuPage->update();
}

MainMenu::MainMenu()
{
    testButton = new MenuButton();
}

void MenuManager::draw()
{

}