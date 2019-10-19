#pragma once
#include <iostream>

class Log
{
public:
	void DeleteLine(int anAmount);
	void Write(std::string aMessage);
	int MultipleChoice(std::string aQuestion,std::string* someStrings, int aNumberofChoices);

private:

};

