#define _USE_MATH_DEFINES

#include<stdio.h>
#include<stdlib.h>
#include"Board.h"
#include"Player.h"

extern "C" {
	//#ifdef BIT64
	//#include"./sdl64/include/SDL.h"
	//#include"./sdl64/include/SDL_main.h"
	//#else
#include"./sdl/include/SDL.h"
#include"./sdl/include/SDL_main.h"
	//#endif
}

#define SCREEN_WIDTH	640
#define SCREEN_HEIGHT	640
#define POSITIONCHANGE 8 //zmiana po³o¿enia o 8 pikseli w trakcie jednego ruchu

#ifdef __cplusplus
extern "C"
#endif
int main(int argc, char **argv) {
	int  quit = 0, frames, rc;
	SDL_Event event;
	SDL_Surface *screen;
	SDL_Texture *scrtex;
	SDL_Window *window;
	SDL_Renderer *renderer;
	//--------------------------------INICJALIZACJA EKRANU GRY-------------------------
	if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO) != 0) {
		printf("SDL_Init error: %s\n", SDL_GetError());
		return 1;
	}
	// tryb pe³noekranowy
	//	rc = SDL_CreateWindowAndRenderer(0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP,
	//	                                 &window, &renderer);
	rc = SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0,
		&window, &renderer);
	if (rc != 0) {
		SDL_Quit();
		printf("SDL_CreateWindowAndRenderer error: %s\n", SDL_GetError());
		return 1;
	};

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	SDL_SetWindowTitle(window, "Bomberman"); //tytu³

	screen = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32,
		0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);

	scrtex = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STREAMING,
		SCREEN_WIDTH, SCREEN_HEIGHT);

	// wy³¹czenie widocznoœci kursora myszy
	SDL_ShowCursor(SDL_DISABLE);

	Player player(48, 48);//pocz¹tkowa pozycja gracza
	Board board("etap.txt", screen, &player);//za³adowanie planszy 

	//-------------------------------------G£OWNA PÊTLA----------------------------------------
	while (!quit) {	
		board.Play();
		SDL_UpdateTexture(scrtex, NULL, screen->pixels, screen->pitch);
		SDL_RenderCopy(renderer, scrtex, NULL, NULL);
		SDL_RenderPresent(renderer);

		// obs³uga zdarzeñ 
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_KEYDOWN: //naciœniêcie przycisku na klaw.
				if (event.key.keysym.sym == SDLK_ESCAPE) quit = 1;
				else if (event.key.keysym.sym == SDLK_UP) player.Move(0,-POSITIONCHANGE);
				else if (event.key.keysym.sym == SDLK_DOWN) player.Move(0, POSITIONCHANGE);
				else if (event.key.keysym.sym == SDLK_RIGHT) player.Move(POSITIONCHANGE, 0);
				else if (event.key.keysym.sym == SDLK_LEFT) player.Move(-POSITIONCHANGE, 0);
				else if (event.key.keysym.sym == SDLK_SPACE) player.PlantBomb();
				break;
			case SDL_QUIT:
				quit = 1;
				break;
			};
		};
	};

	// zwolnienie powierzchni
	SDL_FreeSurface(screen);
	SDL_DestroyTexture(scrtex);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
	return 0;
};
