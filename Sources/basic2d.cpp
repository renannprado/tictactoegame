/*
**  ClanLib SDK
**  Copyright (c) 1997-2013 The ClanLib Team
**
**  This software is provided 'as-is', without any express or implied
**  warranty.  In no event will the authors be held liable for any damages
**  arising from the use of this software.
**
**  Permission is granted to anyone to use this software for any purpose,
**  including commercial applications, and to alter it and redistribute it
**  freely, subject to the following restrictions:
**
**  1. The origin of this software must not be misrepresented; you must not
**     claim that you wrote the original software. If you use this software
**     in a product, an acknowledgment in the product documentation would be
**     appreciated but is not required.
**  2. Altered source versions must be plainly marked as such, and must not be
**     misrepresented as being the original software.
**  3. This notice may not be removed or altered from any source distribution.
**
**  Note: Some of the libraries ClanLib may link to may have additional
**  requirements or restrictions.
**
**  File Author(s):
**
**    Magnus Norddahl
**    Mark Page
*/

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
	desc.set_title("ClanLib Basic2D Example");
	desc.set_size(clan::Size(640, 480), true);
	desc.set_allow_resize(true);

	clan::DisplayWindow window(desc);
	clan::Canvas canvas(window);

	this->canvasPointer = &canvas;

	// Connect the Window close event
	clan::Slot slot_quit = window.sig_window_close().connect(this, &Basic2D::on_window_close);

	// Connect a keyboard handler to on_key_up()
	clan::Slot slot_input_up = window.get_ic().get_keyboard().sig_key_up().connect(this, &Basic2D::on_input_up);

	// Load a sprite from a png-file
	clan::Image spr_logo(canvas, "Resources/logo.png");
	clan::Font font(canvas, "tahoma", 24);

	Choice choice(canvas, "Resources/logo.png");

	this->grid = new TicTacToeGrid(canvas);
	this->grid->resetGrid(canvas);

	float sin_count = 0.0f;

	clan::GameTime game_time;

	// Run until someone presses escape
	while (!quit)
	{
		game_time.update();

		// Clear the display in a dark blue nuance
		canvas.clear(clan::Colorf(0.0f,0.0f,0.2f));

		this->grid->draw(canvas);

		window.flip(1);

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
	}

}

// The window was closed
void Basic2D::on_window_close()
{
	quit = true;
}