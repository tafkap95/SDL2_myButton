#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

struct ty_param
{
   SDL_Window* m_window = nullptr;
   SDL_Renderer* m_renderer = nullptr;
};

#endif // COMMON_H_INCLUDED
