#include "precomp.h"

using namespace std;
using namespace clan;

namespace TicTacToeGame
{
	class TicTacToeGrid
	{
		public:
			TicTacToeGrid();
			~TicTacToeGrid();
			ChoiceSymbol getNextSymbol();
			void doPlay(int x, int y);	
			void resetGrid(Canvas&);
			static const int gridSizeX = 3;
			static const int gridSizeY = 3;
			static const int marginH = 50; //50px
			static const int marginV = 50; //50px
			void draw(Canvas&);
		private:
			ChoiceSymbol nextSymbol;
			vector< vector<Choice*> > grid;
			Canvas* canvas;
		protected:

	};
};