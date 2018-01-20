#pragma once
#ifndef SHAPE_H
#define SHAPE_H
#include "SlotMachine.h"
using namespace std;
class Shape
{
public:
	Shape() = default;
	Shape(const std::string & gn, const std::string & d);
	explicit Shape(const Shape &) = default;
	 ~Shape() = default;
	virtual const Shape & operator=(const Shape & rhs);
	int getIdNum() const;									//Unique id num of each object
	std::string getGenName() const;							//To get the GenName 
	std::string getDescription() const;						//To get the Description name
	void setDescription(const std::string & vn);			//To set the Description name
	virtual std::string toString() const;					//To display the shape Description
	std::string doubleToString(double d, int p) const;		// takes a double and returns a string. p is for precision
	virtual void scale(int s) = 0;							// To rescale the shape
	virtual double geoArea() const = 0;						//To calculate the Area of shape
	virtual double geoPerimeter() const = 0;				//To calculate the Perimeter of shape
	virtual int scrArea() const = 0;						//To calculate the  scrArea of shape
	virtual int scrPerimeter() const = 0;					//To calculate the scrPerimeter of shape
	virtual int bBoxWidth() const = 0;						//To get the bBoxWidth
	virtual int bBoxHeight() const = 0;						//To get the bBoxHeight
	/* Draws textual image of the shape on a drawing surface*/
	virtual void draw(int c, int r, SlotMachine & canvas, char ch = '*') const = 0;
	
public:
	static int nextId; // keeps track of next id number to be assigned
	 // unique id number
	int idNum;
	std::string genName; // generic name
	std::string description;	// variable descriptive name
};
std::ostream& operator<<(std::ostream& ostr, const Shape& rhs);
#endif 