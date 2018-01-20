#include "Triangle.h"

#include <string>
#include <iostream>
using namespace std;

Triangle::Triangle(int h, int b, const std::string & gn, const string & d) : Shape(gn, d), base(h), height(b)
{
}

Triangle::~Triangle()
{
}

const Triangle & Triangle::operator=(const Triangle & rhs)
{
	if (this == &rhs) return *this;
	Shape::operator=(rhs);
	height = rhs.height;
	base = rhs.base;
	return *this;
}

int Triangle::getHeight() const
{
	return height;
}

void Triangle::setHeight(int h)
{
	if (h > 0)
		height = h;
	else
		cerr << "Error. Height has to be greater than zero." << endl;
}

int Triangle::getBase() const
{
	return base;
}

std::string Triangle::toString() const
{
	
	string temp{ Shape::toString() };
	temp.append("\nBound. box W:  " + to_string(bBoxWidth()));
	temp.append("\nBound. box H:  " + to_string(bBoxHeight()));
	temp.append("\nScr area:      " + to_string(scrArea()));
	temp.append("\nGeo area:      " + doubleToString(geoArea(), 2));
	temp.append("\nScr perimeter: " + to_string(scrPerimeter()));
	temp.append("\nGeo perimeter: " + doubleToString(geoPerimeter(), 2));
	return temp;
}

double Triangle::geoArea() const
{
	return getHeight() * static_cast<double>(getBase()) / 2;
}

int Triangle::bBoxWidth() const
{
	return getBase();
}

int Triangle::bBoxHeight() const
{
	return getHeight();
}

void Triangle::setBase(int b)
{
	if (b > 0)
		base = b;
	else
		cerr << "Error. Base has to be greater than zero." << endl;
}

std::ostream & operator<<(std::ostream & ostr, const Triangle & rhs)
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