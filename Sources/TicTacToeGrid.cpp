#include "precomp.h"

using namespace TicTacToeGame;
using namespace clan;
using namespace std;

TicTacToeGrid::TicTacToeGrid(Canvas& canvas)
{
	this->gridImage = Image(canvas, "Resources/grid_white.png");
}

void TicTacToeGrid::resetGrid(Canvas& canvas)
{
	//next symbol is X, because the game starts with X
	this->nextSymbol = ChoiceSymbol::X;

	this->grid.resize(TicTacToeGrid::gridSizeX);
	
	for (int i = 0; i < TicTacToeGrid::gridSizeX; ++i)
	{
		for (int y = 0; y < TicTacToeGrid::gridSizeY; y++)
		{
			grid[i].push_back(new Choice());
		}
	}
} 

TicTacToeGrid::~TicTacToeGrid()
{

}

void TicTacToeGrid::doPlay(Canvas& canvas, int x, int y)
{
	switch (this->nextSymbol)
	{
		case ChoiceSymbol::X:
		{
			this->grid[x][y] = new Choice(canvas, "Resources/X_white.png", this->nextSymbol);
			this->grid[x][y]->set_color(Color::red);
			this->nextSymbol = ChoiceSymbol::O; //switch to the next ChoiceSymbol
			break;
		}
		case ChoiceSymbol::O:
		{
			this->grid[x][y] = new Choice(canvas, "Resources/O_white.png", this->nextSymbol);
			this->grid[x][y]->set_color(Color::yellow);
			this->nextSymbol = ChoiceSymbol::X; //switch to the next ChoiceSymbol
			break;
		}
	}
}

void TicTacToeGrid::draw(Canvas& canvas)
{
	const int distanceBetweenMoves = 50;
	const int padding = 75;
	const int distanceBetweenNumbersH = 170;
	const int distanceBetweenNumbersV = 200;
	const int barSize = 8; //size (in pixels) that construct the tictactoe grid
	gridImage.draw(canvas, 50, 50);

	int placeNumber = 0;

	for (int x = 0; x < this->grid.size(); x++)
	{
		for (int y = 0; y < this->grid[x].size(); y++)
		{
			placeNumber++;
			if (this->grid[x][y] != nullptr && this->grid[x][y]->getChoiceSymbol() != ChoiceSymbol::NONE)
			{
				Choice* c = this->grid[x][y];
				int posX = x * (distanceBetweenMoves + c->get_width()) + padding;
				int posY = y * (distanceBetweenMoves + c->get_height()) + padding;
				c->draw(canvas, posX, posY);
			}
			else
			{
				clan::Font font(canvas, "tahoma", 50);
				std::ostringstream text;
				text << placeNumber; //converting the placeNumber to a string
				font.draw_text(canvas, (x + 1) * distanceBetweenNumbersH, (y + 1) * distanceBetweenNumbersV, text.str());
			}
		}
	}
}

bool TicTacToeGrid::checkVictory()
{
	if (grid[0][0]->getChoiceSymbol() == grid[1][0]->getChoiceSymbol())
		return true;
	else
		return false;
}

void TicTacToeGrid::mouseClickUp(const clan::InputEvent& mouseEvent)
{
	for (unsigned int i = 0; i < grid.size(); i++)
		for (unsigned int j = 0; j < grid[i].size(); j++)
		{
			Choice* c = grid[i][j];

			Rect r = c->getArea();
			
			//if (mouseEvent.mouse_pos.x >= 
		}	
}