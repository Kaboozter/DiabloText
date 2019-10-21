#include "Log.h"
#include <iostream>
#include <string>

void Log::Write(std::string aMessage)
{
	std::cout << aMessage << std::endl;
}

void Log::DeleteLine(int anAmount)
{
	for (int i = 0; i < anAmount; i++)
	{
		std::cout << "\x1b[A";
		printf("%c[2K",27);
	}
}

int Log::MultipleChoice(std::string aQuestion,std::string* someStrings,int aNumberOfChoices)
{
	int tempIn = 0;
	bool tempCorrectInput = false;
	Write(aQuestion);
	for (int i = 0; i < aNumberOfChoices; i++)
	{
		Write(std::to_string(i + 1) + ". " + someStrings[i]);
	}
	while (!tempCorrectInput)
	{
		std::cin >> tempIn;
		if ((tempIn <= aNumberOfChoices) && (tempIn > 0)) 
		{
			tempCorrectInput = true;
			return (tempIn - 1);
		}
		else
		{
			DeleteLine(1);
		}
	}

	//system("CLS");

}