#pragma once

class SnakeBlock {
private:
	int x, y;
	SnakeBlock* following;
public:
	SnakeBlock(int x, int y, SnakeBlock* following);
	~SnakeBlock();

	int get_x();
	int get_y();
	SnakeBlock* getFollowing();
	
	bool move(int x, int y);
	bool check_collision(int x, int y);
	void addFollowing(int x, int y);
};