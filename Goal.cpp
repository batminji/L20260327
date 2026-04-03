#include "stdafx.h"
#include "Goal.h"
#include "Engine.h"
#include "ResourceManager.h"
#include "SpriteComponent.h"

AGoal::AGoal(const FVector2D& InLocation, const char InMesh)
{
	Location = InLocation;
	Mesh = InMesh;

	// Sprite Component
	SpriteComponent = CreateDefaultSubObject<USpriteComponent>("Sprite");

	Resource* MyResource = GEngine->GetResourceManager()->LoadTexture("Data/Goal.bmp", true, 255, 255, 255);
	SpriteComponent->MyResource = MyResource;

	SpriteComponent->TextureSize = { MyResource->Image->w, MyResource->Image->h };

	SpriteComponent->ZOrder = 10;

}

AGoal::~AGoal()
{
}
