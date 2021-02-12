#include "Main.h" 
#include "Display.h" // This allows the use of win, ren and the eve variables which originate in the Display module
#include <stdio.h>

static double s = 1;
static double mx = 0 ;
static double my = 0 ;

// The mandelbrot set shit
int main(void)
{
	Init_Display() ;

	int playing = 1 ;
	int refresh = 1 ;

	while(playing)
	{
		while(SDL_PollEvent(&eve))
		{
			if( eve.type == SDL_QUIT ) playing = 0 ;
			if( eve.type == SDL_KEYDOWN )
			{
				switch(eve.key.keysym.sym)
				{
					case SDLK_r: 
						refresh = 1 ; 
						printf("Refreshing screen...\n") ;
				     	break ;
					case SDLK_d:
						s+=0.1 ;
						printf("Zooming in...\n") ;
					break ;
					case SDLK_f:
						s-=0.1 ;
						printf("Zooming out..\n") ;
					break ;
					case SDLK_j:
						my+=0.1 ;
					break ;
					case SDLK_k:
						my-=0.1 ;
					break ;
					case SDLK_h:
						mx-=0.1 ;
					break ;
					case SDLK_l:
						mx+=0.1 ;
					break ;
				}
				refresh = 1 ;
			}
		}

		if( refresh )
		{
			SDL_RenderClear(ren) ;
			MBrot() ;
			SDL_RenderPresent(ren) ;
			printf("Screen refreshed...\n");
		}

		refresh = 0 ;
	}

	Dinit_Display(); 
	return 0 ;
}

#define BOUNDING (5)
#define MAX_ITERATION (100)

static double map(double, double, double ,double, double) ;
void MBrot(void)
{
	for( int i = 0 ; i < WINDOW_HEIGHT ; i++ )
		for( int j = 0 ; j < WINDOW_WIDTH ; j++ )
		{
			
			double xi = map(0.0, WINDOW_WIDTH*1.0, -2.0/s+mx, 1.0/s+mx, j * 1.0) ;
			double yi = map(0.0, WINDOW_HEIGHT*1.0, -1.0/s+my, 1.0/s+my, i * 1.0) ;

			double x = 0 ; 
			double y = 0 ;

			int inter = 0 ;
			while( x*x + y*y <= BOUNDING*BOUNDING && inter < MAX_ITERATION)
			{
				double xt = x*x - y*y + xi ;
				y = 2*x*y + yi ;
				x = xt ;
				inter++ ;
			}
			
			switch(inter % 5)
			{
				case 0:
					SDL_SetRenderDrawColor(ren,0,0,0,255) ;
				break;
				case 1:
					SDL_SetRenderDrawColor(ren,100,54,201,255) ;
				break;
				case 2:
					SDL_SetRenderDrawColor(ren,54,201,152,255) ;
				break ;
				case 3:
					SDL_SetRenderDrawColor(ren,201,194,54,255) ;
				break ;
				case 4:
					SDL_SetRenderDrawColor(ren,201,54,189,255) ;	
				break ;
			}


			SDL_RenderDrawPoint(ren, j, i) ;
		}
}

double map(double a1,double a2,double b1,double b2,double s)
{
	return b1 + (s-a1)*(b2-b1)/(a2-a1);
}
