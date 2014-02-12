#include "precomp.h"

using namespace TicTacToeGame;

Choice::Choice(Canvas& canvas, string filename, ChoiceSymbol c) : choiceSymbol(c), Image(canvas, filename)
{
	
}

Choice::Choice(ChoiceSymbol c) : choiceSymbol(c)
{

}

void Choice::clean()
{
	this->choiceSymbol = ChoiceSymbol::NONE;
}

ChoiceSymbol Choice::getChoiceSymbol()
{
	return this->choiceSymbol;
}