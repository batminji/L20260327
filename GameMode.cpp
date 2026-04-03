#include "stdafx.h"
#include "GameMode.h"

#include "Engine.h"
#include "World.h"

#include "Player.h"
#include "Goal.h"
#include "Monster.h"

AGameMode::AGameMode()
{
}

AGameMode::~AGameMode()
{
}

void AGameMode::Tick()
{
	__super::Tick();

	APlayer* Player = dynamic_cast<APlayer*>(GEngine->GetWorld()->GetActorOfClass<APlayer>());
	AMonster* Monster = dynamic_cast<AMonster*>(GEngine->GetWorld()->GetActorOfClass<AMonster>());
	AGoal* Goal = dynamic_cast<AGoal*>(GEngine->GetWorld()->GetActorOfClass<AGoal>());

	if (Player && Monster)
	{
		if (Player->GetActorLocation().X == Monster->GetActorLocation().X 
			&& Player->GetActorLocation().Y == Monster->GetActorLocation().Y)
		{
			SDL_Log("You Die");
			GEngine->Stop();
		}
	}

	if (Player && Goal)
	{
		if (Player->GetActorLocation().X == Goal->GetActorLocation().X
			&& Player->GetActorLocation().Y == Goal->GetActorLocation().Y)
		{
			SDL_Log("You Win");
			GEngine->Stop();
		}
	}
}