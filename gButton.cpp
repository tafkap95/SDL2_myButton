#include "common.h"
#include "gButton.h"

gButton::gButton()
{

}

gButton::gButton(SDL_Renderer * m_renderer, SDL_Rect p_rect, string p_sprite1, string p_sprite2)
{
    SDL_Surface* l_sprite1;
    SDL_Surface* l_sprite2;

    this->box = p_rect;

    this->m_renderer = m_renderer;

    l_sprite1 = SDL_LoadBMP(p_sprite1.c_str());
    this->list_sprites.push_back(l_sprite1);

    l_sprite2 = SDL_LoadBMP(p_sprite2.c_str());
    this->list_sprites.push_back(l_sprite2);
}

SDL_Surface* gButton::get_current_sprite(void)
{
    return this->list_sprites[current_sprite];
}

int gButton::get_current_sprite_number(void)
{
    return this->current_sprite;
}

void gButton::Switch_sprite(void)
{
    this->current_sprite++;

    if (this->current_sprite>this->list_sprites.size()) this->current_sprite = 0;
}
