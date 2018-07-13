#include "common.h"
#include "gButton.h"

gButton::gButton(SDL_Renderer * m_renderer, string p_sprite1, string p_sprite2)
{
    SDL_Surface* l_sprite1;
    SDL_Surface* l_sprite2;

    this->m_renderer = m_renderer;

    l_sprite1 = SDL_LoadBMP(p_sprite1.c_str());
    this->list_sprites.push_back(l_sprite1);

    l_sprite2 = SDL_LoadBMP(p_sprite2.c_str());
    this->list_sprites.push_back(l_sprite2);

}
