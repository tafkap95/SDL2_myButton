#ifndef GMENU_H_INCLUDED
#define GMENU_H_INCLUDED

#include <vector>
#include <SDL2/SDL.h>
#include "common.h"
#include "gButton.h"

using namespace std;

class gMenu
{
private:
    int x;
    int y;
    int w;
    int h;
    vector<gButton> list_buttons;
    ty_param s_context;

public:
    void init_menu(void);
    gMenu(ty_param);
    void displayMenu(SDL_Event pevent);
    void ControlButtonEvents(SDL_MouseMotionEvent pMotion);
    bool isInRectangle(SDL_MouseMotionEvent pmotion, SDL_Rect prect);
};

#endif // GMENU_H_INCLUDED
