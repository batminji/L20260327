#include "stdafx.h"
#include "Floor.h"

AFloor::AFloor(const FVector2D InLocation, int InColorR, int InColorG, int InColorB, const char InMesh, const int InZOrder)
{
	Location = InLocation;
	Mesh = InMesh;
	ZOrder = InZOrder;
	ColorR = InColorR;
	ColorG = InColorG;
	ColorB = InColorB;

	Load("Data/floor.bmp", 255, 0, 255, {0, 0}, {64, 64});
}

AFloor::~AFloor()
{
}
