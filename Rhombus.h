#ifndef RHOMBUS_H
#define RHOMBUS_H
#include "Shape.h"
#include <iostream>
class Rhombus : public Shape
{
public:
	Rhombus()=default;
	Rhombus(int diag, const std::string & desc = "");
	Rhombus(const Rhombus &) = default;
	~Rhombus();
	const Rhombus & operator=(const Rhombus & rhs);
	int getDiagonal() const;
	void setDiagonal(int h);
	std::string toString() const override;
	void scale(int n) override;
	double geoArea() const override;
	double geoPerimeter() const override;
	int scrArea() const override;
	int scrPerimeter() const override;
	int bBoxHeight() const override;
	int bBoxWidth() const override;
	/* Draws textual image of the shape on a drawing surface*/
	void draw(int c, int r, SlotMachine & canvas, char ch = '*') const override;
	char draw(char penChar = '*', char fillchar = ' ');
	void draw_on_screen(char penChar = '*', char fillchar = ' ');
	void write_image_to_stream(ostream &out, char penChar = '*', char fillchar = ' ');
private:
	int diagonal;
};
std::ostream & operator<<(std::ostream & ostr, const Rhombus & rhs);
#endif 