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
    vector<gButton>::iterator it;

    for( it = list_buttons.begin(); it != list_buttons.end(); it++)
    {
        //gButton m_button = list_buttons[i];
    }
}
