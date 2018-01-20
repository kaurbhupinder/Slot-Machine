#include "SlotMachine.h"
#include "Rectangle.h"
#include "Isosceles.h"
#include "RightTriangle.h"
#include "Rhombus.h"

#include<array>
#include <iostream>
#include <cassert>
#include<time.h>
#include<array>
#include<string>
#include<algorithm>
using namespace std;


SlotMachine::SlotMachine(int c, int r) : colsN(c), rowsM(r), grid(r, vector <char>(c, BLANK))
{


	assert(c > 0 && r > 0);
	decorate();
}


int SlotMachine::getRowsM() const
{
	return rowsM;
}

int SlotMachine::getColsN() const
{
	return colsN;
}

const std::vector<std::vector<char>>& SlotMachine::getGrid() const
{
	return grid;
}


const ostream & operator<<(ostream & os, const SlotMachine & rhs)
{
	for (auto rowIt = rhs.getGrid().begin(), rowEnd = rhs.getGrid().end(); rowIt != rowEnd; ++rowIt)
	{
		for (auto colIt = rowIt->begin(), colEnd = rowIt->end(); colIt != colEnd; ++colIt)
		{
			os << *colIt;
		}
		os << endl;

	}
	return os;
}
void SlotMachine::clear(char ch)
{
	auto rowIt = grid.begin();
	rowIt += V_ORIGIN; // skip border row

	auto rowEnd = grid.end();
	rowEnd -= V_ORIGIN; // set end pointer to border row (not beyond it)
	for (; rowIt != rowEnd; ++rowIt)
	{
		auto colIt = rowIt->begin();
		colIt += H_ORIGIN; // skip border column
		auto colEnd = rowIt->end();
		colEnd -= H_ORIGIN; // set end pointer to border column (not beyond it)
		for (; colIt != colEnd; ++colIt)
		{
			*colIt = ch; // write char
		}
	}
}

void SlotMachine::putChar(char ch, int c, int r)
{
	if (valid(c, r))
		grid[r + V_ORIGIN][c + H_ORIGIN] = ch;
}

char SlotMachine::getChar(int c, int r) const
{
	if (valid(c, r))
		return grid[r + V_ORIGIN][c + H_ORIGIN];
	else
		cerr << "Error. Invalid column or row" << endl;
	return '\0';
}

void SlotMachine::decorate()
{
	const char CORNER{ '+' };
	const char HLINE{ '-' };
	const char VLINE{ '|' };

	for (int i = 0; i < getRowsM(); i++)
	{
		for (int j = 0; j < getColsN(); j++)
		{
			if (i == 0 && j == 0 || i == 0 && j == getColsN() - 1 || // upper corners or
				i == getRowsM() - 1 && j == 0 || i == getRowsM() - 1 && j == getColsN() - 1) // lower corners
			{
				grid[i][j] = CORNER;
			}
			else if (i == 0 || i == getRowsM() - 1) // sides
			{
				grid[i][j] = HLINE;
			}
			else if (j == 0 || j == getColsN() - 1) // top and bottom
			{
				grid[i][j] = VLINE;
			}

		}
	}


}

bool SlotMachine::valid(int c, int r) const
{
	if (c >= 0 && r >= 0) // not negative
		return c < getColsN() - DECOR_COLUMNS && r < getRowsM() - DECOR_ROWS; // in column range and in row range.
	else
		return false;
}
void SlotMachine::make_shapes()
{
	srand(time(NULL));
	for (int i = 0; i < 3; i++)
	{
		s[i] = rand() % 4;
		w1[i] = rand() % 25 + 1;
		h[i] = w1[i];
	}
	w = w1[0] + w1[1] + w1[2] + 12;
	v[0] = w1[0] + 3;
	v[1] = w1[0] + w1[1] + 3 + 3;
	h1 = rand() % 10 + 1;

	for (int j = 0; j < 3; j++)
	{
		if (s[j] == 1)
		{
			h[j] = w1[j] / 2;

		}
		else if (s[j] == 3)
		{
			h[j] = h1;
		}
	}

}


void SlotMachine::display_shapes()
{
	int max1 = *max_element(h, h + 4);

	SlotMachine slotMachine(w, max1 + 4);


	for (int i = 0; i < 3; i++)
	{
		if (s[i] == 0)
		{
			image[i] = "Rhombus";
			Rhombus rb(w1[i]);
			shape_reel[k] = &rb;
			if (i == 0)

				shape_reel[k]->draw(1, 1, slotMachine);

			else if (i == 1)

				shape_reel[k]->draw(w1[0] + 4, 1, slotMachine);

			else if (i == 2)

				shape_reel[k]->draw(w1[0] + w1[1] + 8, 1, slotMachine);

		}
		else if (s[i] == 1)
		{
			image[i] = "Isosceles";
			Isosceles iso(w1[i]);
			shape_reel[k] = &iso;

			if (i == 0)

				shape_reel[k]->draw(1, 1, slotMachine);

			else if (i == 1)

				shape_reel[k]->draw(w1[0] + 4, 1, slotMachine);

			else if (i == 2)

				shape_reel[k]->draw(w1[0] + w1[1] + 8, 1, slotMachine);


		}
		else if (s[i] == 2)
		{
			image[i] = "Right Triangle";
			RightTriangle rt(w1[i]);
			shape_reel[k] = &rt;

			if (i == 0)

				shape_reel[k]->draw(1, 1, slotMachine);

			else if (i == 1)

				shape_reel[k]->draw(w1[0] + 4, 1, slotMachine);

			else if (i == 2)

				shape_reel[k]->draw(w1[0] + w1[1] + 8, 1, slotMachine);
		}
		else if (s[i] == 3)
		{
			image[i] = "Rectangle";
			Rectangle rect(w1[i], h1);
			shape_reel[k] = &rect;

			if (i == 0)

				shape_reel[k]->draw(1, 1, slotMachine);

			else if (i == 1)

				shape_reel[k]->draw(w1[0] + 4, 1, slotMachine);

			else if (i == 2)

				shape_reel[k]->draw(w1[0] + w1[1] + 8, 1, slotMachine);

		}
		for (int z = 1; z < slotMachine.getRowsM() - 1; z++)
		{
			slotMachine.grid[z][v[0]] = '|';
			slotMachine.grid[z][v[1]] = '|';
		}

	}

	cout << slotMachine;
	cout << endl;


}

void SlotMachine::report_status()
{
	cout << "(" << image[0] << " , " << w1[0] << " , " << h[0] << ")  " << "(" << image[1] << " , " << w1[1] << " , " << h[1] << ")   " << "(" << image[2] << " , " << w1[2] << " , " << h[2] << ")" << endl;
	cout << endl;

	if (image[0] == image[1])
	{
		if (image[1] == image[2])
		{
			if (w1[0] == w1[1] && w1[1] == w1[2] && w1[0] == w1[2] && h[0] == h[1] && h[1] == h[2] && h[0] == h[2])
			{
				cout << "You won 3 times your bet" << endl;
				token = input * 3 + token;
			}
			else
			{
				cout << "You won 2 times your bet" << endl;
				token = input * 2 + token;
			}
		}
		else
		{
			cout << "Neither won nor lost anything" << endl;
		}

	}

	else if (image[1] != image[2] && image[0] != image[2])
	{
		cout << "You lose your bet" << endl;
		token = token - input;

	}
	else
	{
		cout << "Neither won nor lost anything" << endl;
	}
	cout << "You now have " << token << " tokens!" << endl;
	cout << endl;
	if (token == 0)
	{
		cout << "Oops you ran out of tokens...exiting" << endl;
		cout << endl;
		exit(0);
	}
}
void SlotMachine::release_shapes()
{
	for (int i = 0; i < 3; i++)
	{
		delete shape_reel[i];
	}
}
void SlotMachine::run()
{
	cout << "Welcome to this 3-Reel Slot Machine Game!" << endl;
	cout << "Each reel will randomly display one of four shapes , each in 25 sizes ." << endl;
	cout << "To win 3 times your bet you need 3 similar shapes of the same size ." << endl;
	cout << "To win 2 times your bet you need 3 similar shapes ." << endl;
	cout << "To win or lose nothing you need 2 similar shapes ." << endl;
	cout << "Otherwise , you lose your bet ." << endl;
	cout << "You start with 10 free tokens !" << endl;
	cout << endl;
	cout << endl;


	while (true)
	{
		cout << "How much would you like to bet ( enter 0 to quit )? ";
		cin >> input;
		if (input < 0 || input >token)
		{
			cout << endl;
			cout << "Please enter value greater than 0 and less than your tokens!!!" << endl;
			cout << endl;
		}
		else if (input == 0)
		{
			cout << "Exiting the game...." << endl;
			cout << endl;
			exit(0);
		}
		else
			make_shapes();
		display_shapes();
		report_status();

	}
	release_shapes();

}
