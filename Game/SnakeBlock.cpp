#include "SnakeBlock.h"
#include "SnakeBlock.h"

SnakeBlock::SnakeBlock(int x, int y, SnakeBlock* following)
	: x(x), y(y), following(following) {}

int SnakeBlock::get_x() {
	return x;
}

int SnakeBlock::get_y() {
	return y;
}

SnakeBlock* SnakeBlock::getFollowing() {
	return following;
}

bool SnakeBlock::move(int x, int y) {
	if (check_collision(x, y))
		return false;
	this->x = x;
	this->y = y;
	return following == nullptr ? true : following->move(x, y);
}

bool SnakeBlock::check_collision(int x, int y) {
	return this->x == x && this->y == y ? true
		: (following == nullptr ? false : check_collision(x, y));
}

void SnakeBlock::add_following(int x, int y) {
	following = new SnakeBlock(x, y, nullptr);
}

SnakeBlock::~SnakeBlock() {
	delete following;
}
