#ifndef GBUTTON_H_INCLUDED
#define GBUTTON_H_INCLUDED

#include <vector>
#include <SDL2/SDL.h>
#include "common.h"

class gButton
{
private:
    int x;
    int y;
    int width;
    int height;
    SDL_Renderer* m_renderer;
    int current_sprite = 0;

    std::vector<SDL_Surface*> list_sprites;

public:
    SDL_Surface* get_current_sprite(void);
    gButton(SDL_Renderer* m_renderer, std::string p_sprite1, std::string p_sprite2);
    gButton();
};

#endif // GBUTTON_H_INCLUDED
