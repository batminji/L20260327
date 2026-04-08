#include "stdafx.h"
#include "AudioComponent.h"

UAudioComponent::UAudioComponent()
	:Music(nullptr)
{
	
}

UAudioComponent::~UAudioComponent()
{
	Stop();
	if (Music)
	{
		Mix_FreeMusic(Music);
		Music = nullptr;
	}
}

void UAudioComponent::BeginPlay()
{
	Play(1);
}

void UAudioComponent::Tick()
{

}

void UAudioComponent::Load(const std::string& InFileName)
{
	FileName = InFileName;

	if (Music)
	{
		Mix_FreeMusic(Music);
		Music = nullptr;
	}

	// ¹è°æ À½¾Ç Load
	Music = Mix_LoadMUS(FileName.c_str());
	if (!Music)
	{
		SDL_Log("Mix_LoadMUS Error: %s\n", Mix_GetError());
	}
}

void UAudioComponent::Play(int InLoop)
{
	if (Music)
	{
		Mix_PlayMusic(Music, InLoop);
	}
}

void UAudioComponent::Stop()
{
	Mix_PauseMusic();
	Mix_HaltMusic();
}

//void UBGMComponent::Pause()
//{
//	Mix_PauseMusic();
//}
//
//void UBGMComponent::Resume()
//{
//	Mix_ResumeMusic();
//}
//
//void UBGMComponent::SetVolume(int InVolume)
//{
//	Mix_VolumeMusic(InVolume);
//}