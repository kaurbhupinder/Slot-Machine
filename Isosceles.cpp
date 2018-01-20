#include "Isosceles.h"
#include<math.h>
#include<iostream>
using namespace std;

Isosceles::Isosceles(int h, const string & d) : Triangle(h % 2 == 0 ? h+1:h, (h + 1) / 2, "Isosceles", d)
{

}

Isosceles::~Isosceles()
{
	//cout << "Isosceles dtor" << endl;
}

const Isosceles & Isosceles::operator=(const Isosceles & rhs)
{
	Triangle::operator=(rhs);
	return *this;
}

void Isosceles::scale(int n)
{
	if (getHeight() + n > 0)
	{
		setHeight(getHeight() + n);
		setBase(2 * getHeight() - 1);
	}
}

double Isosceles::geoPerimeter() const
{
	double partial{ 0.25 * getBase() * getBase() }; // 0.25 * b^2
	partial += getHeight() * getHeight();  // 0.25 * b^2 + h^2
	return getBase() + 2 * sqrt(partial);  // b + 2* sqrt(0.25 * b^2 + h^2)
}

int Isosceles::scrArea() const
{
	return getHeight() * getHeight();
}

int Isosceles::scrPerimeter() const
{
	return 4 * (getHeight() - 1);
}

/* draw textual image of the shape on a drawing surface */
void Isosceles::draw(int c, int r, SlotMachine & slotMachine, char ch) const
{
	
	c += getBase() / 2; // fixes position, aligns leftmost char to c, instead of c as center.

	for (int h = 0; h < getHeight(); h++)
	{
		for (int w = 0; w <= h; w++)
		{
			slotMachine.putChar(ch, c + w, r + h); // write to right side
			slotMachine.putChar(ch, c - w, r + h); // write to left side
		}
	}

	
}

char Isosceles::draw(char penChar, char fillchar)
{

	int base = Triangle::getBase();
	vector< vector<char> > grid;
	int height = base / 2;
	for (int r = 0; r < base / 2; r++)
	{
		for (int p = 0; p < height; p++)
			cout << fillchar;

		for (int d = 0; d <= 2 * r; d++)
			cout << penChar;

		for (int p = 0; p < height; p++)
			cout << fillchar;
		height--;

		cout << endl;
	}
	for (int d = 0; d < base; d++)
		cout << penChar;
	cout << endl;

	return ' ';
}

void Isosceles::draw_on_screen(char penChar, char fillchar)
{
	int b = Triangle::getBase();
	Isosceles iso(b);
	iso.draw(penChar, fillchar);

}

void Isosceles::write_image_to_stream(ostream &out, char penChar, char fillchar)
{
	int b = Triangle::getBase();
	Isosceles iso(b);
	iso.draw(penChar, fillchar);

}