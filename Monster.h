#pragma once
#include "Actor.h"
class AMonster : public AActor
{
public:
	AMonster(const FVector2D& InLocation = {0, 0}, int InColorR = 255, int InColorG = 0, int InColorB = 0, const char InMesh = 'M', const int InZOrder = 2);
	virtual ~AMonster();
};

