#include "precomp.h"

using namespace TicTacToeGame;

std::string TicTacToeGame::choiceSymbolToString(ChoiceSymbol c)
{
	switch(c)
	{
		case ChoiceSymbol::X:
			return "X";
		case ChoiceSymbol::O:
			return "O";
		case ChoiceSymbol::NONE:
			return "NONE";
	}

	return "FUDEU";
}