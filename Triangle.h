#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"

class Triangle : public Shape
{
public:
	Triangle(){};
	Triangle(int h, int b, const std::string & gn, const std::string & d = "");
	Triangle(const Triangle &) = default;
	 ~Triangle();
	const Triangle & operator=(const Triangle & rhs);
	int getHeight() const;
	void setHeight(int h);
	int getBase() const;
	std::string toString() const override;
	virtual void scale(int n) = 0;
	double geoArea() const override;
	virtual double geoPerimeter() const = 0;
	virtual int scrArea() const = 0;
	virtual int scrPerimeter()const = 0;
	int bBoxWidth() const override;
	int bBoxHeight() const override;
	/* Draws textual image of the shape on a drawing surface*/
	virtual void draw(int c, int r, SlotMachine & canvas, char ch = '*') const = 0;

protected:
	void setBase(int b);
private:
	int height;
	int base;
};
std::ostream& operator<<(std::ostream& ostr, const Triangle& rhs);
#endif // !TRIANGLE_H