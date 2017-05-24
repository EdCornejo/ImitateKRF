#include "Monster.h"

Monster::Monster() { }

Monster::~Monster() { }

bool Monster::init(int type, int road, const std::vector<Vec2> &path) {
	if (!Sprite::init()) {
		return false;
	}

	// this->type_ = type;
	// this->road_ = road;
	// this->path_ = path;
	this->path_ = path;
	this->setPosition(path[0].x * 1.08f, path[0].y * 1.25f);

	return true;
}
