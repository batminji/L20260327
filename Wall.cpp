#include "stdafx.h"
#include "Wall.h"
#include "Engine.h"
#include "ResourceManager.h"

AWall::AWall(const FVector2D& InLocation, int InColorR, int InColorG, int InColorB, const char InMesh, const int InZOrder)
{
	Location = InLocation;
	Mesh = InMesh;
	ZOrder = InZOrder;
	ColorR = InColorR;
	ColorG = InColorG;
	ColorB = InColorB;

	MyResource = GEngine->GetResourceManager()->LoadTexture("Data/wall.bmp");

	TextureLocation = { 0, 0 };
	TextureSize = { MyResource->Image->w, MyResource->Image->h };
}

AWall::~AWall()
{
}
