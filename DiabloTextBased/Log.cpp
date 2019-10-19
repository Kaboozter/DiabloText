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
	int tempIn;
	bool tempCorrectInput;
	Write(aQuestion);
	for (int i = 0; i < aNumberOfChoices; i++)
	{
		Write(std::to_string(i + 1) + ". " + someStrings[i]);
	}
	while (!tempCorrectInput)
	{
		try
		{
			std::cin >> tempIn;
			tempCorrectInput = true;
		}
		catch (int tempExeption)
		{
			(tempIn > aNumberOfChoices) || (tempIn < 0);
		}
	}

	system("CLS");

	return (tempIn - 1);
}