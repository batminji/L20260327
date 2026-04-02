#include "stdafx.h"
#include "Engine.h"
#include "World.h"

int SDL_main(int argc, char* argv[])
{
	GEngine->GetWorld()->Load("NewLevel.txt");

	GEngine->Run();

	delete GEngine;

	return 0;
}