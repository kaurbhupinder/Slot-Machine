#pragma once
#ifndef SlotMachine_H
#define SlotMachine_H
#include <vector>
#include <array>

using namespace std;

class Shape;
class SlotMachine
{
public:
	SlotMachine() = default;
	explicit SlotMachine(const SlotMachine &) = default;
	~SlotMachine() = default;
	SlotMachine(int c, int r); // default char is blank space
	void run();
	int getRowsM() const;
	int getColsN() const;
	const std::vector< std::vector< char > > & getGrid() const;
	void clear(char ch = ' ');
	void putChar(char ch, int c, int r);
	char getChar(int c, int r) const;
	void decorate();
	bool valid(int c, int r) const;
	vector< std::vector< char > > grid;

private:
	int w;
	int k = 0;
	int input;
	int token = 10;
	bool flag = true;
	int height = 0;
	int iso_height = 0;
	int h1;
	string image[3];
	int w1[3], h[3], s[3], v[2];
	array<Shape*, 3> shape_reel{};
	int colsN; // number of columns
	int rowsM; // number of rows
	static const char BLANK{ ' ' };
	static const int DECOR_COLUMNS{ 2 }; // number of not client area columns
	static const int DECOR_ROWS{ 2 }; // number of not client area rows
	static const int H_ORIGIN{ 1 }; // horizontal origin = side border width
	static const int V_ORIGIN{ 1 }; // vertical origin = upper border height
	void make_shapes(); //	make shape reels point at newly created dynamic shape objects
	void display_shapes(); // displays the shape reels
	void report_status();  // displays outcome, payout, and tokens left 
	void release_shapes(); // frees dynamic objects currently pointed at by the shape reels
};
const std::ostream & operator<<(std::ostream & os, const SlotMachine & rhs);
#endif // !SlotMachine_H