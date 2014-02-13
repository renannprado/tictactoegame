#include "precomp.h"
#include "basic2d.h"

using namespace TicTacToeGame;
using namespace std;
using namespace clan;

// The start of the Application
int Basic2D::start(const std::vector<std::string> &args)
{
	quit = false;

	// Set the window
	clan::DisplayWindowDescription desc;
	desc.set_title("TicTacToeGame");
	desc.set_size(clan::Size(640, 480), true);
	desc.set_allow_resize(true);

	clan::DisplayWindow window(desc);
	clan::Canvas canvas(window);

	this->canvasPointer = &canvas;

	this->grid = new TicTacToeGrid(canvas);
	this->grid->resetGrid(canvas);

	// Connect the Window close event
	clan::Slot slot_quit = window.sig_window_close().connect(this, &Basic2D::on_window_close);

	clan::Slot slot_mouse = window.get_ic().get_mouse(0).sig_key_up().connect(this->grid, &TicTacToeGrid::mouseClickUp);

	// Connect a keyboard handler to on_key_up()
	clan::Slot slot_input_up = window.get_ic().get_keyboard().sig_key_up().connect(this, &Basic2D::on_input_up);

	float sin_count = 0.0f;

	clan::GameTime game_time;

	// Run until someone presses escape
	while (!quit)
	{
		game_time.update();

		// Clear the display in a dark blue nuance
		canvas.clear(clan::Colorf(0.0f,0.0f,0.2f));

		this->grid->draw(canvas);

		string title;



		window.set_title(title);

		window.flip(1);

		bool teste = grid->checkVictory();

		// This call processes user input and other events
		clan::KeepAlive::process(0);
	}

	return 0;
}

// A key was pressed
void Basic2D::on_input_up(const clan::InputEvent &key)
{
	if(key.id == clan::keycode_escape)
	{
		quit = true;
	}

	switch (key.id)
	{
		case keycode_1:
		{
			this->grid->doPlay(*this->canvasPointer, 0,0);
			break;
		}
		case keycode_2:
		{
			this->grid->doPlay(*this->canvasPointer, 0,1);
			break;
		}
		case keycode_3:
		{
			this->grid->doPlay(*this->canvasPointer, 0,2);
			break;
		}
		case keycode_4:
		{
			this->grid->doPlay(*this->canvasPointer, 1,0);
			break;
		}
		case keycode_5:
		{
			this->grid->doPlay(*this->canvasPointer, 1,1);
			break;
		}
		case keycode_6:
		{
			this->grid->doPlay(*this->canvasPointer, 1,2);
			break;
		}
		case keycode_7:
		{
			this->grid->doPlay(*this->canvasPointer, 2,0);
			break;
		}
		case keycode_8:
		{
			this->grid->doPlay(*this->canvasPointer, 2,1);
			break;
		}
		case keycode_9:
		{
			this->grid->doPlay(*this->canvasPointer, 2,2);
			break;
		}
	}
}

// The window was closed
void Basic2D::on_window_close()
{
	quit = true;
}