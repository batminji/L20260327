#pragma once
#include "SpriteComponent.h"

class USpriteAnimationComponent : public USpriteComponent
{
public:
	USpriteAnimationComponent();
	virtual ~USpriteAnimationComponent();

	virtual void Render() override;

	FVector2D TextureLocation;
};

