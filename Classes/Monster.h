#pragma once

#ifndef MONSTER
#define MONSTER

#include "cocos2d.h"

USING_NS_CC;

class Monster: public Node {
public:
	Monster();
	~Monster();

	static Monster* create(int type, int road, int path) {
		Monster *pRet = new(std::nothrow) Monster(); 
		if (pRet && pRet->initMonster(type, road, path)) {
			pRet->autorelease(); 
			return pRet;
		}
		delete pRet; 
		pRet = nullptr; 
		return nullptr;
	};

	bool initMonster(int type, int road, int path);

	// �����������
	CC_SYNTHESIZE(int, type, Type);

	// ��ͬ����  
	CC_SYNTHESIZE(int, road, Road);

	// ��ͬ·��  
	CC_SYNTHESIZE(int, path, Path);
};

#endif
