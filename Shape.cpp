#include "Shape.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int Shape::nextId = 1;

Shape::Shape(const string & gn, const string & d) : genName(gn), description(d), idNum(nextId++)
{
	
	if (d.empty())
		description = "Generic " + genName;
}

const Shape & Shape::operator=(const Shape & rhs)
{
	if (this == &rhs) return *this;
	genName = rhs.genName;
	description = rhs.description;
	return *this;
}

int Shape::getIdNum() const
{
	return idNum;
}

string Shape::getGenName() const
{
	return genName;
}

string Shape::getDescription() const
{
	return description;
}

void Shape::setDescription(const string & d)
{
	description = d;
}

std::string Shape::toString() const
{
	
	string temp{ "Shape Information\n-----------------" };
	temp += "\nStatic Type:   ";
	temp.append(typeid(this).name());
	temp += "\nDynamic Type:  ";
	temp.append(typeid(*this).name());
	temp += "\nGeneric name:  " + getGenName();
	temp += "\nDescription:   " + getDescription();
	temp += "\nid:            ";
	temp.append(to_string(getIdNum()));
	return temp;
}

string Shape::doubleToString(double d, int p) const
{
	ostringstream s;
	s.precision(p);
	s << fixed << d;
	string temp{ s.str() };
	return temp;
}

ostream & operator<<(ostream & ostr, const Shape & rhs)
{
	
	const Shape * rhsPtr = &rhs;
	ostr << "Shape Information"
		<< "\n-----------------"
		<< "\nStatic Type:   " << typeid(rhsPtr).name()
		<< "\nDynamic Type:  " << typeid(*rhsPtr).name()
		<< "\nGeneric name:  " + rhs.getGenName()
		<< "\nDescription:   " + rhs.getDescription()
		<< "\nid:            " + to_string(rhs.getIdNum());
	return ostr;
}