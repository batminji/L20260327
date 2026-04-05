#include "stdafx.h"
#include "MyGM.h"
#include "Engine.h"

AMyGM::AMyGM()
{
}

AMyGM::~AMyGM()
{
}

void AMyGM::GameOver()
{
	static bool bGameOver = false;

	if (!bGameOver)
	{
		bGameOver = true;
	}
}

void AMyGM::GameComplete()
{
	static bool bGameComplete = false;

	if (!bGameComplete)
	{
		bGameComplete = true;
	}
}
