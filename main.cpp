#include "stdafx.h"
#include "Engine.h"
#include "World.h"

// 사용할 라이브러리 파일 추가
#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main")

#define WINDOWX 500
#define WINDOWY 500
#define WINDOWW 640
#define WINDOWH 480

#define PI		3.141592

std::random_device RandomDevice;
std::default_random_engine dre(RandomDevice());

std::uniform_int_distribution<int> uidX(0, WINDOWW);
std::uniform_int_distribution<int> uidY(0, WINDOWH);
std::uniform_int_distribution<int> uidW(0, 30);
std::uniform_int_distribution<int> uidH(0, 30);
std::uniform_int_distribution<int> uidRadius(0, 30);

std::uniform_int_distribution<int> uidR(0, 255);
std::uniform_int_distribution<int> uidG(0, 255);
std::uniform_int_distribution<int> uidB(0, 255);

void DrawRect(SDL_Renderer* Renderer, Uint8 ColorR, Uint8 ColorG, Uint8 ColorB, int RectX, int RectY, int RectW, int RectH, bool bIsFill)
{
	SDL_SetRenderDrawColor(Renderer, ColorR, ColorG, ColorB, 255);
	SDL_Rect Rect = { RectX, RectY, RectW, RectH };
	if (bIsFill)
	{
		SDL_RenderFillRect(Renderer, &Rect);
	}
	else {
		SDL_RenderDrawRect(Renderer, &Rect);
	}
}

void DrawCircle(SDL_Renderer* Renderer, Uint8 ColorR, Uint8 ColorG, Uint8 ColorB, int CenterX, int CenterY, int Radius, bool bIsFill) {
	SDL_SetRenderDrawColor(Renderer, ColorR, ColorG, ColorB, 255);

	double Radian = PI / 180.0f;

	for (int angle = 0; angle < 360; ++angle) {
		double CurrentRadian = angle * Radian;

		int X = static_cast<int>(Radius * cos(CurrentRadian));
		int Y = static_cast<int>(Radius * sin(CurrentRadian));

		if (bIsFill) 
		{
			SDL_RenderDrawLine(Renderer, CenterX, CenterY, CenterX + X, CenterY + Y);
		}
		else 
		{
			SDL_RenderDrawPoint(Renderer, CenterX + X, CenterY + Y);
		}
	}
}


int SDL_main(int argc, char* argv[])
{
	bool bIsRunning = true;

	// Initialize
	SDL_Init(SDL_INIT_EVERYTHING);			// `SDL_INIT_EVERYTHING`: all of the above subsystems
	// Create Window
	SDL_Window* Window = SDL_CreateWindow("SDL Engine", WINDOWX, WINDOWY, WINDOWW, WINDOWH, SDL_WINDOW_SHOWN);
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


		// Draw Rects
		int RectCounts = 0;
		for (int i = 0; i < RectCounts; ++i)
		{
			Uint8 ColorR = uidR(dre);
			Uint8 ColorG = uidG(dre);
			Uint8 ColorB = uidB(dre);

			int RectX = uidX(dre);
			int RectY = uidY(dre);
			int RectW = uidW(dre);
			int RectH = uidH(dre);

			bool bIsFill = rand() % 2;
			
			DrawRect(Renderer, ColorR, ColorG, ColorB, RectX, RectY, RectW, RectH, bIsFill);
		}
		
		// Draw Circle
		int CircleCounts = 100;
		for (int i = 0; i < CircleCounts; ++i)
		{
			Uint8 ColorR = uidR(dre);
			Uint8 ColorG = uidG(dre);
			Uint8 ColorB = uidB(dre);

			int CenterX = uidX(dre);
			int CenterY = uidY(dre);
			int Radius = uidRadius(dre);

			bool bIsFill = rand() % 2;

			DrawCircle(Renderer, ColorR, ColorG, ColorB, CenterX, CenterY, Radius, bIsFill);
		}

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