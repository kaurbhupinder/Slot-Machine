#include "Rhombus.h"
#include <iostream>
#include <string>
#include <cassert>
#include<math.h>

using namespace std;

Rhombus::Rhombus(int diag, const string & desc) : Shape("Rhombus", desc), diagonal(diag)
{
	
	if (diagonal % 2 == 0)
		++diagonal;
	
	assert(diagonal > 0);
}

Rhombus::~Rhombus()
{
}

const Rhombus & Rhombus::operator=(const Rhombus & rhs)
{
	if (this == &rhs) return *this;
	Shape::operator=(rhs);
	diagonal = rhs.diagonal;
	return *this;
}

int Rhombus::getDiagonal() const
{
	return diagonal;
}

void Rhombus::setDiagonal(int d)
{
	if (d % 2 == 0)
		++d;
	if (d > 0)
		diagonal = d;
	else
		cerr << "Error. Diagonal has to be and odd integer greater than zero." << endl;
}

string Rhombus::toString() const {
	//cout << "Rhombus::toString()" << endl;
	string temp{ Shape::toString() };
	temp.append("\nBound. box W:  " + to_string(bBoxWidth()));
	temp.append("\nBound. box H:  " + to_string(bBoxHeight()));
	temp.append("\nScr area:      " + to_string(scrArea()));
	temp.append("\nGeo area:      " + doubleToString(geoArea(), 2));
	temp.append("\nScr perimeter: " + to_string(scrPerimeter()));
	temp.append("\nGeo perimeter: " + doubleToString(geoPerimeter(), 2));
	return temp;
}

void Rhombus::scale(int n)
{
	if (n != 0)
	{
		if (n % 2 == 0) // n is even
		{
			if (getDiagonal() + n > 0)
				diagonal += n;
		}
		else // n is odd, find next even value for n
		{
			if (n > 0) // if positive increase n by one
			{
				++n;
				if (getDiagonal() + n > 0)
					diagonal += n;
			}
			else // if negative reduce n by one
			{
				--n;
				if (getDiagonal() + n > 0)
					diagonal += n;
			}
		}
	}
	
}

double Rhombus::geoArea() const
{
	return getDiagonal() * static_cast<double>(getDiagonal()) / 2;
}

double Rhombus::geoPerimeter() const
{
	return 2 * sqrt(2) * getDiagonal();
}

int Rhombus::scrArea() const
{
	int n{ getDiagonal() / 2 }; // n = floor(diagonal / 2), diagonal positive
	return 2 * n * (n + 1) + 1;
}

int Rhombus::scrPerimeter() const
{
	return 2 * (getDiagonal() - 1);
}

int Rhombus::bBoxHeight() const
{
	return getDiagonal();
}

int Rhombus::bBoxWidth() const
{
	return getDiagonal();
}

void Rhombus::draw(int c, int r, SlotMachine & canvas, char ch) const
{
	
	c += diagonal / 2; // fixes position, aligns leftmost char to c, instead of c as center.

	for (int h = 0; h < diagonal; h++) // for each row from 0 to diagonal - 1
	{
		if (h <= diagonal / 2) // upper half increases
		{
			for (int w = 0; w <= h; w++)
			{
				canvas.putChar(ch, c + w, r + h); // write to right side
				canvas.putChar(ch, c - w, r + h); // write to left side
			}
		}
		if (h > diagonal / 2) // lower half decreases
		{
			for (int w = diagonal - 1 - h; w >= 0; w--)
			{
				canvas.putChar(ch, c + w, r + h);
				canvas.putChar(ch, c - w, r + h);
			}
		}
	}
	
}



std::ostream & operator<<(std::ostream & ostr, const Rhombus & rhs)
{
	const Shape * shapePtr = &rhs;
	ostr << *shapePtr;
	ostr.precision(2);
	ostr << "\nBound. box W:  " << rhs.bBoxWidth()
		<< "\nBound. box H:  " << rhs.bBoxHeight()
		<< "\nScr area:      " << rhs.scrArea()
		<< "\nGeo area:      " << fixed << rhs.geoArea()
		<< "\nScr Perimeter: " << rhs.scrPerimeter()
		<< "\nGeo Perimeter: " << rhs.geoPerimeter();
	return ostr;
}

char Rhombus::draw(char penChar, char fillchar)
{
	int w = this->diagonal;
	int h = this->diagonal;

	vector<char> v2(w, penChar);
	vector<vector<char> > grid(h, v2);

	int rows = w;
	int a = rows / 2;
	int b = a;
	int c = rows - 1;
	for (int r = 0; r < rows / 2; r++)
	{
		for (int p = 0; p < b; p++)
			cout << fillchar;

		if (r < a) {
			for (int d = 0; d <= 2 * r; d++)
				cout << penChar;

			for (int d = a; d < c; d++)
				cout << fillchar;
		}
		b--;
		c--;
		cout << endl;
	}
	for (int d = 0; d < rows; d++)
		cout << penChar;
	cout << endl;

	for (int r = 0; r < rows / 2; r++)
	{
		for (int p = 0; p <= r; p++)
			cout << fillchar;

		for (int d = rows - 2; d > r + r; d--)
			cout << penChar;

		for (int p = 0; p <= r; p++)
			cout << fillchar;

		cout << endl;
	}

	return ' ';
}

void Rhombus::draw_on_screen(char penChar, char fillchar)
{
	int w = this->diagonal;
	int h = this->diagonal;
	Rhombus rb(w);
	rb.draw(penChar, fillchar);

}

void Rhombus::write_image_to_stream(ostream &out, char penChar, char fillchar)
{
	int w = this->diagonal;
	int h = this->diagonal;
	Rhombus rb(w);
	rb.draw(penChar, fillchar);

}