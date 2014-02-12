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
			//grid[i].push_back(new Choice(canvas, "Resources/X_white.png"));
			grid[i].push_back(nullptr);
		}
	}

	/*for (int i = 0; i < TicTacToeGrid::gridSizeX; ++i)
	{
		this->grid[i].resize(TicTacToeGrid::gridSizeY);
		this->grid[i].push_back(new Choice(canvas, "Resources/logo.png"));
	}*/

	/*for (int x = 0; x < grid.size(); x++)
		for (int y = 0; y < grid[x].size(); y++)
%			grid[x].push_back(new Choice(canvas, "Resources/logo.png"));*/
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
			this->nextSymbol = ChoiceSymbol::O; //switch to the next ChoiceSymbol
			break;
		}
		case ChoiceSymbol::O:
		{
			this->grid[x][y] = new Choice(canvas, "Resources/O_white.png", this->nextSymbol);
			this->nextSymbol = ChoiceSymbol::X; //switch to the next ChoiceSymbol
			break;
		}
	}
}

void TicTacToeGrid::draw(Canvas& canvas)
{
	const int distanceBetween = 50;
	const int barSize = 8; //size (in pixels) that construct the tictactoe grid
	gridImage.draw(canvas, distanceBetween, distanceBetween);

	for (int x = 0; x < this->grid.size(); x++)
	{
		for (int y = 0; y < this->grid[x].size(); y++)
		{
			if (this->grid[x][y] != nullptr)
			{
				this->grid[x][y]->set_color(Color::yellow);
				this->grid[x][y]->set_scale(0.7f, 0.7f);
				this->grid[x][y]->draw(canvas, x * distanceBetween + barSize, y * distanceBetween + barSize);
			}
		}
	}

		/*for(Choice* c : row) 
		{
			c->set_color(Color::yellow);
			c->set_scale(0.7f, 0.7f);
			c->draw(canvas, (place++ * c->get_size().height) + marginH, (place * c->get_size().width) + marginV);
		}*/
}