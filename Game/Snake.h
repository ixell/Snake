#pragma once
#include "SnakeBlock.h"

class Snake {
public:
	enum Direction {
		left,
		right,
		up,
		down,
	};
private:
	Direction direction;
	SnakeBlock head;
	int limit_x, limit_y;
public:
	Snake(Direction direction, SnakeBlock&& head);
	void set_limits(int limit_x, int limit_y);
	int get_limit_x();
	int get_limit_y();
	SnakeBlock* getHead();
	
	bool update();
};
