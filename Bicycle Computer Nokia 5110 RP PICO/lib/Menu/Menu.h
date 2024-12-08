#ifndef MENU_H
#define MENU_H

#include <Arduino.h>
#include <string>

class MenuManager
{
    MenuPage* currentMenuPage = nullptr;

public:
    //Page pageID = Page::home;
    void changeMenuPage(MenuPage *newMenuPage);
    void update();
    void draw();
};

enum class Page : int16_t
{
    home
};

class MenuPage
{
public:  
    // std::vector<MenuElement*> elements;
};

class MenuElement
{
public:
    std::string name = "";
    bool selected = false;

    void update();
};

class MenuSlider : public MenuElement
{
public:

};

class MenuValue : public MenuElement
{
public:
    int16_t value;
    int16_t min, max;
};

class MenuToggle : public MenuElement
{
};

class MenuButton : public MenuElement
{
public:
    MenuButton(std::string name);
};

//********************************************************************************
//*************************MENU PAGES*********************************************

class MainMenu : public MenuPage
{
    MenuButton* testButton;

public:
    MainMenu();
};

#endif

//*************************************Temp*********************************************** */
//*************************************Temp*********************************************** */