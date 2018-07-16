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
    SDL_Rect l_rect;

    l_rect.x = 50;
    l_rect.y = 50;
    l_rect.w = 200;
    l_rect.h = 100;

// Create first Button
    gButton m_button1(this->s_context.m_renderer,l_rect, "./data/Button1.bmp","./data/Button2.bmp");
    list_buttons.push_back(m_button1);

// Create second Button
//    gButton m_button2(this->m_param.m_renderer,"","");
//
//    list.push_back(m_button2);

}

void gMenu::ControlButtonEvents(SDL_MouseMotionEvent pMotion)
{
    gButton c_button;
    bool    l_ret;

    for(int i=0; i<=0; i++)
    {
        c_button = list_buttons[i];

        l_ret = this->isInRectangle(pMotion, c_button.box);

        if (l_ret==true)
        {
            c_button.Switch_sprite();
            printf("Rectangle OK\n");
        }
        else
        {
            printf("Rectangle KO\n");
        }
    }
}

bool gMenu::isInRectangle(SDL_MouseMotionEvent pmotion, SDL_Rect prect)
{
    int x3;
    int y3;
    bool ret = false;

    x3 = prect.x + prect.w;
    y3 = prect.y + prect.h;

    if ((pmotion.x >= prect.x && pmotion.x <= x3) && (pmotion.y >= prect.y && pmotion.y <= y3) )
    {
        ret = true;
    }

    return ret;
}

void gMenu::displayMenu(SDL_Event event)
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
            SDL_Rect dest = {pButton.box.x, pButton.box.y, pButton.box.w, pButton.box.h};
            SDL_RenderCopy(this->s_context.m_renderer,pTexture,NULL,&dest); // Copie du sprite grâce au SDL_Renderer
        }

        SDL_RenderPresent(this->s_context.m_renderer); // Affichage

        SDL_DestroyTexture(pTexture); // Libération de la mémoire associée à la texture

        //SDL_FreeSurface(l_sprite); // Libération de la ressource occupée par le sprite

    }
}
