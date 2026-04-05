#include "stdafx.h"
#include "TextComponent.h"
#include "Engine.h"
#include "Actor.h"

UTextComponent::UTextComponent()
	: Text("Hello World"), Color({ 255, 255, 255, 255 }), Offset({0, 0})
{
	MyResource = new Resource();
	MyResource->Image = nullptr;
	MyResource->Texture = nullptr;
}

UTextComponent::~UTextComponent()
{
	if (MyResource)
	{
		if (MyResource->Texture)
		{
			SDL_DestroyTexture(MyResource->Texture);
		}
		if (MyResource->Image)
		{
			SDL_FreeSurface(MyResource->Image);
		}
		delete MyResource;
		MyResource = nullptr;
	}
	if (MyFont)
	{
		TTF_CloseFont(MyFont);
	}
}

void UTextComponent::BeginPlay()
{
}

void UTextComponent::Tick()
{
}

void UTextComponent::Render()
{
	if (MyResource && MyResource->Texture)
	{
		FVector2D Temp = { Owner->GetActorLocation().X + Offset.X, Owner->GetActorLocation().Y + Offset.Y };
		GEngine->Render(Temp, MyResource->Texture, TextureSize.X, TextureSize.Y);
	}
}

void UTextComponent::SetFont(const std::string& InFontPath, int InFontSize)
{
	if (MyFont)
	{
		TTF_CloseFont(MyFont);
	}
	MyFont = TTF_OpenFont(InFontPath.c_str(), InFontSize);
}

void UTextComponent::SetText(const std::string& InText)
{
	Text = InText;
	UpdateTextResource();
}

void UTextComponent::UpdateTextResource()
{
	if (!MyFont || Text.empty())
	{
		return;
	}

	if (MyResource)
	{
		if (MyResource->Texture)
		{
			SDL_DestroyTexture(MyResource->Texture);
		}
		if (MyResource->Image)
		{
			SDL_FreeSurface(MyResource->Image);
		}
	}

	MyResource->Image = TTF_RenderText_Solid(MyFont, Text.c_str(), Color);

	if (MyResource->Image)
	{
		MyResource->Texture = SDL_CreateTextureFromSurface(GEngine->GetRenderer(), MyResource->Image);

		TextureSize.X = MyResource->Image->w;
		TextureSize.Y = MyResource->Image->h;
	}
}
