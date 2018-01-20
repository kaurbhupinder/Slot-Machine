#include "RightTriangle.h"
#include<math.h>
#include<iostream>
using namespace std;

RightTriangle::RightTriangle(int h, const string & d) : Triangle(h, h, "RightTriangle", d)
{
}

RightTriangle::~RightTriangle()
{
}

const RightTriangle & RightTriangle::operator=(const RightTriangle & rhs)
{
	Triangle::operator=(rhs);
	return *this;
}

void RightTriangle::scale(int n)
{
	if (getHeight() + n > 0)
	{
		setHeight(getHeight() + n);
		setBase(getHeight() + n);
	}
}

double RightTriangle::geoPerimeter() const
{
	return (2 + sqrt(2)) * getHeight();  // (2 + sqrt(2)) * h
}

int RightTriangle::scrArea() const
{
	return (getHeight() * (getHeight() + 1)) / 2;
}

int RightTriangle::scrPerimeter() const
{
	return 3 * (getHeight() - 1);
}

void RightTriangle::draw(int c, int r,SlotMachine & canvas, char ch) const
{
	
	for (int h = 0; h < getHeight(); h++)
	{
		for (int w = 0; w <= h; w++)
		{
			canvas.putChar(ch, c + w, r + h); // write to right side of c
		}
	}
}

char RightTriangle::draw(char penChar, char fillChar)
{
	int b = Triangle::getBase();
	vector< vector<char> > grid;

	int rows = b;

	for (int r = 0; r < rows; r++)
	{
		for (int p = 0; p <= r; p++)
			cout << fillChar;

		for (int d = 0; d <rows - 1 - r;d++)
			cout << penChar;

		cout << endl;
	}

	return ' ';
}

void RightTriangle::draw_on_screen(char penChar, char fillchar)
{
	int b = Triangle::getBase();
	RightTriangle rect(b);
	rect.draw(penChar, fillchar);

}

void RightTriangle::write_image_to_stream(ostream &out, char penChar, char fillchar)
{
	int b = Triangle::getBase();
	RightTriangle rect(b);
	rect.draw(penChar, fillchar);

}