#pragma once

class UResourceManager
{
public:
	UResourceManager();
	virtual ~UResourceManager();

	Resource* LoadTexture(std::string FileName, bool bIsColorKey = false, Uint8 InColorR = 255, Uint8 InColorG = 255, Uint8 InColorB = 255);

protected:
	std::map<std::string, Resource> Resources;
};

