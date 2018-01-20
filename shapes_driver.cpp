#include "Shape.h"
#include "Rectangle.h"
#include "Isosceles.h"
#include "RightTriangle.h"
#include "Rhombus.h"
#include "SlotMachine.h"
#include <time.h>
#include <iostream>
#include <string>
#include <array>
using namespace std;

int main()
{
	Rectangle shape1(10, 3);
	cout << shape1 << endl;
	
	Rhombus ace(16, "Ace of diamond");
	cout << ace.toString() << endl;
	Isosceles iso(17);
	cout << iso << endl;
	RightTriangle rt(10, "Carpenter's square");
	cout << rt << endl;
	cout << shape1.draw() << endl;
	cout<<ace.draw('0') << endl;
	cout << iso.draw('\\', '.') << endl;
	cout << rt.draw('+', '-') << endl;
	ace.draw_on_screen(' ', '0');
	ace.scale(-4);
	ace.write_image_to_stream(cout, '1');
	ace.scale(2);
	ace.write_image_to_stream(cout, 'A', '.');

	cout << endl;
	cout << endl;
	cout << "***************************************************************" << endl;
	cout << "                             Part 2" << endl;
	cout << "***************************************************************" << endl;
	
	SlotMachine slotMachine;
	slotMachine.run();
	return 0;
	
}