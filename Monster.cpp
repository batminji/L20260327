#include "stdafx.h"
#include "Monster.h"

AMonster::AMonster(const FVector2D& InLocation, int InColorR, int InColorG, int InColorB, const char InMesh, const int InZOrder)
{
	Location = InLocation;
	Mesh = InMesh;
	ZOrder = InZOrder;
	ColorR = InColorR;
	ColorG = InColorG;
	ColorB = InColorB;

	Load("Data/monster.bmp", 255, 255, 255, {0, 0}, {64, 64});
}

AMonster::~AMonster()
{
}
