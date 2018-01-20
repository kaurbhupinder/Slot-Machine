#include "Rectangle.h"
#include <iostream>
#include <string>
#include <cassert>
#include <ostream>

using namespace std;

Rectangle::Rectangle(int w, int h, const string & d) : Shape("Rectangle", d), height(h), width(w)
{
	assert(height > 0 && width > 0);
}

Rectangle::~Rectangle()
{
}

const Rectangle & Rectangle::operator=(const Rectangle & rhs)
{
	if (this == &rhs) return *this;
	Shape::operator=(rhs);
	height = rhs.height;
	width = rhs.width;
	return *this;
}

int Rectangle::getHeight() const
{
	
	return height;
}

void Rectangle::setHeight(int h)
{
	if (h > 0)
		height = h;
	else
		cerr << "Error. Height has to be greater than zero." << endl;
}

int Rectangle::getWidth() const
{
	return width;
}

void Rectangle::setWidth(int w)
{
	if (w > 0)
		width = w;
	else
		cerr << "Error. Width has to be greater than zero." << endl;
}

string Rectangle::toString() const {
	string temp{ Shape::toString() };
	temp.append("\nBound. box W:  " + to_string(width));
	temp.append("\nBound. box H:  " + to_string(height));
	temp.append("\nScr area:      " + to_string(scrArea()));
	temp.append("\nGeo area:      " + doubleToString(geoArea(), 2));
	temp.append("\nScr perimeter: " + to_string(scrPerimeter()));
	temp.append("\nGeo perimeter: " + doubleToString(geoPerimeter(), 2));
	return temp;
}

void Rectangle::scale(int n)
{
	if (height + n >= 1 && width + n >= 1)
	{
		height += n;
		width += n;
	}
}

double Rectangle::geoArea() const
{
	return getHeight() * getWidth();
}

double Rectangle::geoPerimeter() const
{
	return 2 * (getHeight() + getWidth());
}

int Rectangle::scrArea() const
{
	return getHeight() * getWidth();
}

int Rectangle::scrPerimeter() const
{
	return 2 * (getHeight() + getWidth()) - 4;
}

int Rectangle::bBoxHeight() const
{
	return getHeight();
}

int Rectangle::bBoxWidth() const
{
	return getWidth();
}

void Rectangle::draw(int c, int r, SlotMachine & canvas, char ch) const
{
	
	for (int h = 0; h < height; h++)
	{
		for (int w = 0; w < width; w++)
		{
			canvas.putChar(ch, c + w, r + h);
		}
	}
}



char Rectangle::draw(char penChar, char fillchar)
{
	int w = this->width;
	int h = this->height;
	vector<char> v2(w, penChar);
	vector<vector<char> > grid(h, v2);

	for (size_t r = 0;r < grid.size();++r)
	{
		for (size_t c = 0;c < grid[r].size();++c)
		{
			grid[r][c] = penChar;
			cout << grid[r][c];

		}cout << endl;
	}
	return ' ';
}

std::ostream & operator<<(std::ostream & ostr, const Rectangle & rhs)
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

void Rectangle::draw_on_screen(char penChar, char fillchar)
{
	int w = this->width;
	int h = this->height;
	Rectangle rect(w, h);
	rect.draw(penChar, fillchar);

}

void Rectangle::write_image_to_stream(ostream &out, char penChar, char fillchar)
{
	int w = this->width;
	int h = this->height;
	Rectangle rect(w, h);
	rect.draw(penChar, fillchar);

}