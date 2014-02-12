#pragma once

// This is the Application class (That is instantiated by the Program Class)
class Basic2D
{
public:
	int start(const std::vector<std::string> &args);

private:
	void on_input_up(const clan::InputEvent &key);
	void on_window_close();

private:
	bool quit;
	TicTacToeGame::TicTacToeGrid* grid;
	clan::Canvas* canvasPointer;
};
