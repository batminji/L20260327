#include "stdafx.h"
#include "Goal.h"

AGoal::AGoal(const FVector2D& InLocation, int InColorR, int InColorG, int InColorB, const char InMesh, const int InZOrder)
{
	Location = InLocation;
	Mesh = InMesh;
	ZOrder = InZOrder;
	ColorR = InColorR;
	ColorG = InColorG;
	ColorB = InColorB;

	Load("Data/goal.bmp", 255, 255, 255, { 0, 0 }, {64, 64});
}

AGoal::~AGoal()
{
}
