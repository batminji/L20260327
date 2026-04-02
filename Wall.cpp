#include "stdafx.h"
#include "Wall.h"

AWall::AWall(const FVector2D& InLocation, int InColorR, int InColorG, int InColorB, const char InMesh, const int InZOrder)
{
	Location = InLocation;
	Mesh = InMesh;
	ZOrder = InZOrder;
	ColorR = InColorR;
	ColorG = InColorG;
	ColorB = InColorB;

	Load("Data/wall.bmp", 255, 0, 255, {0, 0}, {64, 64});
}

AWall::~AWall()
{
}
