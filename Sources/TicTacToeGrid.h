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
		protected:

	};
};