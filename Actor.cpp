#include "stdafx.h"
#include "Actor.h"
#include "Engine.h"

AActor::AActor(const FVector2D& InLocation, int InColorR, int InColorG, int InColorB, const char InMesh, const int InZOrder)
	: Location(InLocation), ColorR(InColorR), ColorG(InColorG), ColorB(InColorB), Mesh(InMesh), ZOrder(InZOrder)
{
	Image = nullptr;
	Texture = nullptr;
}

AActor::~AActor()
{
	SDL_FreeSurface(Image);
	SDL_DestroyTexture(Texture);
}

void AActor::BeginPlay()
{
}

void AActor::Tick()
{
}

void AActor::Render()
{
	// Console Render
	// GEngine->Render(Location, Mesh);

	// SDL Render Rect
	// GEngine->Render(Location, ColorR, ColorG, ColorB);

	// SDL Render Texture
	GEngine->Render(Location, Texture, TextureLocation, TextureSize);
}

void AActor::SetActorLocation(const FVector2D& NewLocation)
{
	Location = NewLocation;
}

void AActor::AddActorLocalOffset(const FVector2D& Offset)
{
	Location.X += Offset.X;
	Location.Y += Offset.Y;
}

void AActor::Load(std::string FileName, int InColorR, int InColorG, int InColorB, FVector2D InTextureLocation, FVector2D InTextureSize)
{
	Image = SDL_LoadBMP(FileName.c_str());

	Uint32 ColorKey = SDL_MapRGB(Image->format, InColorR, InColorG, InColorB);

	SDL_SetColorKey(Image, SDL_TRUE, ColorKey);

	Texture = SDL_CreateTextureFromSurface(GEngine->GetRenderer(), Image);

	TextureLocation = InTextureLocation;
	TextureSize = InTextureSize;
}