#include "stdafx.h"
#include "Engine.h"
#include "World.h"

void Sort(int* InData, int Size)
{
	for (int i = 0; i < Size; ++i)
	{
		for (int j = 0; j < Size; ++j)
		{
			if (InData[i] < InData[j])
			{
				int Temp = InData[i];
				InData[i] = InData[j];
				InData[j] = Temp;
			}
		}
	}
}

int main()
{
	/*GEngine->GetWorld()->Load("NewLevel.txt");

	GEngine->Run();

	delete GEngine;*/

	int Data[10] = { 9, 1, 3, 5, 4, 6, 7, 8, 2, 10 };
	
	Sort(Data, 10);

	for (int i = 0; i < 10; ++i)
	{
		std::cout << Data[i] << " ";
	}

	return 0;
}