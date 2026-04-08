#pragma once

class IRenderableComponent
{
public:
	virtual void Render() = 0;

	int ZOrder;

	int bIsVisible : 1;
};

