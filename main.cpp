#include "stdafx.h"
#include "Engine.h"
#include "World.h"

// 사용할 라이브러리 파일 추가
#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main")

int SDL_main(int argc, char* argv[])
{
	bool bIsRunning = true;

	// Initialize
	SDL_Init(SDL_INIT_EVERYTHING);			// `SDL_INIT_EVERYTHING`: all of the above subsystems
	// Create Window
	SDL_Window* Window = SDL_CreateWindow("SDL Engine", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	// Create Renderer
	SDL_Renderer* Renderer = SDL_CreateRenderer(Window, -1, 0);
	
	// Running
	while (bIsRunning)
	{
		// Event Polling
		SDL_Event Event;
		SDL_PollEvent(&Event);

		switch (Event.type)
		{
		case SDL_QUIT:
			bIsRunning = false;
			break;
		default:
			break;
		}

		// Clear 
		SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);
		SDL_RenderClear(Renderer);

		int RectCounts = 100;
		SDL_Rect* Rects = new SDL_Rect[RectCounts];

		for (int i = 0; i < RectCounts; ++i)
		{
			Uint8 ColorR = rand() % 255 + 1;
			Uint8 ColorG = rand() % 255 + 1;
			Uint8 ColorB = rand() % 255 + 1;
			SDL_SetRenderDrawColor(Renderer, ColorR, ColorG, ColorB, 255);

			int RectX = rand() % 640;
			int RectY = rand() % 480;
			int RectW = rand() % 100 + 1;
			int RectH = rand() % 100 + 1;
			SDL_Rect Rect = { RectX, RectY, RectW, RectH };

			int Fill = rand() % 2;
			if (Fill)
			{
				SDL_RenderFillRect(Renderer, &Rect);
			}			

			SDL_RenderDrawRect(Renderer, &Rect);
		}
		
		delete[] Rects;

		// Render
		SDL_RenderPresent(Renderer);
	}

	// Destroy Renderer
	SDL_DestroyRenderer(Renderer);
	// Destroy Window
	SDL_DestroyWindow(Window);

	// Quit (Terminate)
	SDL_Quit();
	return 0;
}

//int main()
//{
//	GEngine->GetWorld()->Load("NewLevel.txt");
//
//	GEngine->Run();
//
//	delete GEngine;
//
//	return 0;
//}