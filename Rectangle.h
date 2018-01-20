#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"
#include <iostream>
class Rectangle : public Shape
{
public:
	Rectangle()=default;
	Rectangle(int h, int w, const std::string & d = "");
	Rectangle(const Rectangle &) = default;
	~Rectangle();
	const Rectangle & operator=(const Rectangle & rhs);
	int getHeight() const;
	void setHeight(int h);
	int getWidth() const;
	void setWidth(int w);
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
	int height;
	int width;
};
std::ostream & operator<<(std::ostream & ostr, const Rectangle & rhs);

#endif 
