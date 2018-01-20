#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H
#include "Triangle.h"

using namespace std;

class RightTriangle : public Triangle
{
public:

	RightTriangle(){};
	RightTriangle(int h, const std::string & d = "");
	RightTriangle(const RightTriangle &) = default;
	~RightTriangle();
	const RightTriangle & operator=(const RightTriangle & rhs);
	void scale(int n) override;
	double geoPerimeter() const override;
	int scrArea() const override;
	int scrPerimeter() const override;
	/* Draws textual image of the shape on a drawing surface*/
	void draw(int c, int r, SlotMachine & canvas, char ch = '*') const override;
	char draw(char penChar = '*', char fillchar = ' ');
	void draw_on_screen(char penChar = '*', char fillchar = ' ');
	void write_image_to_stream(ostream &out, char penChar = '*', char fillchar = ' ');
};
#endif // !RightTriangle_H