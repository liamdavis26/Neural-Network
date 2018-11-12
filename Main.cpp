#include <iostream>
#include "Neuron.h"

int main()
{
	Neuron nNeuron;
	int iCorrect = 0;
	float fResult = 0.0f;
	
	while(iCorrect != 4)
	{

		fResult = nNeuron.GetInput(0.0f, 0.0f);
		std::cout << fResult << ", ";
		if(fResult == 0.0f)
		{
			iCorrect++;
		}
		fResult = nNeuron.GetInput(0.0f, 1.0f);
		std::cout << fResult << ", ";
		if(fResult == 0.0f)
		{
			iCorrect++;
		}
		fResult = nNeuron.GetInput(1.0f, 0.0f);
		std::cout << fResult << ", ";
		if(fResult == 0.0f)
		{
			iCorrect++;
		}
		fResult = nNeuron.GetInput(1.0f, 1.0f);
		std::cout << fResult << ", " << std::endl;
		if(fResult == 1.0f)
		{
			iCorrect++;
		}

		if(iCorrect < 4)
		{
			iCorrect = 0;
		}

	}

	nNeuron.PrintWeight();
	std::cin.get();

	return 0;
}
