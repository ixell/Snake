#include "Apple.h"

Apple::Apple(int x, int y)
	: x(x), y(y) {}

void Apple::set_limits(int limit_x, int limit_y) {
	this->limit_x = limit_x;
	this->limit_y = limit_y;
}

int Apple::get_x() {
	return x;
}

int Apple::get_y() {
	return y;
}

void Apple::move(int x, int y) {
	this->x = (x + limit_x) % limit_x;
	this->y = (y + limit_x) % limit_x;
}

void Apple::move() {
	std::srand(std::time(nullptr));
	x = rand() % limit_x;
	y = rand() % limit_y;
}

