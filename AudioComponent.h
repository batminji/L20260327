#pragma once
#include "Component.h"
class UAudioComponent : public UComponent
{
public:
	UAudioComponent();
	virtual ~UAudioComponent();

	virtual void BeginPlay() override;
	virtual void Tick() override;

	void Load(const std::string& InFileName);

	void Play(int InLoop = -1);
	void Stop();

protected:
	std::string FileName;
	Mix_Music* Music;
};

