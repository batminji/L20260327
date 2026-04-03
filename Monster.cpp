#include "stdafx.h"
#include "Monster.h"
#include "Engine.h"
#include "World.h"
#include "ResourceManager.h"
#include "SpriteComponent.h"
#include "CollisionComponent.h"

AMonster::AMonster(const FVector2D& InLocation, const char InMesh)
{
	Location = InLocation;
	Mesh = InMesh;

	Direction = rand() % 4;

	// Sprite Component
	SpriteComponent = CreateDefaultSubObject<USpriteComponent>("Sprite");

	Resource* MyResource = GEngine->GetResourceManager()->LoadTexture("Data/monster.bmp", true, 255, 255, 255);
	SpriteComponent->MyResource = MyResource;

	SpriteComponent->TextureSize = { MyResource->Image->w, MyResource->Image->h };

	SpriteComponent->ZOrder = 20;

	// Collision Component
	CollisionComponent = CreateDefaultSubObject<UCollisionComponent>("Collision");
	CollisionComponent->bIsGenerateHit = true;
	CollisionComponent->bIsGenerateOverlap = true;
}

AMonster::~AMonster()
{
}

void AMonster::Tick()
{
	DeltaTime += GEngine->GetDeltaSeconds();

	FVector2D Offset = { 0, 0 };

	if (DeltaTime > 0.5f)
	{
		Direction = rand() % 4;
		if (Direction == 0)
		{
			Offset.Y--;
		}
		if (Direction == 1)
		{
			Offset.Y++;
		}
		if (Direction == 2)
		{
			Offset.X--;
		}
		if (Direction == 3)
		{
			Offset.X++;
		}
		DeltaTime = 0.0f;
	}

	if (Offset.X != 0 || Offset.Y != 0)
	{
		AddActorLocalOffset(Offset);
		if (!PredictMovement(Location))
		{
			Offset.X = Offset.X * -1;
			Offset.Y = Offset.Y * -1;
			AddActorLocalOffset(Offset);
		}
	}
}

void AMonster::ReceiveHit(AActor* OtherActor)
{

}

void AMonster::ProcessBeginOverlap(AActor* OtherActor)
{
	SDL_Log("Monster Collide Player");
}

bool AMonster::PredictMovement(FVector2D InLocation)
{
	for (auto Other : GEngine->GetWorld()->GetAllActorsOfClass())
	{
		if (Other == this)
		{
			continue;
		}
		for (auto OtherComponent : Other->Components)
		{
			UCollisionComponent* OtherCollision = dynamic_cast<UCollisionComponent*>(OtherComponent);
			if (OtherCollision)
			{
				if (OtherCollision->bIsGenerateOverlap && InLocation.X == Other->GetActorLocation().X && InLocation.Y == Other->GetActorLocation().Y)
				{
					ProcessBeginOverlap(Other);
					return true;
				}
				if (OtherCollision->bIsGenerateHit && InLocation.X == Other->GetActorLocation().X && InLocation.Y == Other->GetActorLocation().Y)
				{
					ReceiveHit(Other);
					return false;
				}
			}
		}
	}
	return true;
}