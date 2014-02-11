#include "precomp.h"

using namespace TicTacToeGame;

Choice::Choice(Canvas& canvas, string filename, ChoiceSymbol c) : choiceSymbol(c), Image(canvas, filename)
{
	
}

void Choice::clean()
{
	this->choiceSymbol = ChoiceSymbol::NONE;
}