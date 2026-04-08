#include "stdafx.h"
#include "MyGM.h"
#include "Engine.h"
#include "World.h"
#include "Component.h"
#include "YoudieActor.h"
#include "RenderableComponent.h"

AMyGM::AMyGM()
{
}

AMyGM::~AMyGM()
{
}

void AMyGM::GameOver()
{
	static bool bGameOver = false;

	if (!bGameOver)
	{
		AYoudieActor* TextActor = dynamic_cast<AYoudieActor*>(GEngine->GetWorld()->GetActorOfClass<AYoudieActor>());
		if (TextActor)
		{
			IRenderableComponent* RenderComponent = dynamic_cast<IRenderableComponent*>(TextActor->Components[0]);
			if (RenderComponent)
			{
				RenderComponent->bIsVisible = true;
			}
		}
		bGameOver = true;
	}
}

void AMyGM::GameComplete()
{
	static bool bGameComplete = false;

	if (!bGameComplete)
	{
		bGameComplete = true;
	}
}
