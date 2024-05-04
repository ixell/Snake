#include "Snake.h"
#include "Snake.h"
#include "Snake.h"

Snake::Snake(Direction direction, SnakeBlock&& head)
	: direction(direction), head(head), next_direction(direction) {}

Snake::Snake(int x, int y, Direction direction, int length)
	: Snake(direction, SnakeBlock(x, y, nullptr)) {
	SnakeBlock* block = &head;
	for (; length != 0; --length) {
		block->addFollowing(x, y);
		block = block->getFollowing();
	}
}

void Snake::set_limits(int limit_x, int limit_y) {
	this->limit_x = limit_x;
	this->limit_y = limit_y;
}

void Snake::change_direction(Direction direction) {
	switch (this->direction) {
	case up:
		if (direction == down)
			return;
		break;
	case left:
		if (direction == right)
			return;
		break;
	case down:
		if (direction == up)
			return;
		break;
	case right:
		if (direction == left)
			return;
		break;
	}
	this->next_direction = direction;
}

int Snake::get_limit_x() {
	return limit_x;
}

int Snake::get_limit_y() {
	return limit_y;
}

Snake::Direction Snake::get_direction() {
	return direction;
}

SnakeBlock* Snake::getHead() {
	return &head;
}

bool Snake::update() {
	direction = next_direction;
	int x = head.get_x(), y = head.get_y();
	switch (direction) {
	case left: x -= 1; break;
	case right: x += 1; break;
	case up: y -= 1; break;
	case down: y += 1; break;
	}
	return head.move((x + limit_x) % limit_x, (y + limit_y) % limit_y);
}


