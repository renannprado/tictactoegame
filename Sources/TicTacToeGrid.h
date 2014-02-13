#include "precomp.h"

using namespace std;
using namespace clan;

namespace TicTacToeGame
{
	class TicTacToeGrid
	{
		public:
			TicTacToeGrid(Canvas&);
			~TicTacToeGrid();
			ChoiceSymbol getNextSymbol();
			void doPlay(Canvas&, int, int);	
			void cleanPlay(int, int);
			void resetGrid(Canvas&);
			static const int gridSizeX = 3;
			static const int gridSizeY = 3;
			static const int marginH = 50; //50px
			static const int marginV = 50; //50px
			void draw(Canvas&);
			bool checkVictory();
			void mouseClickUp(const clan::InputEvent&);
		private:
			ChoiceSymbol nextSymbol;
			vector< vector<Choice*> > grid;
			Image gridImage;
			Canvas* canvasPointer;
			static const int distanceBetweenMoves = 50;
			static const int padding = 75;
			static const int distanceBetweenNumbersH = 170;
			static const int distanceBetweenNumbersV = 200;
			static const int barSize = 8; //size (in pixels) that construct the tictactoe grid
		protected:

	};
};