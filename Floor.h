#pragma once
#include "Actor.h"
class AFloor : public AActor
{
public:
	AFloor(const FVector2D InLocation = {0, 0}, int InColorR = 0, int InColorG = 0, int InColorB = 0, const char InMesh = ' ', const int InZOrder = 0);
	virtual ~AFloor();
};

