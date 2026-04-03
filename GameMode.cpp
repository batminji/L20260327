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

	std::vector<AActor*> TempPlayers = GEngine->GetWorld()->GetActorsOfClass<APlayer>();
	std::vector<AActor*> TempMonsters = GEngine->GetWorld()->GetActorsOfClass<AMonster>();
	std::vector<AActor*> TempGoals = GEngine->GetWorld()->GetActorsOfClass<AGoal>();

	std::vector<APlayer*> Players{};
	std::vector<AMonster*> Monsters{};
	std::vector<AGoal*> Goals{};

	for (auto P : TempPlayers)
	{
		APlayer* Player = dynamic_cast<APlayer*>(P);
		if (Player)
		{
			Players.emplace_back(Player);
		}
	}

	for (auto M : TempMonsters)
	{
		AMonster* Monster = dynamic_cast<AMonster*>(M);
		if (Monster)
		{
			Monsters.emplace_back(Monster);
		}
	}

	for (auto G : TempGoals)
	{
		AGoal* Goal = dynamic_cast<AGoal*>(G);
		if (Goal)
		{
			Goals.emplace_back(Goal);
		}
	}

	for (auto P : Players)
	{
		for (auto M : Monsters)
		{
			if (M->GetActorLocation().X == P->GetActorLocation().X
				&& M->GetActorLocation().Y == P->GetActorLocation().Y)
			{
				SDL_Log("You Die");
				GEngine->Stop();

				return;
			}
		}
	}

	for (auto P : Players)
	{
		for (auto G : Goals)
		{
			if (G->GetActorLocation().X == P->GetActorLocation().X
				&& G->GetActorLocation().Y == P->GetActorLocation().Y)
			{
				SDL_Log("You Win");
				GEngine->Stop();

				return;
			}
		}
	}
}