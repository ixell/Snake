#pragma once
#include "SnakeBlock.h"
#include "Apple.h"

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
	int limit_x{ 1000 }, limit_y{ 1000 };
	Direction next_direction;
	bool coming_block{ false };
protected:
	Snake(Direction direction, SnakeBlock&& head);
public:
	Snake(int x, int y, Direction direction, int lentgh);
	void set_limits(int limit_x, int limit_y);
	void change_direction(Direction direction);

	int get_limit_x();
	int get_limit_y();
	Direction get_direction();
	SnakeBlock* getHead();
	
	bool update();
	void try_eat(Apple& apple);
};
