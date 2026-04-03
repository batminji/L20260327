#include "stdafx.h"
#include "SpriteAnimationComponent.h"
#include "Engine.h"
#include "Actor.h"

USpriteAnimationComponent::USpriteAnimationComponent()
{
}

USpriteAnimationComponent::~USpriteAnimationComponent()
{
}

void USpriteAnimationComponent::Render()
{
	GEngine->Render(Owner->GetActorLocation(), MyResource->Texture, Owner->GetActorTextureLocation(), TextureSize);
}
