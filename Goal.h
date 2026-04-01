#pragma once
#include "Actor.h"
class AGoal : public AActor
{
public:
	AGoal(const FVector2D& InLocation = { 0, 0 }, int InColorR = 0, int InColorG = 0, int InColorB = 255, const char InMesh = 'G', const int InZOrder = 1);
	virtual ~AGoal();
};

