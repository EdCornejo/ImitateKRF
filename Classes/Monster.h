
#ifndef MONSTER
#define MONSTER

#include "cocos2d.h"

USING_NS_CC;

class Monster: public Sprite {
public:
	enum MonsterState {
		WALK_LEFT,
		WALK_RIGHT,
		WALK_UP,
		WALK_DOWN,
		ATTACK_LEFT,
		ATTACK_RIGHT,
		STAND,
		DEAD
	};
public:
	Monster();
	~Monster();

	//static Monster* create(int type, int road, int path) {
	//	Monster *pRet = new(std::nothrow) Monster();
	//	if (pRet && pRet->init(type, road, path)) {
	//		pRet->autorelease();
	//		return pRet;
	//	}
	//	delete pRet;
	//	pRet = nullptr;
	//	return nullptr;
	//}

	virtual bool init(int type, const std::vector<Vec2> &path);

	// ��������
	CC_SYNTHESIZE(int, type_, Type);

	// Ѫ��
	CC_SYNTHESIZE(int, hp_, HP);

	// ���Ѫ��
	CC_SYNTHESIZE(int, max_hp_, MaxHP);

	// ��ǰ״̬
	CC_SYNTHESIZE(MonsterState, state_, State);

	// is dead
	CC_SYNTHESIZE(bool, is_dead_, IsDead);

public:
	virtual void keepGoing() = 0;

	virtual void getDamage(float damage);

	virtual void dying() = 0;

	Sprite *getImage() const {
		return image_;
	}

protected:
	Sprite *image_;
	Sprite *hp_bg_;
	ProgressTimer *hp_prog_;
	std::vector<Vec2> path_;
};

#endif
