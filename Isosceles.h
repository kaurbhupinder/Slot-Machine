#ifndef ISOSCELES_H
#define ISOSCELES_H
#include "Triangle.h"


class Isosceles : public Triangle
{
public:
	Isosceles(){};
	Isosceles(int h, const std::string & d = "");
	Isosceles(const Isosceles &) = default;
	 ~Isosceles();
	const Isosceles & operator=(const Isosceles & rhs);
	void scale(int n) override;
	double geoPerimeter() const override;
	int scrArea() const override;
	int scrPerimeter() const override;
	/* Draws textual image of the shape on a drawing surface*/
	void draw(int c, int r, SlotMachine & slotMachine, char ch = '*') const override;
	char draw(char penChar = '*', char fillchar = ' ');
	void draw_on_screen(char penChar = '*', char fillchar = ' ');
	void write_image_to_stream(ostream &out, char penChar = '*', char fillchar = ' ');
};
#endif // !Isosceles_H#pragma once
