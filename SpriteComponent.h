#pragma once
#include "Component.h"
#include "RenderableComponent.h"

class USpriteComponent : public UComponent, IRenderableComponent
{
public:
	USpriteComponent();
	virtual ~USpriteComponent();

	virtual void BeginPlay() override;
	virtual void Tick() override;

	virtual void Render() override;
};

