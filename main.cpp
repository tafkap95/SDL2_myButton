#include <exception>
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include "gMenu.h"
#include "common.h"

class InitError : public std::exception
{
    std::string msg;
public:
    InitError();
    InitError( const std::string & );
    virtual ~InitError() throw();
    virtual const char * what() const throw();
};

InitError::InitError() :
    exception(),
    msg( SDL_GetError() )
{
}

InitError::InitError( const std::string & m ) :
    exception(),
    msg( m )
{
}

InitError::~InitError() throw()
{
}

const char * InitError::what() const throw()
{
    return msg.c_str();
}

class SDL
{
    SDL_Window * m_window;
    SDL_Renderer * m_renderer;
public:
    SDL_Renderer * getRenderer(void);
    SDL_Window * getWindow(void);
    ty_param getParam(void);
    SDL( Uint32 flags = 0 );
    virtual ~SDL();
    void draw();
};

SDL_Renderer* SDL::getRenderer(void)
{
    return m_renderer;
}

SDL_Window* SDL::getWindow(void)
{
    return m_window;
}


SDL::SDL( Uint32 flags )
{
    if ( SDL_Init( flags ) != 0 )
        throw InitError();

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

    if ( SDL_CreateWindowAndRenderer( 800, 600, SDL_WINDOW_SHOWN, &m_window, &m_renderer ) != 0 )
        throw InitError();
}

ty_param SDL::getParam(void)
{
    ty_param m_param;

    m_param.m_renderer = this->getRenderer();
    m_param.m_window = this->getWindow();

    return m_param;
}

SDL::~SDL()
{
    SDL_DestroyWindow( m_window );
    SDL_DestroyRenderer( m_renderer );
    SDL_Quit();
}

void SDL::draw()
{
    // Clear the window with a black background
    SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
    SDL_RenderClear( m_renderer );

    // Show the window
    SDL_RenderPresent( m_renderer );

    int rgb[] = { 203, 203, 203, // Gray
                  254, 254,  31, // Yellow
                  0, 255, 255, // Cyan
                  0, 254,  30, // Green
                  255,  16, 253, // Magenta
                  253,   3,   2, // Red
                  18,  14, 252, // Blue
                  0,   0,   0  // Black
                };

    SDL_Rect colorBar;
    colorBar.x = 0;
    colorBar.y = 0;
    colorBar.w = 90;
    colorBar.h = 480;

    // Render a new color bar every 0.5 seconds
    for ( int i = 0; i != sizeof rgb / sizeof *rgb; i += 3, colorBar.x += 90 )
    {
        SDL_SetRenderDrawColor( m_renderer, rgb[i], rgb[i + 1], rgb[i + 2], 255 );
        SDL_RenderFillRect( m_renderer, &colorBar );
        SDL_RenderPresent( m_renderer );
        SDL_Delay( 500 );
    }
}

int main( int argc, char * argv[] )
{
    int i;
    char cont = 1; /* Détermine si on continue la boucle principale */
    SDL_Event event;

    try
    {
        SDL sdl( SDL_INIT_VIDEO | SDL_INIT_TIMER );

        gMenu myMenu(sdl.getParam());

        while(cont != 0 )
        {

            while ( SDL_PollEvent(&event) )
            {
                /* Traitement de l'événement */
                switch (event.type) /* Quel événement avons-nous ? */
                {
                case SDL_MOUSEBUTTONDOWN:
                    fprintf(stdout, "Un appuie sur un bouton de la souris :\n");
                    fprintf(stdout, "\tfenêtre : %d\n",event.button.windowID);
                    fprintf(stdout, "\tsouris : %d\n",event.button.which);
                    fprintf(stdout, "\tbouton : %d\n",event.button.button);
#if SDL_VERSION_ATLEAST(2,0,2)
                    fprintf(stdout, "\tclics : %d\n",event.button.clicks);
#endif
                    fprintf(stdout, "\tposition : %d;%d\n",event.button.x,event.button.y);
                    //cin >> i;
                    cont =0;
                    break;
                }

            }

            if (cont != 0)
            {
                myMenu.displayMenu(event);
                SDL_RenderPresent(sdl.getRenderer());
            }

        }

    }
    catch ( const InitError & err )
    {
        std::cerr << "Error while initializing SDL:  "
                  << err.what()
                  << std::endl;
    }
    return 0;
}
