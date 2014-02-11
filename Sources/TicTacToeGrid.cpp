#include "precomp.h"

using namespace TicTacToeGame;
using namespace clan;
using namespace std;

TicTacToeGrid::TicTacToeGrid()
{
	//this->canvas = canvas;

	//this->resetGrid();
	
	 // Set up sizes. (HEIGHT x WIDTH)
  /*array2D.resize(HEIGHT);
  for (int i = 0; i < HEIGHT; ++i)
    array2D[i].resize(WIDTH);

  // Put some values in
  array2D[1][2] = 6.0;
  array2D[3][1] = 5.5;*/
}

void TicTacToeGrid::resetGrid(Canvas& canvas)
{
	//next symbol is X, because the game starts with X
	this->nextSymbol = ChoiceSymbol::X;

	this->grid.resize(TicTacToeGrid::gridSizeX);
	
	for (int i = 0; i < TicTacToeGrid::gridSizeX; ++i)
	{
		for (int y = 0; y < TicTacToeGrid::gridSizeY; y++)
			grid[i].push_back(new Choice(canvas, "Resources/X_white.png"));
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

void TicTacToeGrid::doPlay(int x, int y)
{

}

void TicTacToeGrid::draw(Canvas& canvas)
{
	int place = 1;

	for(std::vector<Choice*> row : this->grid) 
	{
		for(Choice* c : row) 
		{
			c->set_color(Color::yellow);
			c->set_scale(0.5f, 0.5f);
			c->draw(canvas, (place++ * c->get_size().height) + marginH, (place * c->get_size().width) + marginV);
		}
	}
}