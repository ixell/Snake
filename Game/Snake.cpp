#include "Snake.h"
#include "Apple.h"

Snake::Snake(Direction direction, SnakeBlock&& head)
	: direction(direction), head(head), next_direction(direction) {}

Snake::Snake(int x, int y, Direction direction, int length)
	: Snake(direction, SnakeBlock(x, y, nullptr)) {
	SnakeBlock* block = &head;
	int move_x = 0, move_y = 0;
	switch (direction) {
	case left: move_x = -1; break;
	case right: move_x = 1; break;
	case up: move_y = -1; break;
	case down: move_y = 1; break;
	}
	for (; length != 0; --length) {
		x -= move_x;
		y -= move_y;
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
	x = (x + limit_x) % limit_x;
	y = (y + limit_y) % limit_y;
	if (coming_block) {
		coming_block = false;
		return head.grow(x, y);
	}
	return head.move(x, y);
}

void Snake::try_eat(Apple& apple) {
	if (head.get_x() == apple.get_x() && head.get_y() == apple.get_y()) {
		apple.move();
		coming_block = true;
	}
}
