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
	if (check_collision(x, y)) {
		erase_last();
		return false;
	}
	bool r = (following == nullptr ? true : following->move(this->x, this->y));
	this->x = x;
	this->y = y;
	return r;
}

bool SnakeBlock::grow(int x, int y) {
	if (check_collision(x, y)) {
		erase_last();
		return false;
	}
	addFollowing(this->x, this->y);
	this->x = x;
	this->y = y;
	return true;
}

void SnakeBlock::erase_last() {
	if (following == nullptr) return;
	if (following->getFollowing() == nullptr) {
		delete following;
		following = nullptr;
		return;
	}
	following->erase_last();
}

bool SnakeBlock::check_collision(int x, int y) {
	return this->x == x && this->y == y ? true
		: (following == nullptr ? false : following->check_collision(x, y));
}

void SnakeBlock::addFollowing(int x, int y) {
	following = new SnakeBlock(x, y, following);
}

SnakeBlock::~SnakeBlock() {
	delete following;
}
