#include "stdafx.h"
#include "Engine.h"
#include "World.h"

int UEngine::KeyCode = 0;

UEngine::UEngine()
{
	Init();
}

UEngine::~UEngine()
{
	Terminate();
}

void UEngine::Init()
{
	bIsRunning = true;
	World = new UWorld();

	InitBuffer();
}

void UEngine::Terminate()
{
	delete World;
	World = nullptr;

	TermBuffer();
}

void UEngine::Run()
{
	while (bIsRunning)
	{
		Input();
		Tick();
		Render();
	}
}

void UEngine::InitBuffer()
{
	ScreenBufferHandle[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	ScreenBufferHandle[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	CONSOLE_CURSOR_INFO ConsoleCursorInfo;
	ConsoleCursorInfo.dwSize = 1;
	ConsoleCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(ScreenBufferHandle[0], &ConsoleCursorInfo);
	SetConsoleCursorInfo(ScreenBufferHandle[1], &ConsoleCursorInfo);
}

void UEngine::Clear()
{
	DWORD DW;
	FillConsoleOutputCharacter(ScreenBufferHandle[ActiveScreenBufferIndex], ' ', 80 * 25, COORD{0, 0}, &DW);
}

void UEngine::Render(const FVector2D& InLocation, const char InMesh)
{
	char MeshString[2] = { 0, };
	MeshString[0] = InMesh;

	SetConsoleCursorPosition(ScreenBufferHandle[ActiveScreenBufferIndex], COORD{(short)(InLocation.X * 2), (short)InLocation.Y});
	WriteFile(ScreenBufferHandle[ActiveScreenBufferIndex], MeshString, 1, NULL, NULL);
}

void UEngine::Flip()
{
	SetConsoleActiveScreenBuffer(ScreenBufferHandle[ActiveScreenBufferIndex]);
	ActiveScreenBufferIndex = !ActiveScreenBufferIndex;
}

void UEngine::TermBuffer()
{
	CloseHandle(ScreenBufferHandle[0]);
	CloseHandle(ScreenBufferHandle[1]);
}

void UEngine::Input()
{
	KeyCode = _getch();
	if (KeyCode == 'f')
	{
		GEngine->GetWorld()->Save("SaveLevel.txt");
	}
	if (KeyCode == 'q')
	{
		bIsRunning = false;
	}
}

void UEngine::Tick()
{
	World->Tick();
}

void UEngine::Render()
{
	World->Render();
}