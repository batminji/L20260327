#include "stdafx.h"
#include "YoudieActor.h"
#include "TextComponent.h"

AYoudieActor::AYoudieActor()
{
	TextComponent->SetText("You Died.");
	Location = { 200, 200 };

	TextComponent->SetZOrder(500);
	TextComponent->bIsVisible = false;	
	TextComponent->SetColor(SDL_Color{ 255, 0, 0 });
}

AYoudieActor::~AYoudieActor()
{
}
