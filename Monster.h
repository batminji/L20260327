#pragma once
#include "Actor.h"

class USpriteComponent;
class UCollisionComponent;

class AMonster : public AActor
{
public:
	AMonster(const FVector2D& InLocation = { 0, 0 }, const char InMesh = ' ');
	virtual ~AMonster();

	virtual void Tick() override;

	USpriteComponent* SpriteComponent;
	UCollisionComponent* CollisionComponent;

	virtual void ReceiveHit(AActor* OtherActor) override;

	void ProcessBeginOverlap(AActor* OtherActor);

protected:
	int Direction;
	float DeltaTime;

	bool PredictMovement(FVector2D InLocation);
};

