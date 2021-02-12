#include "Main.h"

SDL_Window *win ;
SDL_Renderer *ren ;
SDL_Event eve ;

int Init_Display(void)
{
	if( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) ) 
	{
		printf("Could not initialize the SDL library for some reason!!\n") ;
		return -1 ;
	}

	win = SDL_CreateWindow("...",
		       	SDL_WINDOWPOS_UNDEFINED,
		       	SDL_WINDOWPOS_UNDEFINED,
		       	WINDOW_WIDTH,
		       	WINDOW_HEIGHT,
		       	SDL_WINDOW_SHOWN) ;
	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED) ;

	if( win == NULL || ren == NULL )
	{
		printf("Could not create window or renderer\nWIN:%lld\nREN:%lld", (long long int)win, (long long int)ren) ;
		return -1 ;
	}

	return 0;
}

void Dinit_Display(void)
{
	SDL_DestroyRenderer(ren) ; 
	SDL_DestroyWindow(win) ;
	SDL_Quit() ;
}
