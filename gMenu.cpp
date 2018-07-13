#include "gMenu.h"
#include "gButton.h"
#include "common.h"

gMenu::gMenu(ty_param p_param)
{
    this->s_context.m_window = p_param.m_window;
    this->s_context.m_renderer = p_param.m_renderer;

    this->init_menu();
}

void gMenu::init_menu(void)
{

// Create first Button
    gButton m_button1(this->s_context.m_renderer,"./data/Button1.bmp","./data/Button2.bmp");

    list_buttons.push_back(m_button1);

// Create second Button
//    gButton m_button2(this->m_param.m_renderer,"","");
//
//    list.push_back(m_button2);

}

void gMenu::displayMenu(void)
{
//    for( int i = 0; i <= list_buttons.size(); i++)
//    {
    gButton pButton;

    pButton = list_buttons[0];

    SDL_Surface* l_sprite = pButton.get_current_sprite();

    if (l_sprite)
    {

        SDL_Texture* pTexture = SDL_CreateTextureFromSurface(this->s_context.m_renderer,l_sprite); // Préparation du sprite

        if (pTexture)
        {
            SDL_Rect dest= { 800/2 - l_sprite->w/2,600/2 - l_sprite->h/2, l_sprite->w, l_sprite->h};
            SDL_RenderCopy(this->s_context.m_renderer,pTexture,NULL,&dest); // Copie du sprite grâce au SDL_Renderer
        }

        SDL_RenderPresent(this->s_context.m_renderer); // Affichage
        SDL_Delay(3000); /* Attendre trois secondes, que l'utilisateur voit la fenêtre */

        SDL_DestroyTexture(pTexture); // Libération de la mémoire associée à la texture

        SDL_FreeSurface(l_sprite); // Libération de la ressource occupée par le sprite

    }

}
