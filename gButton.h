#ifndef GBUTTON_H_INCLUDED
#define GBUTTON_H_INCLUDED

#include <vector>
#include <SDL2/SDL.h>
#include "common.h"

class gButton
{
private:
    SDL_Rect* clip;

    SDL_Renderer* m_renderer;
    int current_sprite = 0;

    std::vector<SDL_Surface*> list_sprites;

public:
    SDL_Rect box;

/* Constructor*/
    gButton();
    gButton(SDL_Renderer* m_renderer, SDL_Rect p_rec, std::string p_sprite1, std::string p_sprite2);

    SDL_Surface* get_current_sprite(void);
    int get_current_sprite_number(void);
    void Switch_sprite(void);
};

#endif // GBUTTON_H_INCLUDED
