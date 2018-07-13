#ifndef GBUTTON_H_INCLUDED
#define GBUTTON_H_INCLUDED

#include <vector>
#include <SDL2/SDL.h>
#include "common.h"

class gButton
{
private:
    SDL_Rect box;

    SDL_Rect* clip;

    SDL_Renderer* m_renderer;
    int current_sprite = 1;

    std::vector<SDL_Surface*> list_sprites;

public:
    gButton();
    gButton(SDL_Renderer* m_renderer, std::string p_sprite1, std::string p_sprite2);
    SDL_Surface* get_current_sprite(void);
    void setSpritefromEvent(SDL_Event pmotion);
};

#endif // GBUTTON_H_INCLUDED
