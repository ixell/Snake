#pragma once
#include <cstdlib>
#include <ctime>

class Apple {
private:
	int x, y;
	int limit_x{ 1000 }, limit_y{ 1000 };
public:
	Apple(int x, int y);
	void set_limits(int limit_x, int limit_y);

	int get_x();
	int get_y();

	void move(int x, int y);
	void move();
};
