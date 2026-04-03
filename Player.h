#pragma once
#include "Actor.h"

class USpriteAnimationComponent;

class APlayer : public AActor
{
public:
	APlayer(const FVector2D& InLocation = { 0, 0 }, const char InMesh = ' ');
	virtual ~APlayer();

	virtual void Tick() override;

	USpriteAnimationComponent* SpriteAnimationComponent;

protected:
	int Direction = 3;
	float DeltaSeconds = 0.0f;
	int SpriteIndex = 0;
};

