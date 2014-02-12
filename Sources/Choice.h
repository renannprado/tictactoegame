#include "precomp.h"

using namespace clan;
using namespace std;

namespace TicTacToeGame
{
	class Choice : public Image
	{
		public:
			Choice(Canvas&, string, ChoiceSymbol = ChoiceSymbol::NONE);
			Choice(ChoiceSymbol = ChoiceSymbol::NONE);
			ChoiceSymbol getChoiceSymbol();
			clan::Rect getArea();
		protected:

		private:	
			ChoiceSymbol choiceSymbol;
			void clean();
	};
};